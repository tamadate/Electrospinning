//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet::compute_coul(void) {
	Bead *beads = vars->beads.data();
	const int num_bead = vars->beads.size();

	for (int i=0; i<num_bead-1; i++){
		for (int j=i+1; j<num_bead; j++){
			double dx = beads[i].x - beads[j].x;
			double dy = beads[i].y - beads[j].y;
			double dz = beads[i].z - beads[j].z;
			double rsq = (dx * dx + dy * dy + dz * dz);
			double r2inv = 1/rsq;
			double force_pair = Qcoeff * sqrt(r2inv)*r2inv;
			beads[i].fx += force_pair * dx;
			beads[i].fy += force_pair * dy;
			beads[i].fz += force_pair * dz;
			beads[j].fx -= force_pair * dx;
			beads[j].fy -= force_pair * dy;
			beads[j].fz -= force_pair * dz;
		}
	}
}

