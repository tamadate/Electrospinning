//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------

void
Verlet :: verlet ( int itime ) {

	/*Bead *beads = vars->beads.data();
	const int num_bead = vars->beads.size();
	double dx = beads[num_bead-1].x;
	double dy = beads[num_bead-1].y;
	double dz = beads[num_bead-1].z;
	double rsq = (dx * dx + dy * dy + dz * dz);*/
    //if ( ( rsq > Lstep * Lstep ) ) vars -> add_beads( itime );
	if ( ( itime + 1 ) % i_gen == 0 ) vars -> add_beads( itime );

	update_sigma();

	velocity_calculation();
	update_position();	
	compute_force();
	velocity_calculation();

	if ( itime % 100 == 0 ) export_dump();
	
	vars -> time += dt_bar;

}


void 
Verlet :: velocity_calculation ( void ) {
	double dt2 = 0.5 * dt_bar;
	for ( auto &a : vars -> beads ) {
		a.vx += a.fx * dt2;
	    a.vy += a.fy * dt2;
	    a.vz += a.fz * dt2;
	}
}

void
Verlet :: update_position ( void ) {
	Bead *beads = vars -> beads.data();
	const int num_bead = vars -> beads.size();
	int i_remove = 0;
	for ( int i = 0; i < num_bead; i++ ) {
		beads[ i ].x += beads[ i ].vx * dt_bar;
		beads[ i ].y += beads[ i ].vy * dt_bar;
		beads[ i ].z += beads[ i ].vz * dt_bar;
		beads[ i ].fx = beads[ i ].fy = beads[ i ].fz = 0.0;
		if ( beads[ i ].z > H ) i_remove = i;
	}
	beads[ 0 ].x = 0;
	beads[ 0 ].y = 0;
	beads[ 0 ].z = 0;
	if ( i_remove > 0 ) {
		for ( int i = 0; i < i_remove; i++ )	vars -> beads.erase ( vars -> beads.begin() + 1 );
	}
}


void
Verlet :: export_dump ( void ) {
	int count = vars -> time;
	FILE *f = fopen ( "test.dump", "a" );
	int num = vars -> beads.size();

	fprintf ( f, "ITEM: TIMESTEP\n%d\nITEM: NUMBER OF ATOMS\n%d\nITEM: ATOMS id type x y z\n", count, num );

	for ( auto &a : vars -> beads ) fprintf ( f, "%d %d %f %f %f\n", a.id, 100, a.x , a.y, a.z);
	fclose( f );
}

void 
Verlet :: update_sigma ( void ) {
	Bead *beads = vars -> beads.data();
	const int num_bead = vars -> beads.size();

	for ( int i = 1; i < num_bead; i++ ) {
		double dx = beads[ i - 1 ].x - beads[ i ].x;
		double dy = beads[ i - 1 ].y - beads[ i ].y;
		double dz = beads[ i - 1 ].z - beads[ i ].z;
		double rsq = ( dx * dx + dy * dy + dz * dz );
		double l = sqrt ( rsq );
		beads[ i - 1 ].sig *= exp ( -dt_bar );
		beads[ i - 1 ].sig += 1 - beads[ i - 1 ].l / l;
		beads[ i - 1 ].l = l;
	}
	int i = num_bead - 1;
	double dx = beads[ i ].x - beads[ 0 ].x;
	double dy = beads[ i ].y - beads[ 0 ].y;
	double dz = beads[ i ].z - beads[ 0 ].z;
	double rsq = ( dx * dx + dy * dy + dz * dz );
	double l = sqrt ( rsq );
	beads[ i ].sig *= exp( -dt_bar );
	beads[ i ].sig += 1 - beads[ i ].l / l;
	beads[ i ].l = l;
    beads[ i ].ap = sqrt ( vol0 / M_PI / l / L0 ) / L0;
}



