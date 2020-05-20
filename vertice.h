//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_VERTICE_H
#define METROPOLIN_VERTICE_H
#include <cstdio>

class vertice {
private:
    const unsigned int from;
    const unsigned int to;
    const double length;
    double pollution;

public:
    static double poll_const;

    vertice(const unsigned int from, const unsigned int to, const double length);

    void operator++(int){ pollution += poll_const/length;} // update the pollution


    /*
     * getters and setters
     */
    const unsigned int getFrom() const;

    const unsigned int getTo() const;

    const double getLength() const;

    double getPollution() const;

    void setPollution(double pollution);

};


#endif //METROPOLIN_VERTICE_H
