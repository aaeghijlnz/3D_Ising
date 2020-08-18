#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include <functional>

class Structure {
  public:
    int cal_index(int, int, int);//return the real ia(ix,iy,iz)
    void cal_neighbours();
    void set_supercell(const double lattice[3][3]);
    int cal_xyz(int i);
    int cal_distance(int i , int j);
    //void get_volume(void);
    //void print_neighbours(int ix,int iy,int iz);
    void print_a();

  public:
    
    Structure(const double lattice[3][3],int n1, int n2, int n3) :
	    nx{n1}, ny{n2}, nz{n3},
	    nxy{n1*n2}, nsites{n1*n2*n3},
	    ix{xt::zeros<int>({nxy})},
	    iy{xt::zeros<int>({nxy})},
	    
	    site{xt::zeros<int>({nx, ny})},
	    
	    iaa{xt::zeros<int>({nx,ny,nz})},
	    
	    ixa{xt::zeros<int>({nsites})},
	    iya{xt::zeros<int>({nsites})},
	    iza{xt::zeros<int>({nsites})},
	    
	    ia000{xt::zeros<double>({nsites})},
      
	    //NN
	    ia100{xt::zeros<int>({nsites})},
	    iai00{xt::zeros<int>({nsites})},
	    ia010{xt::zeros<int>({nsites})},
	    ia0i0{xt::zeros<int>({nsites})},
	    ia001{xt::zeros<int>({nsites})},
	    ia00i{xt::zeros<int>({nsites})},

	    //2nd NN
	    //perpendicular to x-axis
      	    ia011{xt::zeros<int>({nsites})},
	    ia0i1{xt::zeros<int>({nsites})},
	    ia0ii{xt::zeros<int>({nsites})},
	    ia01i{xt::zeros<int>({nsites})},

	    //perpendicular to y-axis
	    ia101{xt::zeros<int>({nsites})},
	    iai01{xt::zeros<int>({nsites})},
	    ia10i{xt::zeros<int>({nsites})},
	    iai0i{xt::zeros<int>({nsites})},

      
	    //erpendicular to z-axis
	    ia110{xt::zeros<int>({nsites})},
	    ia1i0{xt::zeros<int>({nsites})},
	    iai10{xt::zeros<int>({nsites})},
	    iaii0{xt::zeros<int>({nsites})},


      
	    //3rd NN
	    ia111{xt::zeros<int>({nsites})},
	    iai11{xt::zeros<int>({nsites})},
	    iaii1{xt::zeros<int>({nsites})},
	    ia1i1{xt::zeros<int>({nsites})},
	    ia11i{xt::zeros<int>({nsites})},
	    iai1i{xt::zeros<int>({nsites})},
	    iaiii{xt::zeros<int>({nsites})},
	    ia1ii{xt::zeros<int>({nsites})},

      
	    //Lattice vector (Bravais vector)
	    a{xt::zeros<int>({3,3})},
	    b{xt::zeros<int>({3,3})},
	    xyz{xt::zeros<int>({3})}
    {
	    set_supercell(lattice);
	    cal_neighbours();
    }

    //the supercell where the ising dipoles are
    //
    //nx etc are the number of cells about spin

    int nx;
    int ny;
    int nz;
    int nxy;
    int nsites; 

    xt::xarray<int> iaa;
    xt::xarray<int> ix;
    xt::xarray<int> iy;
    xt::xarray<int> site;
    xt::xarray<int> a;
    xt::xarray<int> b;
    xt::xarray<int> xyz;
    //Up to third neighbours, a total of 27 arrays.
    //'i' means -1 in the indices.
    //self
    xt::xarray<int> ia000;
    xt::xarray<int> ixa;
    xt::xarray<int> iya;
    xt::xarray<int> iza;

    //NN
    xt::xarray<int> ia100;
    xt::xarray<int> iai00;
    xt::xarray<int> ia010;
    xt::xarray<int> ia0i0;
    xt::xarray<int> ia001;
    xt::xarray<int> ia00i;

    //2nd NN
    //erpendicular to x-axis
    xt::xarray<int> ia011;
    xt::xarray<int> ia0i1;
    xt::xarray<int> ia0ii;
    xt::xarray<int> ia01i;
    //erpendicular to y-axis
    xt::xarray<int> ia101;
    xt::xarray<int> iai01;
    xt::xarray<int> ia10i;
    xt::xarray<int> iai0i;
    //erpendicular to z-axis
    xt::xarray<int> ia110;
    xt::xarray<int> ia1i0;
    xt::xarray<int> iai10;
    xt::xarray<int> iaii0;

    //3rd NN
    xt::xarray<int> ia111;
    xt::xarray<int> iai11;
    xt::xarray<int> iaii1;
    xt::xarray<int> ia1i1;
    xt::xarray<int> ia11i;
    xt::xarray<int> iai1i;
    xt::xarray<int> iaiii;
    xt::xarray<int> ia1ii;
};

#endif //STRUCTURE_H
