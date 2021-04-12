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
	void compute_e_field(void);
	void compute_viscoelastic(void);
	void compute_surfacetension(void);
	void update_sigma(void);
	


private:
};
//------------------------------------------------------------------------
