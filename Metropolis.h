//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_METROPOLIS_H
#define METROPOLIN_METROPOLIS_H
#include <iostream>
#include <cmath>
#include "edge.h"
#include "graph.h"
using namespace std;

class Metropolis {
private:
    const unsigned int size;
    unsigned int num_of_ticks;
    edge** junction;
    vertice** road;

public:
    Metropolis(double** graph , unsigned int size);
    ~Metropolis();

    void tick(); //iterate time skip

    void printPollution();
    /*
     * getters and setters
     */
    const unsigned int getSize() const { return size;}
    edge& getJunction(int id) const{ return *junction[id];}
};


#endif //METROPOLIN_METROPOLIS_H
