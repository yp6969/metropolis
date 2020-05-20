#include <string>
#include <fstream>
#include <sstream>
#include "Metropolis.h"
#define MAX_EDGE 500
#define MAX_CARS 10000

void InputError();
bool checkInput(ifstream& metrix , ifstream& cars  , unsigned int& size);
bool creaateMetrix(ifstream& matrix , unsigned int& size);
bool checkCars(ifstream& cars);
bool checkMartixLine(string& str , unsigned int size);
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
    if( !checkInput(matrix , cars , size)) InputError();
    Metropolis* metropolis = new Metropolis( _graph , size);
    for(int i=0 ; i<size ; i++){
        //metropolis->getJunction();
    }


    return 0;
}

/**
 * check and create the matrix
 *
 * @param matrix
 * @param _graph
 * @param size
 * @return
 */

bool creaateMetrix(ifstream& matrix , double** &_graph , int& size) {
    string temp;
    getline(matrix , temp );
    /*
     * check is the first line is an integer
     */
    if( !is_integer(temp)) InputError();
    if((size = atoi(temp.c_str())) > MAX_EDGE ) InputError();

    /*
     * creation of the graph
     */
    _graph = new double*[size];
    for(int i=0 ; i < size ; i++)
        _graph[i] = new double[size];

    for (int i = 0 ; i < size ; i) {
        getline(matrix , temp );
        /*
         * checking each line
         * if not correct return false
         */
        if( !checkMartixLine(temp , size) ) return false;
        stringstream oss(temp);
        for(int j = 0 ; j < size ; j++) {
            oss >> _graph[i][j];
        }
    }
    /*
     * if after finish with matrix ther is stil data
     * there is input error!
     */
    if ( !matrix.eof() ){
        for (int i = 0; i < size ; ++i) {
            delete [] _graph[i];
        }
        delete [] _graph;
        return false;
    }
    return true;
}

/**
 * checking correction of each line
 * @param str
 * @return
 */
bool checkMartixLine(string& str ,unsigned int size){
    string::const_iterator itr = str.begin();
    int cnt = 0;
    while (itr != str.end()){
        if(*itr == ' '){
            if(itr == str.begin() || itr == str.begin()-1 ) return false;
            if( !isdigit(*(itr+1)) || !isdigit(*(itr-1))) return false;
            cnt++;
        }
        else if( !isdigit(*itr) || *itr != '.' ) return false;
        itr++;
    }
    if(cnt != size-1) return false;
    return true;
}

bool checkCars(ifstream& cars){

}

bool checkInput(ifstream& matrix , ifstream& cars  , unsigned int& size){
    return creaateMetrix(matrix , size) && checkCars(cars);
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
