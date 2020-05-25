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
    unsigned int number_of_neighbors;
    unsigned int* neighbor; // array of id naighbors including me in [0]
    car* carList; // list of cars


public:
    edge(unsigned int id , unsigned int number_of_neighbors);
    ~edge();

    void addCar(car* c); // add car to the end of the list
    car* removeCar();
    int getProbability();
    friend ostream& operator<<(ostream& out , edge& junction );
    unsigned int& operator[](int i){ return neighbor[i];}
    //void moveCar(unsigned int id);

    /*
     * getters and setters
     */
    const unsigned int getId() const { return id;}
    const unsigned int getNumber_of_neighbors() const { return number_of_neighbors;}
    void setNeighbor(int i , unsigned int id){ neighbor[i] = id;}
    car* getCarList() const { return carList;}


};


#endif //METROPOLIN_EDGE_H