//
// Created by Pinhas on 14/05/2020.
//

#ifndef METROPOLIN_CAR_H
#define METROPOLIN_CAR_H


class car {
private:
    const unsigned int id;
    int location;

public:
    car* next;
    car* prev;

    car(int id , int location);
    car(car& c);


    /*
     * getters setters
     */
    int getLocation() const;
    void setLocation(int location);
    const unsigned int getId() const;
};


#endif //METROPOLIN_CAR_H
