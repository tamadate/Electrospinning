#pragma once

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const double Nw = 6.02e23;
const double kb = 1.38e-23;     /* boltzmann constant */
const double kb_real = kb*Nw/4184.0;     /* boltzmann constant with real unit kcal/molK*/
const double e0 = 8.85e-12;     /* permittivity of vacuum */
const double e = 1.602e-19;     /* elementary charge */
const double MN2=28.0, MHe=4.0026;
const double rho_liq=1000;

/*******************Coeff.************************/
const double four_pi_epu_inv=0.25/M_PI/e0;	
const double Cpress=1e30/Nw*4184;
const double eV_to_kcalmol=23.061;
const double real_to_kcalmol=10000/4.184;	/*	A^2 g fs^-2 mol^-1 to kcal/mol*/
const double kb_real_inv = 1/kb_real;     /* boltzmann constant with real unit kcal/molK*/


const double Q=5e-9;
const double h=0.1;

const double myu=2;
const double G=50000;
const double I=0.1e-6;
const double a0=5e-5;
const double alpha=0.7;

const double vol0=Q*1e-7;
const double m0=rho_liq*vol0;
const double lstep=vol0/(a0*a0*M_PI);
const double q0=I*1e-7;
const double rhoV=I/Q;

const double T0=myu/G;
const double L0=sqrt(q0*q0*four_pi_epu_inv/(a0*a0*G*M_PI));

const double dt=1e-7/T0;
const int itime_max=1e5;
const double omega=(1e4*T0)*2*M_PI;
const double r0=0.00001/L0;
const double vs=0.28*T0/L0;

const double V0=9e3;
const double Vcoeff=q0*V0/h*(T0*T0/L0/m0);
const double Qcoeff=q0*q0*four_pi_epu_inv/(L0*L0)*(T0*T0/L0/m0);
const double Fvecoeff=M_PI*a0*a0*G*(T0*T0/L0/m0);
const double Acoeff=alpha*M_PI*a0*a0/(L0)*(T0*T0/L0/m0);
const double Fgcoeff=9.8*(T0*T0/L0);
const double H=h/L0;
const double Lstep=lstep/L0;

