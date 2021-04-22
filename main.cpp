//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



int main( int argc, char *argv[] ) {
	Verlet *verl;
	verl = new Verlet();
	cout << "current " << I * 1e6 << " uA" << endl;
	cout << "Vol. flow rate " << Q * 3600 * 1e6 << " mL/h" << endl;
    for ( int itime = 0; itime < itime_max; itime++ ) {
		verl -> verlet ( itime );
	}
	delete verl;
	return 0;
}

