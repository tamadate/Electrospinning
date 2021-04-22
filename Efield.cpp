//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet :: compute_e_field_simple ( void ) {
	for ( auto &a : vars->beads ) {
		a.fz += Vcoeff_simple*400;
	}
}



void
Verlet :: compute_e_field ( void ) {
	for ( auto &a : vars->beads ) {
		a.fz += Vcoeff_simple;
	}
}

