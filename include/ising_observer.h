//
// Created by Dawei Wang on 2020/6/18.
//

#ifndef INC_3D_ISING_ISING_OBSERVER_H
#define INC_3D_ISING_ISING_OBSERVER_H

#include <vector>
#include <netcdfcpp.h>
#include "observer.h"
#include "system.h"

class Ising_observer : public IObserver {
    //This observer is for the total dipole, i.e., the sum of all ising dipoles.
public:
    Ising_observer(System &subject) : subject_(subject) {
        this->subject_.Attach(this);
    }

    virtual ~Ising_observer() {
        std::cout << "Goodbye, I was the Ising_observer, called \"" << this->number_ << "\" times.\n";
    }

    void Update();

    void RemoveMeFromTheList() {
        subject_.Detach(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }

    void print_info();

private:
    System &subject_;
    int number_;
    std::vector<double> average;
};

#endif //INC_3D_ISING_ISING_OBSERVER_H
