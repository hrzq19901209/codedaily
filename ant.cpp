#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    int length = 27;
    int pos[] = {3, 7, 11, 17, 23};
    int min=0, max =0;
    int left,right;
    for(int i=0; i<5; i++){
        left = pos[i];
        right = length - pos[i];
        if(left < right){
            min += left;
            max += right;
        }else{
            min += right;
            max += left;
        }
    }
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    return 0;
}
