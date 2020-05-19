//
// Created by Pinhas on 14/05/2020.
//

#include "edge.h"

void edge::addCar(car* c) {
    car* temp = carList;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = c;
}

car* edge::removeCar(){
    car* temp = carList;
    carList = carList->next;
    temp->next = NULL;
    return temp;
}

int edge::getProbability() {
    srand (time(NULL)); //******* maybe ot side of function
    return neighbor[ rand() % (number_of_neighbors+1)];
}