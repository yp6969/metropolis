//
// Created by Pinhas on 14/05/2020.
//

#include "Metropolis.h"

Metropolis::Metropolis(double** _graph , unsigned int size) : size(size){
    junction = new edge*[size];
    for(unsigned int i=0 ; i<size ; i++){
        junction[i] = new edge(i);
    }
    metro = new graph( _graph , size);
}

Metropolis::~Metropolis() {
    for(int i=0 ; i<size ; i++)
        delete junction[i];
    delete [] junction;
    delete metro;
}

void Metropolis::timeSkip(){
    for(int i=0 ; i<size ; i++){

    }
}



void Metropolis::printPollution(){
    double poll;
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++){
            if( (*metro)(i,j) != NULL ) {
                poll = (*metro)(i, j)->getPollution();
                cout << round(100 * poll) / 100;
            }
            else cout<<"0";
            cout<<(j < (size-1) ? " ":"");
        }
        cout<<endl;
    }
}

