#include <string>
#include <fstream>
#include "Metropolis.h"

int main(int argc , char* argv[]) {

    /**
     * open the files .......
     */
    ifstream matrix(argv[1] );
    ifstream cars(argv[2]);
    if(!matrix || !cars){

    }
    /**
     * check the input ......
     */
    double** _graph = NULL;
    unsigned int size ;
    Metropolis* metropolis = new Metropolis( _graph , size);
    for(int i=0 ; i<size ; i++){
        metropolis->getJunction();
    }


    return 0;
}

bool checkMetrix(ifstream metrix , int& size) {
    string temp ;
    getline(metrix , temp);
}
bool checkCars(ifstream cars){

}

bool checkInput(ifstream metrix , ifstream cars  , int& size){
    return checkMetrix(metrix , size) && checkCars(cars) ;
}
