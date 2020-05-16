//
// Created by Pinhas on 14/05/2020.
//

#include "edge.h"

edge::edge(unsigned int id) : id(id) {}
edge::~edge(){}


void edge::addCar(unsigned int id) {
    car* temp = new car(id , this->id);
    temp->next = carList;
    carList->prev = temp;
    carList = temp;
}