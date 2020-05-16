//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_EDGE_H
#define METROPOLIN_EDGE_H
#include "car.h"

class edge {
private:
    const unsigned int id;
    car* carList;

public:
    edge(unsigned int id);
    ~edge();

    void addCar(unsigned int id);

    /*
     * getters and setters
     */
    const unsigned int getId() const { return id;}


};


#endif //METROPOLIN_EDGE_H