#ifndef PARAMETERS_H
#define PARAMETERS_H
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include <string>

class Parameters {
  public:
    std::string str[30];
    double par[30];
    double k;
    double T;
    double J;
    double E_b;
    double sigma;
    int specialspin_num;
    int maxit;
    int outit;
    int per_steps_n;
    void set_parameters();
    void set_specialspin_num();
    void get_it();
    bool longeffect;
    xt::xarray<double> Jlong;
    void set_Jlong();
};
#endif
