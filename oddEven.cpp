#include <iostream>
#include <algorithm>

using namespace std;

void swap(int arr[], int n){
    int i=0, j=n-1;
    while(i<j){
        while(i<j && arr[j] > 0){
            j--;    
        }
        while(i<j && arr[i] < 0){
            i++;    
        }
        if(i<j){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
}

void print(int n){
    cout << n << " ";        
}

int main(int argc, char* argv[]){
    int arr[] = {1, 7, -5, 9, -12, 15};
    swap(arr, 6);
    for_each(arr, arr+6, print);
    cout << endl;
    return 0;
}
