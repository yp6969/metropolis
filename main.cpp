#include <string>
#include "Metropolis.h"
#define MAX_EDGE 500
#define MAX_CARS 10000

void InputError();
//bool checkInput(ifstream& metrix , ifstream& cars , double** &_graph , unsigned int& size);
bool createMatrix(ifstream& matrix ,  double** &_graph , unsigned int& size);
//bool checkCars(ifstream& cars);
bool checkMatrixLine(string& str , unsigned int size);
bool is_integer(const string& s);

double poll_const;

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
    unsigned int size = 9;

    double** _graph = new double*[size];
    for (int k = 0; k < size; ++k) {
        _graph[k] = new double [size];
    }

    createMatrix(matrix , _graph , size );
    Metropolis* metropolis = new Metropolis( _graph , size);
    metropolis->createCarList(cars);
    metropolis->printCarList();

    return 0;
}

/**
 * create the graph
 * @param matrix
 * @param _graph
 * @param size
 * @return
 */
bool createMatrix(ifstream& matrix ,  double** &_graph , unsigned int& size){
    string s;
    getline(matrix , s);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix>>_graph[i][j];
        }
    }
}

/**
 * exit if the input is not correct
 */
void InputError(){
    cerr<<"ERROR: Invaild input."<<endl;
    exit(0);
}

/**
 * chek if the number is an integer
 * @param s
 * @return
 */
bool is_integer(const string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool checkMatrix(ifstream& matrix , unsigned int& size){
    string s;
    getline(matrix , s);
    if(!is_integer(s)) return false;
    size = atoi(s.c_str());
    for (int i = 0; i < size ; ++i) {
        for (int j = 0; j < size ; ++j) {

        }
    }
}


