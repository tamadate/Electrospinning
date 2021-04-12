//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet::compute_surfacetension(void) {
	Bead *beads = vars->beads.data();
	const int num_bead = vars->beads.size();

	double x1,x2,x3,y1,y2,y3,cx_u,cy_u,c_d,cx,cy,k_bar_inv,k_bar;
	for (int i=2; i<num_bead-1; i++){
		x1=beads[i-1].x;
		x2=beads[i].x;
		x3=beads[i+1].x;
		y1=beads[i-1].y;
		y2=beads[i].y;
		y3=beads[i+1].y;
		cx_u = (y1-y2)*(x3*x3-x1*x1+y3*y3-y1*y1)-(y1-y3)*(x2*x2-x1*x1+y2*y2-y1*y1);
		cy_u = (x1-x3)*(x2*x2-x1*x1+y2*y2-y1*y1)-(x1-x2)*(x3*x3-x1*x1+y3*y3-y1*y1);
		c_d = 2*(x1-x2)*(y1-y3)-2*(x1-x3)*(y1-y2);
		cx=cx_u/c_d;
		cy=cy_u/c_d;
		k_bar_inv=sqrt((cx-x1)*(cx-x1)+(cy-y1)*(cy-y1));
		k_bar=1/k_bar_inv;

		double dx = beads[i].x - cx;
		double dy = beads[i].y - cy;
		double rsq = (dx * dx + dy * dy);
		double r2inv = 1/rsq;
		double C=1/sqrt(beads[i].l)+1/sqrt(beads[i-1].l);
		double force_pair = Lstep*Acoeff*0.25*k_bar*C*C*sqrt(r2inv);
		beads[i].fx -= force_pair * dx;
		beads[i].fy -= force_pair * dy;
	}

	x1=beads[num_bead-2].x;
	x2=beads[num_bead-1].x;
	x3=beads[0].x;
	y1=beads[num_bead-2].y;
	y2=beads[num_bead-1].y;
	y3=beads[0].y;
	cx_u = (y1-y2)*(x3*x3-x1*x1+y3*y3-y1*y1)-(y1-y3)*(x2*x2-x1*x1+y2*y2-y1*y1);
	cy_u = (x1-x3)*(x2*x2-x1*x1+y2*y2-y1*y1)-(x1-x2)*(x3*x3-x1*x1+y3*y3-y1*y1);
	c_d = 2*(x1-x2)*(y1-y3)-2*(x1-x3)*(y1-y2);
	cx=cx_u/c_d;
	cy=cy_u/c_d;
	k_bar_inv=sqrt((cx-x1)*(cx-x1)+(cy-y1)*(cy-y1));
	k_bar=1/k_bar_inv;

	double dx = beads[num_bead-1].x - cx;
	double dy = beads[num_bead-1].y - cy;
	double rsq = (dx * dx + dy * dy);
	double r2inv = 1/rsq;
	double C=1/sqrt(beads[num_bead-1].l)+1/sqrt(beads[num_bead-2].l);
	double force_pair = Lstep*Acoeff*0.25*k_bar*C*C*sqrt(r2inv);
	beads[num_bead-1].fx -= force_pair * dx;
	beads[num_bead-1].fy -= force_pair * dy;

}

