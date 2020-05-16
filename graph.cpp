//
// Created by Pinhas on 14/05/2020.
//

#include "graph.h"

graph::graph(double** graph ,unsigned int size) : size(size) {
    road = new vertice**[size];
    for(int i=0 ; i<size ; i++){
        road[i] = new vertice*[size];
    }

    for(int i=0 ; i<size ; i++)
        for(int j ; j<size ; j++){
            if( graph[i][j] != 0 ){
                road[i][j] = new vertice(i , j , graph[i][j]);
            }
        }
}

graph::~graph(){
    for(int i=0 ; i<size ; i++) {
        for (int j = 0; j < size; j++) {
            delete road[i][j];
        }
        delete [] road[i];
    }
    delete road;
}