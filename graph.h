//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_GRAPH_H
#define METROPOLIN_GRAPH_H
#include "vertice.h"

class graph {
private:
    const unsigned int size;
    vertice*** road;

public:

    graph(double** graph , unsigned int size);
    ~graph();

};


#endif //METROPOLIN_GRAPH_H
