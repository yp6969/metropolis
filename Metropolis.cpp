//
// Created by Pinhas on 14/05/2020.
//

#include "Metropolis.h"

Metropolis::Metropolis(double** _graph , unsigned int size) : size(size){
    junction = new edge*[size];
    for(unsigned int i=0 ; i<size ; i++){
        junction[i] = new edge(i);
    }
    metro = new graph(_graph , size);
}

Metropolis::~Metropolis() {
    for(int i=0 ; i<size ; i++)
        delete junction[i];
    delete [] junction;
    delete metro;
}
