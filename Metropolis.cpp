//
// Created by Pinhas on 14/05/2020.
//

#include "Metropolis.h"

Metropolis::Metropolis(double** _graph , unsigned int size) : size(size) , num_of_ticks(0){
    junction = new edge*[size];
    for(unsigned int i=0 ; i<size ; i++){
        junction[i] = new edge(i);
    }

}

Metropolis::~Metropolis() {
    for(int i=0 ; i<size ; i++)
        delete junction[i];
    delete [] junction;
    delete metro;
}

void Metropolis::tick(){
    int next;
    for(int i=0 ; i<size ; i++){
        car* head = junction[i]->getCarList();
        while(head || head->get_num_of_move() == num_of_ticks){
            next = junction[i]->getProbability();
            junction[next]->addCar(junction[i]->removeCar());
            (*head)++;
            head->setLocation(next);
            road[i][next]++;
            head = head->next;
        }
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

