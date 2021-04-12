//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet::compute_force(void) {
	compute_coul();
	compute_e_field();
	compute_viscoelastic();
	//compute_surfacetension();
}

