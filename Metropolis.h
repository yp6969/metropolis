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
    edge** junction;
    graph* metro;

public:
    Metropolis(double** graph , unsigned int size);
    ~Metropolis();

    void timeSkip();

    void printPollution();
    /*
     * getters and setters
     */
    const unsigned int getSize() const { return size;}
    edge& getJunction(int id) const{ return *junction[id];}
    //void setJunction(edge **junction);
    graph& getMetro() const{ return *metro;}
    //void setMetro(graph *metro);
};


#endif //METROPOLIN_METROPOLIS_H
