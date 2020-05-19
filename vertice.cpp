//

#include "vertice.h"

//
// Created by Pinhas on 14/05/2020.

vertice::vertice(const unsigned int from, const unsigned int to, const double length) :
from(from),
to(to),
length(length),
pollution(0) {}

const unsigned int vertice::getFrom() const {return from;}

const unsigned int vertice::getTo() const {return to;}

const double vertice::getLength() const {return length;}

double vertice::getPollution() const {return pollution;}

void vertice::setPollution(double pollution) {this->pollution = pollution;}
