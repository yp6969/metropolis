//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_EDGE_H
#define METROPOLIN_EDGE_H
#include "car.h"
#include <cstdlib>
#include <time.h>

class edge {
private:
    const unsigned int id;
    car* carList; // list of cars
    unsigned int* neighbor; // array of id naighbors including me in [0]
    unsigned int number_of_neighbors;

public:
    edge(unsigned int id) : id(id) {}
    ~edge();

    void addCar(car* c); // add car to the end of the list
    car* removeCar();
    int getProbability();
    //void moveCar(unsigned int id);

    /*
     * getters and setters
     */
    const unsigned int getId() const { return id;}
    car* getCarList() const { return carList;}


};


#endif //METROPOLIN_EDGE_H