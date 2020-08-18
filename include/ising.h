//
// Created by Dawei Wang on 2020/5/8.
//
#ifndef ISING_H
#define ISING_H
#include <iostream>
#include <functional>
#include <netcdfcpp.h>

#include "structure.h"
#include "system.h"

class Ising: public System 
{
  public:
    Ising(Structure s):
      System(s),
      spins{xt::zeros<double>({s.nsites})},
      alloy{xt::zeros<int>({s.nsites})},
      H_random{xt::zeros<int>({s.nsites})}
      {
	par.set_parameters();
      }
    xt::xarray<double> spins;
    xt::xarray<double> H_random;
    xt::xarray<int> alloy;

    ~Ising(){}

    void infile_init_spins();
    void init_spin(xt::xarray<double> spin_init_value);
    void loop();

    double set_1_kT();
    double get_average();
    void outfile_spins();
    double T1;
    double T();
    double tmp;

    double spins_total();
    int positive_total();
    int negative_total();
    double get_spins();
    bool try_flip(double de);
    double hamiltonian(int i);
    double Magnetization_Sum;
    double kT;
    double dE;
    void apply_change(int i);
    double try_change(int i);
    double p;
    void set_activespins();
    void H_random_init();
    double PI=3.1415926;

};

#endif
