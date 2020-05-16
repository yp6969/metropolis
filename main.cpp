#include <iostream>
#include "Metropolis.h"

int main(int argc , char* argv[]) {

    /**
     * open the files .......
     */
    fopen(argv[1] , "r");
    fopen(argv[2] , "r");
    /**
     * check the input ......
     */
    double** _graph = NULL;
    unsigned int size = 3;
    Metropolis* metropolis = new Metropolis( _graph , size);
    for(int i=0 ; i<size ; i++){
        metropolis->getJunction();
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
