#include "mc.h"

int MC::run(Ising& s ){
	s.set_1_kT();
	s.set_activespins();
	for (int i=0;i<par.maxit;i++){
//		s.set_activespins();	 
		s.loop();
		s.Notify(); // Keep a record for every step.
		if(i%(par.per_steps_n) == 0){
			//every par.per_steps_n steps print to shell,to record the progress
			std::cout << "Step: " << i << std::endl;
		}
	}
	return 0;
}
