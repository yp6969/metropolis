//

#include "vertice.h"

//
// Created by Pinhas on 14/05/2020.

vertice::vertice(const unsigned int frome, const unsigned int to, const double length) :
frome(frome),
to(to),
length(length),
pollution(0) {}

void vertice::operator++(){
    pollution += poll_const/length;
}

const unsigned int vertice::getFrome() const {
    return frome;
}

const unsigned int vertice::getTo() const {
    return to;
}

const double vertice::getLength() const {
    return length;
}

double vertice::getPollution() const {
    return pollution;
}

void vertice::setPollution(double pollution) {
    vertice::pollution = pollution;
}
