#include <iostream>
#include <fstream>
#include "alloy_in_generate.h"

void set_alloyin(Structure s){
	Parameters par;
	par.set_specialspin_num();
	int alloy_in[s.nsites];
	int rand_num[s.nsites];
	for(int i=0;i<s.nsites;i++){
		alloy_in[i]=1;
		rand_num[i]=i;
	}
	for(int i=s.nsites-1;i>=1;--i){ 
		std::swap(rand_num[i],rand_num[rand()%i]);	
	}
	for(int i=0;i<par.specialspin_num;i++){
		alloy_in[rand_num[i]]=-1;
	}
	std::ofstream outfile;
	outfile.open("alloy_in.txt");
	for(int i=0;i<s.nsites;i++){
		outfile<<alloy_in[i]<<std::endl;
//		std::cout<<alloy_in[i]<<std::endl;
	}
	outfile.close();
}
