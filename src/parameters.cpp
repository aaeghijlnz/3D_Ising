#include <iostream>
#include <fstream>
#include "parameters.h"

void Parameters::set_parameters(){
  std::ifstream infile;
  infile.open("parameter.txt",std::ios::in);
  for(int i=0;i<30;i++){	
    infile>>str[i];
    if(str[i]=="k:"){
      infile>>k;
    }
    if(str[i]=="J:"){
      infile>>J;
    }
    if(str[i]=="sigma:"){
      infile>>sigma;
    }
    if(str[i]=="T:"){
      infile>>T;
    }
    if(str[i]=="print_per_nsteps:"){
      infile>>per_steps_n;
    }
    if(str[i]=="E_b:"){
      infile>>E_b;
    }
  }
  infile.close();
  if(k > 0 & k < 100 & J > 0 & J < 100){
  //  std::cout<<"The parameter created sucessfully!"<<std::endl;
//    std::cout<<"k="<<k<<",J="<<J<<",sigma="<<sigma<<",T="<<T<<std::endl;
  } else {
    std::cerr<<"There is a problem with the parameter input!!!";
    std::cin.get();//pause
  }
}

void Parameters::set_specialspin_num(){
  std::ifstream infile;
  infile.open("parameter.txt",std::ios::in);
  for(int i=0;i<20;i++){	
    infile>>str[i];
    if(str[i]=="spec_num:"){
      infile>>specialspin_num;
    }
  }
  infile.close();
  if(true){
 //   std::cout<<"The specialspin_num is:"<<specialspin_num<<std::endl;
  } else {
    std::cerr<<"There is a problem with the specialspin_num input!!!";
    std::cin.get();//pause
  }
}

void Parameters::get_it(){
  std::ifstream infile;
  infile.open("parameter.txt",std::ios::in);
  for(int i=0;i<20;i++){	
    infile>>str[i];
    if(str[i]=="maxit:"){
      infile>>maxit;
    }
    if(str[i]=="outit:"){
      infile>>outit;
    }
  }
  infile.close();
  if(maxit > outit){
  //  std::cout<<"The parameter_it created sucessfully!"<<std::endl;
  //  std::cout<<"maxit="<<maxit<<",outit="<<outit<<std::endl;
  } else {
    std::cerr<<"3333There is a problem with the parameter about it input!!!";
    std::cin.get();//pause
  }
}


void Parameters::set_Jlong(){
	Jlong=xt::zeros<int>({8000});
	std::ifstream infile;
	infile.open("dd_mat20*20*20.txt",std::ios::in);
	for(int i=0;i<8000;i++){
		infile>>Jlong(i);
	}    	
	infile.close();
}















