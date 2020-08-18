#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include <cstdlib>
#include <time.h>

#include "structure.h"
#include "ising.h"
#include "mc.h"
#include "alloy_in_generate.h"
#include "parameters.h"
#include "ising_observer.h"

int main(){
  const double lat[3][3] = {
    {1,0,0},   
    {0,1,0},
    {0,0,1},
  };
  Structure s = Structure(lat, 20,20,20);//structure 
  //set_alloyin(s);
  MC mc;
  Ising ising(s);
  Ising_observer *ob1 = new Ising_observer(ising);
  mc.run(ising);
  ob1->print_info(); 

  delete ob1;
  return 0;
}
