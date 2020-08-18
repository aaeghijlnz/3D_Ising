//
// Created by Dawei Wang on 2020/6/18.
//

#include <string>
#include "ising_observer.h"

void Ising_observer :: Update() {
    double av = this->subject_.get_average();
    this->average.push_back(av);
}

void Ising_observer :: print_info() {
    //Output the saved average values.
    int len = average.size();

    for(int i = 0; i < len; i++){
    //    std::cout << i << " " << average[i] << std::endl;
  }
	int nx = 1;
	int ny = len;
   NcFile dataFile("average_mc.nc",NcFile::Replace);
   if (!dataFile.is_valid())
   {
      std::cout << "Couldn't open file!\n";
   }
    char str[2];
    sprintf(str, "%lf", subject_.T());
   NcDim* xDim = dataFile.add_dim("avspins", nx);
   NcDim* yDim = dataFile.add_dim("steps", ny);
   NcVar *data = dataFile.add_var(str, ncDouble, xDim, yDim);
	//NcAtt *att = dataFile.add_att("s",ncInt,"s");
   data->put(&average[0],nx,ny);
}


