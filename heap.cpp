#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//小根堆
void shiftDownLittle(vector<int>& array, int base, int i, int size){
    int val = array[i+base];
    for(int j=2*i; j<size; j = 2*j){
        if(j+1 < size && array[j+base] > array[j+1+base]){
            j++;    
        }
        if(val <= array[j+base]){
            break;
        }else{
            array[i+base] = array[j+base];
            i = j;
        }
    }
    array[i+base] = val;
}

//大根堆
void shiftDownBig(vector<int>& array, int base, int i, int size){
    int val = array[i+base];
    for(int j=2*i; j<size; j=2*j){
        if(j+1 < size && array[j+1+base] > array[j+base]) {
            j++;    
        }   

        if(val >= array[j+base]){
            break;    
        }else{
            array[i+base] = array[j+base];
            i = j;
        }
    }
    array[i+base] = val;
}

void adjustLittle(vector<int>& array, int start, int end){
    int size = end-start;
    for(int i=(size-1)/2; i>=0; i--){
        shiftDownLittle(array, start, i, size);
    }        
}


void adjustBig(vector<int>& array, int start, int end){
    int size = end-start;
    for(int i=(size-1)/2; i>=start; i--){
        shiftDownBig(array, start, i, size);
    }        
}

void print(int n){
    cout << n << " ";        
}

int main(int argc, char **argv){
    int a[6] = {5,1,8,2,8,4};
    vector<int> desc(a, a+6);
    vector<int> asc(a, a+6);
    for_each(desc.begin(), desc.end(), print);
    cout << endl;
    int start = 2;
   for(int end=desc.size(); end>start; end--){
        adjustLittle(desc, start, end);
        int temp = desc[start];
        desc[start] = desc[end-1];
        desc[end-1] = temp;
    }
    for_each(desc.begin(), desc.end(), print);
    cout << endl;
    return 0;
}
