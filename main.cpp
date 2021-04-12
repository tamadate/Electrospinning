//------------------------------------------------------------------------
#include "verlet.hpp"
//------------------------------------------------------------------------



int main(int argc,char *argv[]) {
	Verlet *verl;
	verl = new Verlet();
	for(int itime=0; itime<itime_max; itime++){
		verl->verlet(itime);
	}
	delete verl;
	return 0;
}

