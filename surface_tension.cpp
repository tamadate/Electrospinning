//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



void
Verlet :: compute_surfacetension ( void ) {
	Bead *beads = vars -> beads.data();
	const int num_bead = vars -> beads.size();


	double cx, cy, cz, cr, k_bar;
	if ( num_bead > 2 ) {
		for ( int i = 2; i < num_bead - 1; i++ ) {
			int flag = 0;
			compute_curvature ( i - 1, i, i + 1, cx, cy, cz, cr, flag);

			if ( flag==0 ) {
				k_bar =1 / cr;

				double dx = cx - beads[ i ].x;
				double dy = cy - beads[ i ].y;
				double dz = cz - beads[ i ].z;
				double C = beads[ i - 1 ].ap * asin ( 0.5 * beads[ i - 1 ].l * k_bar ) + beads[ i ].ap * asin ( 0.5 * beads[ i ].l * k_bar );
				double force_pair = Acoeff * C * k_bar;
				beads[ i ].fx += force_pair * dx;
				beads[ i ].fy += force_pair * dy;
				beads[ i ].fz += force_pair * dz;

				dx = beads[ i - 1 ].x - beads[ i ].x;
				dy = beads[ i - 1 ].y - beads[ i ].y;
				dz = beads[ i - 1 ].z - beads[ i ].z;
				double rsq = ( dx * dx + dy * dy + dz * dz );
				double r2inv = 1 / rsq;
				force_pair = Acoeff * sqrt ( beads[ i - 1 ].ap ) * sqrt ( r2inv );
				beads[ i ].fx += force_pair * dx;
				beads[ i ].fy += force_pair * dy;
				beads[ i ].fz += force_pair * dz;
				beads[ i - 1 ].fx -= force_pair * dx;
				beads[ i - 1 ].fy -= force_pair * dy;
				beads[ i - 1 ].fz -= force_pair * dz;
			}
		}

		int flag = 0;
		compute_curvature ( num_bead - 2, num_bead - 1, 0, cx, cy, cz, cr, flag );
		if ( flag == 0 ) {
			k_bar = 1 / cr;

			double dx = cx - beads[ num_bead - 1 ].x;
			double dy = cy - beads[ num_bead - 1 ].y;
			double dz = cz - beads[ num_bead - 1 ].z;
            double C = beads[ num_bead - 2 ].ap * asin ( 0.5 * beads[ num_bead - 2 ].l * k_bar ) + beads[ num_bead - 1 ].ap * asin ( 0.5 * beads[ num_bead - 1 ].l * k_bar );
			double force_pair = Acoeff*C*k_bar;
			beads[ num_bead - 1 ].fx += force_pair * dx;
			beads[ num_bead - 1 ].fy += force_pair * dy;
			beads[ num_bead - 1 ].fz += force_pair * dz;

			dx = beads[ num_bead - 2 ].x - beads[ num_bead - 1 ].x;
			dy = beads[ num_bead - 2 ].y - beads[ num_bead - 1 ].y;
			dz = beads[ num_bead - 2 ].z - beads[ num_bead - 1 ].z;
			double rsq = (dx * dx + dy * dy + dz * dz);
			double r2inv = 1 / rsq;
            force_pair = Acoeff * sqrt ( beads[ num_bead - 2 ].ap ) * sqrt ( r2inv );
			beads[num_bead-1].fx += force_pair * dx;
			beads[num_bead-1].fy += force_pair * dy;
			beads[num_bead-1].fz += force_pair * dz;
			beads[num_bead-2].fx -= force_pair * dx;
			beads[num_bead-2].fy -= force_pair * dy;
			beads[num_bead-2].fz -= force_pair * dz;
		}
	}
}



void 
Verlet::gauss(double a[3][3 + 1])  
{
    for (int i = 0; i < 3; i++) {
        double m = 0, t;
        int pivot = i;
        for (int j = i; j < 3; j++)
            if (fabs(a[j][i]) > m)
                m = fabs(a[j][i]), pivot = j;
        if (pivot != i)
            for (int j = 0; j <= 3; j++)
                t = a[i][j], a[i][j] = a[pivot][j], a[pivot][j] = t;
    }
    for (int k = 0; k < 3; k++) {
        double p = a[k][k];
        a[k][k] = 1;
        for (int j = k + 1; j <= 3; j++)
            a[k][j] /= p;
        for (int i = k + 1; i < 3; i++) {
            double q = a[i][k];
            for (int j = k + 1; j <= 3; j++)
                a[i][j] -= q * a[k][j];
            a[i][k] = 0;
        }
    }
    for (int i = 3; --i >= 0; )
        for (int j = 3; --j > i; )
            a[i][3] -= a[i][j] * a[j][3];
}


void
Verlet::compute_curvature(int i, int j, int k, double &cx, double &cy, double &cz, double &cr, int &flag) 
{
	Bead *beads = vars->beads.data();

    // |AP| = |BP|
    // (x - A.x)^2 + (y - A.y)^2 + (z - A.z)^2
    //    = (x - B.x)^2 + (y - B.y)^2 + (z - B.z)^2
    M[0][0] = 2*(beads[j].x - beads[i].x);
    M[0][1] = 2*(beads[j].y - beads[i].y);
    M[0][2] = 2*(beads[j].z - beads[i].z);
    M[0][3] = beads[j].x*beads[j].x+ beads[j].y*beads[j].y + beads[j].z*beads[j].z - beads[i].x*beads[i].x - beads[i].y*beads[i].y - beads[i].z*beads[i].z;

    // |AP| = |CP|
    // (x - A.x)^2 + (y - A.y)^2 + (z - A.z)^2
    //    = (x - C.x)^2 + (y - C.y)^2 + (z - C.z)^2
    M[1][0] = 2*(beads[k].x - beads[i].x);
    M[1][1] = 2*(beads[k].y - beads[i].y);
    M[1][2] = 2*(beads[k].z - beads[i].z);
    M[1][3] = beads[k].x*beads[k].x+ beads[k].y*beads[k].y + beads[k].z*beads[k].z - beads[i].x*beads[i].x - beads[i].y*beads[i].y - beads[i].z*beads[i].z;

    double AB[3] = { beads[j].x - beads[i].x, beads[j].y - beads[i].y, beads[j].z - beads[i].z };  // vectorAB
    double AC[3] = { beads[k].x - beads[i].x, beads[k].y - beads[i].y, beads[k].z - beads[i].z };  // vectorAC

	double xratio=AB[0]/AC[0];
	double yratio=AB[1]/AC[1];
	double zratio=AB[2]/AC[2];
	if((xratio-yratio)*(xratio-yratio)<1e-30 &&  (xratio-zratio)*(xratio-zratio)<1e-30){
		double ABxAC[3] = {   
		    AB[1]*AC[2] - AB[2]*AC[1],
		    AB[2]*AC[0] - AB[0]*AC[2],
		    AB[0]*AC[1] - AB[1]*AC[0],
		};
		// P は 平面ABC上、法線ベクトルABxAC とベクトルAP は直交、内積が 0
		// ABxAC[0](x - A.x) + ABxAC[1](y - A.y) + ABxAC[2](z - A.z) = 0
		M[2][0] = ABxAC[0];
		M[2][1] = ABxAC[1];
		M[2][2] = ABxAC[2];
		M[2][3] = ABxAC[0]*beads[i].x + ABxAC[1]*beads[i].y + ABxAC[2]*beads[i].z;

		gauss(M);

		cx=M[0][3];
		cy=M[1][3];
		cz=M[2][3];

		cr=sqrt((cx-beads[i].x)*(cx-beads[i].x)+(cy-beads[i].y)*(cy-beads[i].y)+(cz-beads[i].z)*(cz-beads[i].z));
	}
	else flag=1;
}




