#include <functional>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include<stdio.h>
#include<gsl/gsl_rng.h>
#include "ising.h"

void Ising::loop() {
    infile_init_spins();//init spins in loop().(or in main().)
    H_random_init();	//init H_random
//    std::cout<<H_random(1)<<std::endl;
    for (int i = 0; i < natoms; i++) {
		if( alloy(i)<0 ){
			dE = try_change(i);
			if (try_flip(dE)) {
				apply_change(i);
			}
		}
    }
    outfile_spins();
}

double Ising::get_average() {
    double spins_sum = 0.0;
    for (int i = 0; i < natoms; i++) {
        spins_sum = spins_sum + spins(i);
    }
    double average_dipole_sum = spins_sum / double(natoms);
    return average_dipole_sum;
}

double Ising::get_spins() {
    std::cout << spins << std::endl;
    return 0;
}

void Ising::outfile_spins() {
    std::ofstream outfile;
    outfile.open("cfj.txt");
    for (int i = 0; i < natoms; i++) {
        outfile << spins(i) << std::endl;
    }
    outfile.close();
}

void Ising::infile_init_spins() {
    std::ifstream infile;
    infile.open("cfj.txt", std::ios::in);
    for (int i = 0; i < natoms; i++) {
        infile >> spins(i);
    }
    infile.close();
}

void Ising::init_spin(const xt::xarray<double> spin_init_values) {
    //use spin_init_values to initialize the spin in the system.
    for (int in = 0; in < natoms; in++) {
        spins(in) = spin_init_values(in);
    }
}

double Ising::hamiltonian(int i) {
    double Hamiltonians =
            -par.J * spins(structure.ia000(i)) *
                    (spins(structure.ia001(i)) + spins(structure.ia00i(i))
                    + spins(structure.ia0i0(i)) + spins(structure.ia010(i))
                    + spins(structure.iai00(i)) + spins(structure.ia100(i))+H_random(structure.ia000(i)));
    return Hamiltonians;
}

double Ising::try_change(int i) {
    double E1, E2;
    E1 = hamiltonian(i);
    spins(i) = -spins(i);
    E2 = hamiltonian(i);
    spins(i) = -spins(i);
    return E2 - E1;
}

void Ising::H_random_init(){
	for(int i = 0; i < natoms;i++){
		double A = sqrt((-2)*log(gsl_rng_uniform (r)));		
		double B = 2 * PI*gsl_rng_uniform (r);				           
	   double E=0.0;			               
	   double D=par.sigma;				
		H_random(i)= E+D*A*cos(B);
	}
}


void Ising::apply_change(int i) {
    spins(i) = -spins(i);
}

double Ising::set_1_kT() {
    double tmp = par.T;
    kT = 1 / (tmp * par.k);
std::cout<<"kT:		"<<kT<<std::endl;
    return 0;
}

double Ising::T() {
    return par.T;
}

bool Ising::try_flip(double de) {
    if (de < 0) {
        return true;
    } else {
        double p = gsl_rng_uniform(r);
        if (p < exp(-de * kT)) {
            return true;
        } else {
            return false;
        }
    }
    return 0;
}

void Ising::set_activespins() {
double w2 = exp(-(par.E_b)* kT);
    for (int j = 0 ; j < 8000 ; j++) {
		double w1 = gsl_rng_uniform (r);
		if (w1 <= w2)
       {
			alloy(j)=-1;
    	}
		else{
			alloy(j)=1;
  		}
	}
}

double Ising::spins_total() {  //
    double Spins_Sum = 0.0;
    for (int i = 0; i < natoms; i++) {
        Spins_Sum = Spins_Sum + spins(i);
    }
    return Spins_Sum;
}

int Ising::positive_total() {  //
    int positive_Sum = 0;
    for (int i = 0; i < natoms; i++) {
        if(spins(i) > 0 ){
		positive_Sum += 1;
    	  }
     }
    return positive_Sum;
}

int Ising::negative_total() {  //
    int negative_Sum = 0;
    for (int i = 0; i < natoms; i++) {
        if(spins(i) < 0 ){
		negative_Sum += 1;
    	  }
     }
    return negative_Sum;
}

