/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2022 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 ************************************************************************
 ************************************************************************/

#include "patternmatcher/automaton.hh"
#include "patternmatcher/is_box_pattern_op.hh"

#include "compiler/block_diagram/boxes/boxes.hh"
#include "compiler/block_diagram/boxes/ppbox.hh"
#include "global.hh"
#include "compiler/block_diagram/eval/eval.hh"
#include "environment.hh"

namespace PM {

  /* Check for cons (nonempty list) nodes. */
  static inline bool isCons(Tree x, Tree& h, Tree& t)
  {
      if (isList(x)) {
          h = hd(x);
          t = tl(x);
          return true;
      } else
          return false;
  }

  /* Take the rules of a BoxCase expression and return a pointer to the
     corresponding TA automaton (interface operation). */

  Automaton* Automaton::make_pattern_matcher(Tree R)
  /* Tree R encodes the rules of a case box expressions as a Tree object, as
     follows:

     Rules	::= cons Rule (cons Rule ... nil)
     Rule		::= cons Lhs Rhs
     Lhs		::= cons Pattern (cons Pattern ... nil)
     Pattern	::= Tree (parameter pattern)
     Rhs		::= Tree

     NOTE: The lists of rules and patterns are actually delivered in reverse
     order by the parser, so we have to reverse them on the fly. */
  {
      Automaton*            A = new Automaton;
      int                   n = len(R), r = n;
      State*                start = new State;
      Tree                  rule, rest;
      vector<Tree>          rules(n, (Tree)NULL);
      vector<vector<Tree> > testpats(n);
      while (isCons(R, rule, rest)) {
          rules[--r] = rule;
          R          = rest;
      }
      for (r = 0; r < n; r++) {
          Tree lhs, rhs;
          if (isCons(rules[r], lhs, rhs)) {
              Tree         pat;
              int          m = len(lhs), i = m;
              vector<Tree> pats(len(lhs), (Tree)NULL);
              State*      state0 = new State, *state = state0;
              A->rhs.push_back(rhs);
              while (isCons(lhs, pat, rest)) {
                  pats[--i] = pat;
                  lhs       = rest;
              }
              testpats[r] = pats;
              for (i = 0; i < m; i++) {
                  Path p;
                  state = State::make_state(state, r, pats[i], p);
              }
              Rule new_rule(r, NULL);
              state->rules.push_back(new_rule);
              State::merge_state(start, state0);
          }
      }
      A->build(start);
      /* Check for shadowed rules. Note that because of potential nonlinearities
         it is *not* enough to just check the rule lists of final states and
         determine whether they have multiple matched rules. */
      for (r = 0; r < n; r++) {
          int          s = 0, m = (int)testpats[r].size();
          Tree         C;
          vector<Tree> E(n, global::config().nil);
          /* try to match the lhs of rule #r */
          for (int i = 0; i < m; i++) {
              s = apply_pattern_matcher(A, s, testpats[r][i], C, E);
              if (s < 0) break;
          }
          if (A->final(s)) {
              list<Rule>::const_iterator ru;
              for (ru = A->rules(s).begin(); ru != A->rules(s).end(); ru++)
                  if (!isBoxError(E[ru->r])) {
                      if (ru->r < r) {
                          /* Lhs of rule #r matched a higher-priority rule, so rule #r may
                             be shadowed. */
                          Tree lhs1, rhs1, lhs2, rhs2;
                          if (isCons(rules[ru->r], lhs1, rhs1) && isCons(rules[r], lhs2, rhs2)) {
                              cerr << "WARNING : shadowed pattern-matching rule: " << boxpp(reverse(lhs2)) << " => "
                                   << boxpp(rhs2) << ";"
                                   << " previous rule was: " << boxpp(reverse(lhs1)) << " => " << boxpp(rhs1) << ";"
                                   << endl;
                          } else {
                              stringstream error;
                              error << "ERROR : " << __FILE__ << ":" << __LINE__ << endl;
                              throw faustexception(error.str());
                          }
                      } else if (ru->r >= r) {
                          break;
                      }
                  }
          }
      }
  #ifdef DEBUG
      cerr << "automaton " << A << endl << *A << "end automaton" << endl;
  #endif
      return A;
  }

  /* Process a given term tree X starting from state s, modify variable
     substitutions accordingly. Returns the resulting state, or -1 if no
     match. This does all the grunt work of matching. */

  int Automaton::apply_pattern_matcher_internal(Automaton* A, int s, Tree X, vector<Subst>& subst)
  {
      /* FIXME: rewrite this non-recursively? */
      if (s >= 0) {
          list<Trans>::const_iterator t;
          if (A->state[s]->match_num) /* simplify possible numeric argument on the fly */
              X = simplifyPattern(X);
          /* first check for applicable non-variable transitions */
          for (t = A->trans(s).begin(); t != A->trans(s).end(); t++) {
              Tree x;
              Node op(0), op1(0);
              if (t->is_var_trans())
                  continue;
              else if (t->is_cst_trans(x)) {
                  if (X == x) {
                      /* transition on constant */
  #ifdef DEBUG
                      cerr << "state " << s << ", " << *x << ": goto state " << t->state->s << endl;
  #endif
                      Automaton::add_subst(subst, A, s);
                      s = t->state->s;
                      return s;
                  }
              } else if (t->is_op_trans(op)) {
                  Tree x0, x1;
                  if (isBoxPatternOp(X, op1, x0, x1) && op == op1) {
                      /* transition on operation symbol */
  #ifdef DEBUG
                      cerr << "state " << s << ", " << op << ": goto state " << t->state->s << endl;
  #endif
                      Automaton::add_subst(subst, A, s);
                      s = t->state->s;
                      if (s >= 0) s = apply_pattern_matcher_internal(A, s, x0, subst);
                      if (s >= 0) s = apply_pattern_matcher_internal(A, s, x1, subst);
                      return s;
                  }
              }
          }
          /* check for variable transition (is always first in the list of
             transitions) */
          t = A->trans(s).begin();
          if (t->is_var_trans()) {
  #ifdef DEBUG
              cerr << "state " << s << ", _: goto state " << t->state->s << endl;
  #endif
              Automaton::add_subst(subst, A, s);
              s = t->state->s;
          } else {
  #ifdef DEBUG
              cerr << "state " << s << ", *** match failed ***" << endl;
  #endif
              s = -1;
          }
      }
      return s;
  }


  /* Subterm at given path in given term tree. */

  Tree Automaton::subtree(Tree X, int i, const Path& p)
  {
      int  n = (int)p.size();
      Node op(0);
      Tree x0, x1;
      if (i < n && isBoxPatternOp(X, op, x0, x1))
          return subtree((p[i] == 0) ? x0 : x1, i + 1, p);
      else
          return X;
  }


  /* Apply the pattern matcher to a single argument, starting from a given state
     (interface operation). Returns the resulting state, modifies the variable
     bindings E accordingly, and sets C to the resulting closure if a final
     state is reached. Result will be -1 to indicate a matching failure, and C
     will be set to nil if no final state has been reached yet. */

  int Automaton::apply_pattern_matcher(Automaton*    A,  // automaton
                          int           s,  // start state
                          Tree          X,  // arg to be matched
                          Tree&         C,  // output closure (if any)
                          vector<Tree>& E)  // modified output environments
  {
      int           n = A->n_rules();
      vector<Subst> subst(n, Subst());
      /* perform matching, record variable substitutions */
  #ifdef DEBUG
      cerr << "automaton " << A << ", state " << s << ", start match on arg: " << *X << endl;
  #endif
      s = apply_pattern_matcher_internal(A, s, X, subst);
      C = global::config().nil;
      if (s < 0) /* failed match */
          return s;
      /* process variable substitutions */
      list<Rule>::const_iterator r;
      for (r = A->rules(s).begin(); r != A->rules(s).end(); r++) {
          // all rules still active in state s
          if (!isBoxError(E[r->r])) {  // and still viable
              Subst::const_iterator assoc;
              for (assoc = subst[r->r].begin(); assoc != subst[r->r].end(); assoc++) {
                  Tree Z, Z1 = subtree(X, 0, assoc->p);
                  if (searchIdDef(assoc->id, Z, E[r->r])) {
                      if (Z != Z1) {
                          /* failed nonlinearity, add to the set of nonviable rules */
  #ifdef DEBUG
                          cerr << "state " << s << ", rule #" << r->r << ": " << *assoc->id << " := " << *Z1
                               << " *** failed *** old value: " << *Z << endl;
  #endif
                          E[r->r] = boxError();
                      }
                  } else {
                      /* bind a variable for the current rule */
  #ifdef DEBUG
                      cerr << "state " << s << ", rule #" << r->r << ": " << *assoc->id << " := " << *Z1 << endl;
  #endif
                      E[r->r] = pushValueDef(assoc->id, Z1, E[r->r]);
                  }
              }
          }
      }
      if (A->final(s)) {
          /* if in a final state then return the right-hand side together with the
             corresponding variable environment */
          for (r = A->rules(s).begin(); r != A->rules(s).end(); r++)  // all rules matched in state s
              if (!isBoxError(E[r->r])) {                             // and still viable
                  /* return the rhs of the matched rule */
                  C = closure(A->rhs[r->r], global::config().nil, global::config().nil, E[r->r]);
  #ifdef DEBUG
                  cerr << "state " << s << ", complete match yields rhs #" << r->r << ": " << *A->rhs[r->r] << endl;
  #endif
                  return s;
              }
              /* if none of the rules were matched then declare a failed match */
  #ifdef DEBUG
          cerr << "state " << s << ", *** match failed ***" << endl;
  #endif
          return -1;
      }
  #ifdef DEBUG
      cerr << "state " << s << ", successful incomplete match" << endl;
  #endif
      return s;
  }

  /* add all substitutions for a given state */

  void Automaton::add_subst(vector<Subst>& subst, Automaton* A, int s)
  {
      list<Rule>                 rules = A->rules(s);
      list<Rule>::const_iterator r;
      for (r = rules.begin(); r != rules.end(); r++)
          if (r->id != NULL) subst[r->r].push_back(Assoc(r->id, r->p));
  }

  void Automaton::build(State* st)
  {
      state.push_back(st);
      st->s = s++;
      list<Trans>::const_iterator t;
      for (t = st->trans.begin(); t != st->trans.end(); t++) {
          Tree   x;
          double f;
          int    i;
          if (t->is_cst_trans(x) && (isBoxInt(x, &i) || isBoxReal(x, &f))) st->match_num = true;
          build(t->state);
      }
  }

  #ifdef DEBUG
  inline ostream& operator<<(ostream& s, const Automaton& x)
  {
      return x.print(s);
  }
  ostream& Automaton::print(ostream& fout) const
  {
      int i, n = rhs.size();
      for (i = 0; i < n; i++) fout << "rule #" << i << ": " << *rhs[i] << endl;
      n = state.size();
      for (i = 0; i < n; i++) fout << *state[i];
      return fout;
  }
  #endif

}
