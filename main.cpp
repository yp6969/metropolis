#include <string>
#include <fstream>
#include "Metropolis.h"
#define MAX_EDGE 500
#define MAX_CARS 10000

void InputError();
bool checkInput(ifstream& metrix , ifstream& cars  , int& size);
bool checkMetrix(ifstream& matrix , int& size);
bool checkCars(ifstream& cars);
bool is_integer(const string& s);


int main(int argc , char* argv[]) {

    /**
     * open the files .......
     */
    ifstream matrix(argv[1] );
    ifstream cars(argv[2]);
    if(!matrix || !cars){
        InputError();
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

bool checkMetrix(ifstream& matrix , int& size) {
    string temp;
    getline(matrix , temp );
    /*
     * check is the first line is an integer
     */
    if( !is_integer(temp)) InputError();
    if((size = atoi(temp.c_str())) > MAX_EDGE ) InputError();

}
bool checkCars(ifstream& cars){

}

bool checkInput(ifstream& matrix , ifstream& cars  , int& size){
    return checkMetrix(matrix , size) && checkCars(cars) ;
}

/**
 * exit if the input is not correct
 */
void InputError(){
    cerr<<"ERROR: Invaild input."<<endl;
    exit(0);
}

bool is_integer(const string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
