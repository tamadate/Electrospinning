//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------

void
Verlet::verlet(int itime) {

	/*Bead *beads = vars->beads.data();
	const int num_bead = vars->beads.size();
	double dx = beads[num_bead-1].x - beads[0].x;
	double dy = beads[num_bead-1].y - beads[0].y;
	double dz = beads[num_bead-1].z - beads[0].z;
	double rsq = (dx * dx + dy * dy + dz * dz);
	if (sqrt(rsq)>Lstep) vars->add_beads(itime);*/

	update_sigma();

	velocity_calculation();
	update_position();	
	compute_force();
	velocity_calculation();

	if(itime%1==0) export_dump();
	
	vars->time+=dt;
	vars->add_beads(itime);
}


void 
Verlet::velocity_calculation(void) {
	double dt2=0.5*dt;
	for (auto &a : vars->beads) {
		a.vx += a.fx * dt2;
	    a.vy += a.fy * dt2;
	    a.vz += a.fz * dt2;
	}
}

void
Verlet::update_position(void) {
	for (auto &a : vars->beads) {
		a.x += a.vx * dt;
		a.y += a.vy * dt;
		a.z += a.vz * dt;
		a.fx=a.fy=a.fz=0.0;
	}
	Bead *beads = vars->beads.data();
	beads[0].x=cos(omega*vars->time)*r0;
	beads[0].y=sin(omega*vars->time)*r0;
	beads[0].z=0;
}


void
Verlet::export_dump(void) {
	int count = vars->time;
	FILE*f=fopen("test.dump", "a");
	int num=vars->beads.size();

	fprintf(f, "ITEM: TIMESTEP\n%d\nITEM: NUMBER OF ATOMS\n%d\nITEM: ATOMS id type x y z\n", count, num);

	for (auto &a : vars->beads) fprintf(f, "%d %d %f %f %f\n", a.id, 100, a.x*L0*1000000, a.y*L0*1000000, a.z*L0*1000000);
	fclose(f);
}

void 
Verlet::update_sigma(void) {
	Bead *beads = vars->beads.data();
	const int num_bead = vars->beads.size();

	for (int i=0; i<num_bead-1; i++){
		double dx = beads[i+1].x - beads[i].x;
		double dy = beads[i+1].y - beads[i].y;
		double dz = beads[i+1].z - beads[i].z;
		double rsq = (dx * dx + dy * dy + dz * dz);
		double l=sqrt(rsq);
		beads[i].sig*=exp(-dt);
		beads[i].sig+=1-beads[i].l/l;
		beads[i].l=l;
	}
}


