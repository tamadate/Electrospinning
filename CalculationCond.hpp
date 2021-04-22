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

const double Nw = 6.02e23; /* avogadro's number  */
const double kb = 1.38e-23;     /* boltzmann constant */
const double e0 = 8.85e-12;     /* permittivity of vacuum */
const double e = 1.602e-19;     /* elementary charge */
const double rho_liq = 1000; /*  liquid density */
const double four_pi_epu_inv = 0.25 / M_PI / e0;	

/* experimental parameters (with SI unit)*/
const double h = 0.2;   /*needle-collector distance */
const double myu = 1000;   /*  liquid viscosity */
const double myu_air = 18.6e-6;   /* gas viscosity */
const double G = 100000; /* Young's modulus */
const double I = 2.93e-7; /* Current */
const double a0 = 150e-6; /* initial radius of the cylinder */
const double lstep = h / 5e4; /* initial length of the cylinder */
const double alpha = 70e-3; /* surface tension */
const double V0 = 1e4; /* strength of applied high voltage */

/* calculation parameters (with SI unit)*/
const double dt = 1e-7; /* time step */
const long int itime_max = 1e10; /* total number of time steps */
const int i_gen = 400; /* interval of a cylinder generation */
const double vol0 = M_PI * a0 * a0 * lstep; /* volume of a cylinder element */
const double m0 = rho_liq * vol0; /* mass of a cylinder element */
const double q0 = I * dt * i_gen; /* charge of a cylinder element */
const double Q = vol0 / dt / i_gen; /* total flow rate of liquid  */

/* parameters for non-dimensionalization */
const double T0 = myu / G; /* time */
const double L0 = sqrt ( q0 * q0 * four_pi_epu_inv / ( a0 * a0 * G * M_PI ) ); /* length */

/* dimensionless parameters */
const double H = h / L0; /*needle-collector distance */
const double dt_bar = dt / T0; /* time */
const double omega = ( 1e4 * T0 ) * 2 * M_PI; /* angular frequency */
const double r0 = 25e-6 / L0; /* radius of the perturbation */
const double vs = 0.28 * T0 / L0; /* initial velocity */
const double Lstep = lstep / L0; /* initial length of the cylinder */
const double z0 = sqrt ( Lstep * Lstep + r0 * r0 );

/* coefficients for force calculation */
const double Vcoeff = q0 * 2 * V0 / log ( 1 + 4 * h / a0 ) * ( T0 * T0 / L0 / m0 ); /* electric field */
const double Vcoeff_simple = q0 * V0 / h; /* electric field (Voltage devided by distance h) */
const double Qcoeff = q0 * q0 * four_pi_epu_inv / ( L0 * L0 ) * ( T0 * T0 / L0 / m0 );  /* Coulombic */
const double Fvecoeff = 4 * M_PI * a0 * a0 * G * ( T0 * T0 / L0 / m0 ); /* viscoelastic */
const double Acoeff = 4 * alpha * M_PI * a0 * ( T0 * T0 / L0 / m0 ); /* surface tension */
const double Fgcoeff = 9.8 * ( T0 * T0 / L0 ); /* gravity */
const double FDn = -12 * M_PI * myu_air * L0 * L0 / T0 * ( T0 * T0 / L0 / m0 ); /* drag */
const double FDt = -6 * myu_air * L0 * L0 / T0 * ( T0 * T0 / L0 / m0 ); /* drag */


