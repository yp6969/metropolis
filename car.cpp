//
// Created by Pinhas on 14/05/2020.
//

#include "car.h"

car::car(int id , int location) : id(id) , location(location) {}

//car::car(car& c) : id(c.id) , location(){}

const unsigned int car::getId() const {
    return id;
}

int car::getLocation() const {
    return location;
}

void car::setLocation(int location) {
    car::location = location;
}