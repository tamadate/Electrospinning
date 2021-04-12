//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet::compute_e_field(void) {
	Bead *beads = vars->beads.data();
	const int num_bead = vars->beads.size();

	for (auto &a : vars->beads) {
		a.fz += Vcoeff;
	}
}

