/************************************************************************
 ************************************************************************
    FAUST compiler
    Copyright (C) 2003-2018 GRAME, Centre National de Creation Musicale
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

#ifndef _FIR_TO_FIR_H
#define _FIR_TO_FIR_H

#include "fir/visitor/array_to_pointer.hh"
#include "fir/visitor/cast_remover.hh"
#include "fir/visitor/constants_copy_from_memory_1.hh"
#include "fir/visitor/constants_copy_from_memory.hh"
#include "fir/visitor/constants_copy_memory.hh"
#include "fir/visitor/constants_copy_to_memory_1.hh"
#include "fir/visitor/constants_copy_to_memory.hh"
#include "fir/visitor/control_expander.hh"
#include "fir/visitor/dsp_renamer.hh"
#include "fir/visitor/fir_checker.hh"
#include "fir/visitor/move_variables_in_front_2.hh"
#include "fir/visitor/move_variables_in_front_3.hh"
#include "fir/visitor/stack_2_struct_rewriter_1.hh"
#include "fir/visitor/stack_2_struct_rewriter_2.hh"
#include "fir/visitor/var_address_remover.hh"
#include "fir/visitor/variable_size_counter.hh"

#endif
