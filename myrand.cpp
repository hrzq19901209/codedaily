#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int myRand(){
    int pick=0;
    srand((unsigned int)time(NULL));
    for(int i=1; i<=10; i++){
        if(rand()%i == 0){
            pick =i;    
        }
    }
    
    return pick;
}

int main(int argc, char* argv[]){
    for(int i=0; i<10; i++){
        cout << myRand() << endl;    
        //sleep(1);
    }
    return 0;
}
