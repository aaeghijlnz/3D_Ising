//
// Created by Dawei Wang on 2020/6/18.
//

#ifndef INC_3D_ISING_OBSERVER_H
#define INC_3D_ISING_OBSERVER_H

#include <string>

// The interface of observer.
class IObserver {
public:
    virtual ~IObserver(){};
    virtual void Update() = 0;
};

// The interface to for observed subject.
class ISubject {
public:
    virtual ~ISubject(){};
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify() = 0;
};

#endif //INC_3D_ISING_OBSERVER_H
