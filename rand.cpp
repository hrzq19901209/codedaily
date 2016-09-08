#include <iostream>

using namespace std;

int rand10(){
    int x=0;
    do{
        x = (rand7()-1)*7+rand7()   
    }while(x > 40);
    return x/4;
}
