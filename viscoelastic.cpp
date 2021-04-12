//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet::compute_viscoelastic(void) {
	Bead *beads = vars->beads.data();
	const int num_bead = vars->beads.size();

	double dx,dy,dz,rsq,r2inv,force_pair;

	for (int i=2; i<num_bead; i++){
		dx = beads[i].x - beads[i-1].x;
		dy = beads[i].y - beads[i-1].y;
		dz = beads[i].z - beads[i-1].z;
		rsq = (dx * dx + dy * dy + dz * dz);
		r2inv = 1/rsq;
		force_pair = Lstep*Fvecoeff*beads[i].sig*r2inv;
		beads[i].fx -= force_pair * dx;
		beads[i].fy -= force_pair * dy;
		beads[i].fz -= force_pair * dz;
		beads[i-1].fx += force_pair * dx;
		beads[i-1].fy += force_pair * dy;
		beads[i-1].fz += force_pair * dz;
	}

	dx = beads[0].x - beads[num_bead-1].x;
	dy = beads[0].y - beads[num_bead-1].y;
	dz = beads[0].z - beads[num_bead-1].z;
	rsq = (dx * dx + dy * dy + dz * dz);
	r2inv = 1/rsq;
	force_pair = Lstep*Fvecoeff*beads[0].sig*r2inv;
	beads[0].fx -= force_pair * dx;
	beads[0].fy -= force_pair * dy;
	beads[0].fz -= force_pair * dz;
	beads[num_bead-1].fx += force_pair * dx;
	beads[num_bead-1].fy += force_pair * dy;
	beads[num_bead-1].fz += force_pair * dz;

}

