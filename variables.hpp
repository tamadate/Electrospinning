#pragma once
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include "CalculationCond.hpp"

using namespace std;
//------------------------------------------------------------------------
struct Bead {
 	double x, y, z;
	double vx, vy, vz;
	double q;
	int id;
	double fx, fy, fz;
	double mass, ap;
	double sig,l;
};

struct Pair {
	int i, j;
};


class Variables {
public:

	Variables(void) {
		time = 0.0;
	 	Bead a;
		a.id = 0;
		a.x = cos ( omega * 0 ) * r0;
		a.y = sin ( omega * 0 ) * r0;
		a.z = 0;
		a.vx = 0;
		a.vy = 0;
		a.vz = 0;
		a.mass = 1;	// m0/m0
		a.fx = 0;
		a.fy = 0;
		a.fz = 0;
		a.q = q0;
		a.ap = a0 / L0;
		a.sig = 1;
		a.l = Lstep;
		beads.push_back ( a );
		add_beads ( 0 );
	}

	/*variables*/
	std::vector<Bead> beads;
	double time;

	/*add to vectors*/
	void add_beads ( int itime ) {
	 	Bead a;
		a.id = itime;
		a.x = cos ( omega * time ) * r0;
		a.y = sin ( omega * time ) * r0;
		a.z = z0;
		a.vx = 0;
		a.vy = 0;
		a.vz = 0;
		a.mass = 1;	// m0/m0
		a.fx = 0;
		a.fy = 0;
		a.fz = 0;
		a.q = q0;
		a.ap = a0 / L0;
		a.sig = 1;
		a.l = Lstep;
		beads.push_back ( a );
	}


private:
};
//------------------------------------------------------------------------
