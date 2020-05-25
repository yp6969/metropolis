//
// Created by Pinhas on 14/05/2020.
//

#include "Metropolis.h"

Metropolis::Metropolis(double** _graph , unsigned int size) : size(size) , num_of_ticks(0){
    junction = new edge*[size];

    int cnt_roads = 0 , cnt_neighbors = 0;
    /*
     * create the junctions
     * count number of edges
     */
    for(int i=0 ; i<size ; i++) {
        for (int j = 0; j < size; j++) {
            if (_graph[i][j] != 0){
                cnt_roads++;
                cnt_neighbors++;
            }
        }
        /*
         * init junctions
         */
        junction[i] = new edge(i+1 , cnt_neighbors);
        cnt_neighbors = 0;
    }

    road = new vertice*[cnt_roads];
    num_of_roads = cnt_roads;
    cnt_neighbors = 0;
    cnt_roads = 0;

    /*
     * init roads
     * init neighbors
     */
    for(unsigned int i=0 ; i<size ; i++){
        for(unsigned int j=0 ; j<size ; j++){
            if(_graph[i][j] != 0){
                road[cnt_roads++] = new vertice(i+1 , j+1 , _graph[i][j] );
                junction[i]->setNeighbor( ++cnt_neighbors , j+1);
            }
        }
        cnt_neighbors = 0;
    }
//    for (int k = 0; k < size; k++) {
//        for (int i = 0; i < junction[k]->getNumber_of_neighbors()+1 ; i++) {
//            cout<<(*junction[k])[i]<<" ";
//        }
//        cout<<endl;
//    }
//    junction[0]->addCar(new car(5 ,4));
//    cout<<junction[0]->getCarList()->getId();
//    junction[0]->addCar(new car(56 ,4));
//    cout<<junction[0]->getCarList()->next->getId();
//    junction[0]->addCar(new car(111 ,4));
//    cout<<junction[0]->getCarList()->next->next->getId();
}

/**
 * distractor
 */
Metropolis::~Metropolis() {
    for(int i=0 ; i<size ; i++)
        delete junction[i];
    delete [] junction;

    for(int i=0 ; i<num_of_roads ; i++)
        delete road[i];
    delete [] road;
}

/**
 * create car list for each junction
 * @param cars
 * @return
 */
bool Metropolis::createCarList(ifstream& cars){
    string s;
    int id;
    for (int i = 0; i < size ; ++i) {
        getline(cars , s);
        stringstream sso(s);
        sso>>s; // junk
        //cout<<s<<endl; // print the function id like 1: ....(cars)...
        while(sso>>id){ // insert the car id into varlible
            //cout<<id<<" "; // print it out
            junction[i]->addCar(new car(id, junction[i]->getId())); // add the car
        }
        //cout<<endl;
    }
}

/**
 * stimulate the car exchange with in one unit of time
 */
void Metropolis::tick(){
    int next_id;
    for(int i=0 ; i<size ; i++){
        car* head = junction[i]->getCarList();
        while(head || head->get_num_of_move() == num_of_ticks){
            next_id = junction[i]->getProbability();
            junction[next_id-1]->addCar(junction[i]->removeCar());
            (*head)++; // update the car to know it moved
            head->setLocation(next_id);
            (*getRoad(i+1 , next_id))++; // update the pollution
            head = head->next;
        }
    }
    num_of_ticks++;
}

/**
 * print the pollution metrix
 */
void Metropolis::printPollution(){
    double poll;
    vertice* v;
    for(int i=0 ; i<size ; i++){
        for(int j=0 ; j<size ; j++){
            if( (v = getRoad(i+1,j+1)) != NULL ) {
                poll = v->getPollution();
                cout << round(100 * poll) / 100;
            }
            else cout<<"0";
            cout<<(j < (size-1) ? " ":"");
        }
        cout<<endl;
    }
}

/**
 * print the information about the cars in the junctions
 */
void Metropolis::printCarList(){
    for(int i=0 ; i<size ; i++){
        cout<<junction[i];
    }
}


/**
 *
 * @param from
 * @param to
 * @return the road [from][to]
 */
vertice* Metropolis::getRoad(int from , int to ){
    for(int i=0 ; i<num_of_roads ; i++)
        if(from == road[i]->getFrom() && to == road[i]->getTo()) return road[i];
}

