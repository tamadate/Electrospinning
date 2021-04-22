//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------

void
Verlet :: compute_dragforce( void ) {
	const int num_bead = vars -> beads.size();

	for ( int i = 2; i < num_bead - 1; i++ ) {
		compute_dragforce_sub ( i, i - 1, i );
		compute_dragforce_sub ( i ,i, i + 1 );
	}
	if ( num_bead > 2 ) {
		compute_dragforce_sub ( 1, 1, 2 );
		compute_dragforce_sub ( 1, 1, 2 );
	}
	compute_dragforce_sub ( num_bead - 1, num_bead - 2, num_bead - 1 );
	compute_dragforce_sub( num_bead - 1, num_bead - 1, 0 );
}

void
Verlet :: compute_dragforce_sub ( int i, int j, int k ) {
	Bead *beads = vars -> beads.data( );
	double vx, vy, vz, dx, dy, dz, rsq, r ,vn_nn_r, vnx, vny, vnz, vtx, vty, vtz, vn, vt, vsq, v;
	vx = beads[ i ].vx;
	vy = beads[ i ].vy;
	vz = beads[ i ].vz;
	dx = beads[ j ].x - beads[ k ].x;
	dy = beads[ j ].y - beads[ k ].y;
	dz = beads[ j ].z - beads[ k ].z;
	rsq = ( dx * dx + dy * dy + dz * dz );
	r = sqrt ( rsq );
	vsq = ( vx * vx + vy * vy + vz * vz );
	v = sqrt ( vsq );
	vn_nn_r = ( vx * dx + vy * dy + vz * dz ) / ( dx * dx + dy * dy + dz * dz ) / r;

	vnx = vn_nn_r * dx;
	vny = vn_nn_r * dy;
	vnz = vn_nn_r * dz;
	vn = sqrt ( vnx * vnx + vny * vny + vnz * vnz );
	vtx = vx - vnx;
	vty = vy - vny;
	vtz = vz - vnz;
	vt = sqrt ( vtx * vtx + vty * vty + vtz * vtz );
	double force_n = FDn * beads[ j ].ap;
	double force_t = FDt * beads[ j ].l;
	beads[ i ].fx += force_n * vnx + force_t * vtx;
	beads[ i ].fy += force_n * vny + force_t * vty;
	beads[ i ].fz += force_n * vnz + force_t * vtz;
}
