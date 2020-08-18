//
// Created by Dawei Wang on 2020/5/8.
//
#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include <functional>
#include<gsl/gsl_rng.h>

#include "structure.h"
#include "parameters.h"
#include "observer.h"

class System : public ISubject {
public:
    System(Structure s):
            structure{s},
            natoms{s.nsites}
    {
        gsl_rng_env_setup();
        rng_type = gsl_rng_default;
        r = gsl_rng_alloc (rng_type);
        par.set_parameters();
    }

    ~System(){}

    virtual void loop() = 0;
    virtual double set_1_kT() = 0;
    virtual double get_average() = 0;
    virtual double spins_total() = 0;
    virtual int positive_total() = 0;
    virtual int negative_total() = 0;
//  virtual double spin_information(int i) = 0;
    int get_atoms();
    Parameters par;
    virtual double T()=0;
    int natoms;
    const gsl_rng_type * rng_type;
    gsl_rng * r;
    Structure structure;

    /**
    * The following are for the observers.
   */

    /**
   * The subscription management methods.
   */
    void Attach(IObserver *observer) override {
        list_observer_.push_back(observer);
    }
    void Detach(IObserver *observer) override {
        list_observer_.remove(observer);
    }
    void Notify() override {
        std::list<IObserver *>::iterator iterator = list_observer_.begin();
        //HowManyObserver();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update();
            ++iterator;
        }
    }

    void HowManyObserver() {
        std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
    }

    /**
     * Usually, the subscription logic is only a fraction of what a Subject can
     * really do. Subjects commonly hold some important business logic, that
     * triggers a notification method whenever something important is about to
     * happen (or after it).
     */
    void SomeBusinessLogic() {
        this->message_ = "change message message";
        Notify();
        std::cout << "I'm about to do some thing important\n";
    }

private:
    std::list<IObserver *> list_observer_;
    std::string message_;

};

#endif
