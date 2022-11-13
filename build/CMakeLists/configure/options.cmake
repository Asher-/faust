
#######################################
#  Build Options
#######################################

option ( DEPLOYMENT_TARGET	      "[MacOS]"                                                   	on )
option ( UNIVERSAL 	              "Compiles and combines i386 and x86_64 architectures [MacOS]"	off )
option ( IOS               	      "Compiles for iOS"	                                        	off )
option ( USE_LLVM_CONFIG          "Force use of llvm-config"	                            	    on )
option ( INCLUDE_EXECUTABLE	      "Include runtime executable"                            		  on )
option ( INCLUDE_STATIC    	      "Include static library"	                            	      off )
option ( INCLUDE_DYNAMIC          "Include dynamic library"	                                	  off )
option ( INCLUDE_OSC    	        "Include Faust OSC library"	                              	  on )
option ( INCLUDE_HTTP    	        "Include Faust HTTPD library"	                            	  on )
option ( INCLUDE_ITP    	        "Include Faust Machine library"	                              off )
option ( INCLUDE_EMCC    	        "Include emcc targets"	                            	        on )
option ( INCLUDE_WASM_GLUE        "Include wasm glue targets"	                              	  on )
option(  INCLUDE_TESTS            "Include tests"                                           	  on )
option ( MSVC_STATIC		          "Use static runtimes with MSVC"                               off)
option ( SELF_CONTAINED_LIBRARY	  "Don't search system architecture files."                     off)
