#ifndef MC_H
#define MC_H

#include "ising.h"
#include "parameters.h"
class MC{
  public:
    MC()
    {
      par.get_it();
      par.set_parameters();
    }
    Parameters par;
    int run(Ising& s);


  private:
};

#endif
