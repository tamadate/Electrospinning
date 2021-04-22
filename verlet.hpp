#pragma once
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "CalculationCond.hpp"
#include "variables.hpp"

//------------------------------------------------------------------------

class Verlet {
public:
	Variables *vars;
	Verlet(void) {
		vars = new Variables();
	}
	~Verlet(void) {
		delete vars;	
	}

	void verlet(int itime);
	void velocity_calculation(void);
	void update_position(void);
	void export_dump(void);
	void compute_coul(void);
	void compute_force(void);
	void compute_e_field_simple(void);
    void compute_e_field(void);
	void compute_viscoelastic(void);
	void compute_surfacetension(void);
	void compute_dragforce(void);
	void compute_dragforce_sub(int i, int j, int k);
	void update_sigma(void);
	

    double M[ 3 ][ 3 + 1 ];  // Matrix
	void gauss(double a[ 3 ][ 3 + 1 ]);
	void compute_curvature(int i, int j, int k, double &cx, double &cy, double &cz, double &cr, int &flag);


private:
};
//------------------------------------------------------------------------
