//
// Created by Dawei Wang on 2020/5/12.
//
#include <iostream>
#include "structure.h"

//The 3D position is given by (ix,iy,iz).
//:return: return the real ia(ix,iy,iz)
int Structure::cal_index(int ix,int iy,int iz){
	while (ix >= nx)
		ix -= nx;
	while (ix < 0)
		ix += nx;
	while (iy >= ny)
		iy -= ny;
	while (iy < 0)
		iy += ny;
	while (iz >= nz)
		iz -= nz;
	while (iz < 0)
		iz += nz;
	return iaa(ix,iy,iz);
}

void Structure::set_supercell(const double lattice[3][3]){
	int factor[] = {nx, ny, nz};
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			a(i,j) = factor[i] * lattice[i][j];
		}
	}
	int nxy = 0;
	for(int i = 0;i < nx;i++){
		for(int j = 0;j < ny;j++){
			ix(nxy) = i;
			iy(nxy) = j;
			nxy += 1;
			site(i,j) = nxy;//site begins form 1
		}
	}
	int l_ = 0;
	for(int i = 0;i < nx;i++){
		for(int j = 0;j < ny;j++){
			for(int k = 0;k < nz;k++){
				iaa(i, j, k) = l_;//iaa begins form 0
				ixa(l_) = i;//index of every iaa[l_] 
				iya(l_) = j;
				iza(l_) = k;
        
				l_ += 1;
			}
		}
	}
}

void Structure::print_a(){
	std::cout<<a<<std::endl;
}

//i is the index of a point in supercell
//return: 3D position
int  Structure::cal_xyz(int i){
        xyz(0) = ixa(i);
        xyz(1) = iya(i);
        xyz(2) = iza(i);
        return 0;
}



//i,j are the index of two points in supercell
//return: the distance of them by index
int Structure::cal_distance(int i , int j){
	cal_xyz(i);
	int ix =xyz(0);
	int iy =xyz(1);
	int iz =xyz(2);
	cal_xyz(j);
	int jx =xyz(0);
	int jy =xyz(1);
	int jz =xyz(2);
	return cal_index(ix - jx, iy - jy, iz - jz);
}

//Set the neighbours up to the 3rd NN.
//:return: NULL
void Structure::cal_neighbours(){
      	for(int i = 0; i < nsites; i++){
		int ix = ixa(i);
		int iy = iya(i);
		int iz = iza(i);

		ia000(i) = cal_index(ix, iy, iz);

		// NN
		ia100(i) = cal_index(ix + 1, iy, iz);
		iai00(i) = cal_index(ix - 1, iy, iz);
		ia010(i) = cal_index(ix, iy + 1, iz);
		ia0i0(i) = cal_index(ix, iy - 1, iz);
		ia001(i) = cal_index(ix, iy, iz + 1);
		ia00i(i) = cal_index(ix, iy, iz - 1);

		// 2nd NN
		// Perpendicular to x-axis
		ia011(i) = cal_index(ix, iy + 1, iz + 1);
		ia0i1(i) = cal_index(ix, iy - 1, iz + 1);
		ia0ii(i) = cal_index(ix, iy - 1, iz - 1);
		ia01i(i) = cal_index(ix, iy + 1, iz - 1);

		// Perpendicular to y-axis
		ia101(i) = cal_index(ix + 1, iy, iz + 1);
		iai01(i) = cal_index(ix - 1, iy, iz + 1);
		iai0i(i) = cal_index(ix - 1, iy, iz - 1);
		ia10i(i) = cal_index(ix + 1, iy, iz - 1);
		
		// Perpendicular to z-axis
		ia110(i) = cal_index(ix + 1, iy + 1, iz);
		iai10(i) = cal_index(ix - 1, iy + 1, iz);
		iaii0(i) = cal_index(ix - 1, iy - 1, iz);
		ia1i0(i) = cal_index(ix + 1, iy - 1, iz);
		
		// 3rd NN
		// Can be easily derived from 2nd NN
		// Here I use perpendicular to shifted z-axis values.
		ia111(i) = cal_index(ix + 1, iy + 1, iz + 1);
		iai11(i) = cal_index(ix - 1, iy + 1, iz + 1);
		iaii1(i) = cal_index(ix - 1, iy - 1, iz + 1);
		ia1i1(i) = cal_index(ix + 1, iy - 1, iz + 1);
		ia11i(i) = cal_index(ix + 1, iy + 1, iz - 1);
		iai1i(i) = cal_index(ix - 1, iy + 1, iz - 1);
		iaiii(i) = cal_index(ix - 1, iy - 1, iz - 1);
		ia1ii(i) = cal_index(ix + 1, iy - 1, iz - 1);
		}
}
