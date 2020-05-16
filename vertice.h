//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_VERTICE_H
#define METROPOLIN_VERTICE_H


class vertice {
private:
    const unsigned int frome;
    const unsigned int to;
    const double length;
    double pollution;

public:
    static unsigned int poll_const;

    vertice(const unsigned int frome, const unsigned int to, const double length);

    void operator++(); // update the pollution

    /*
     * getters and setters
     */
    const unsigned int getFrome() const;

    const unsigned int getTo() const;

    const double getLength() const;

    double getPollution() const;

    void setPollution(double pollution);

};


#endif //METROPOLIN_VERTICE_H
