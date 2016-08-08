#include <iostream>

using namespace std;

void sort(int array[], int size){
    if(array == NULL || size == 0){
        return;    
    }
    int *ages = new int[70](); 
    for(int i=0; i<size; i++){
        ages[array[i]]++;
    }
    for(int i=0; i<70; i++){
        for(int k=0; k<ages[i]; k++){
            cout << i << " ";    
        }    
    }
    cout << endl;
    delete[] ages;
}

int main(int argc, char** argv){
    int a[] = {25,24,26,24,25};
    sort(a, 5);
    return 0;
}
