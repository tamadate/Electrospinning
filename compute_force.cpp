//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet::compute_force(void) {
	compute_coul();
	compute_e_field_simple();
	compute_viscoelastic();
	compute_surfacetension();
	compute_dragforce();
}

