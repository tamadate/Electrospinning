//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet::compute_viscoelastic(void) {
	Bead *beads = vars -> beads.data();
	const int num_bead = vars -> beads.size();

	double dx, dy, dz, rsq, r2inv, force_pair;

	for ( int i = 2; i < num_bead; i++ ) {
		dx = beads[ i - 1 ].x - beads[ i ].x;
		dy = beads[ i - 1 ].y - beads[ i ].y;
		dz = beads[ i - 1 ].z - beads[ i ].z;
		rsq = (dx * dx + dy * dy + dz * dz);
		r2inv = 1 / rsq;
		force_pair = Fvecoeff * beads[ i - 1 ].sig * beads[ i - 1 ].ap * beads[ i - 1 ].ap * sqrt ( r2inv );
		beads[ i ].fx += force_pair * dx;
		beads[ i ].fy += force_pair * dy;
		beads[ i ].fz += force_pair * dz;
		beads[ i - 1 ].fx -= force_pair * dx;
		beads[ i - 1 ].fy -= force_pair * dy;
		beads[ i - 1 ].fz -= force_pair * dz;
	}

	dx = beads[ num_bead - 1 ].x - beads[ 0 ].x;
	dy = beads[ num_bead - 1 ].y - beads[ 0 ].y;
	dz = beads[ num_bead - 1 ].z - beads[ 0 ].z;
	rsq = ( dx * dx + dy * dy + dz * dz );
	r2inv = 1 / rsq;
    force_pair = Fvecoeff * beads[ num_bead - 1 ].sig * beads[ num_bead - 1 ].ap * beads[ num_bead - 1 ].ap * sqrt ( r2inv );
	beads[ num_bead - 1 ].fx -= force_pair * dx;
	beads[ num_bead - 1 ].fy -= force_pair * dy;
	beads[ num_bead - 1 ].fz -= force_pair * dz;
}

