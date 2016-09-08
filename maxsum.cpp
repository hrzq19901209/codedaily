#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int maxsum(int a[], int n, int* start, int *end){
    if(n < 1){
        exit(1);    
    }
    int max = a[0];
    int current = a[0];
    int cstart = 0;
    int cend = 0;
    *start = cstart;
    *end = cend;
    for(int i=1; i<n; i++){
        if(current > 0){
            current += a[i];    
            cend++;
        }else{
            current = a[i];
            cstart = i;
            cend = i;
        }
        if(current > max){
            max = current;
            *start = cstart;
            *end = cend;
        }
    }
    return max;
}

void print(int i){
    cout << i << " ";
}
int main(int argc, char* argv[]){
    int a[] = {-10, -2, -3, -10, -4, -7, -2, -5};
    //int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
    for_each(a, a+8, print);
    cout << endl;
    int start, end;
    cout << maxsum(a, 8, &start, &end) << endl;
    cout << "start:" << start << " end:"<< end << endl;
    for_each(a+start, a+end+1, print);
    cout << endl;
    return 0;
}
