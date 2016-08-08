#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(int a[], int size){
    bool swap = true;
    for(int i=size-1; i>=1; i--){
        if(!swap){
            break;    
        }
        swap = false;
        for(int j=0; j<i-1; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap = true;
            }    
        }
    }
}

void merge(int a[], int lbegin, int lend, int rbegin, int rend, int tmp[]){
    int l=lbegin, r=rbegin;
    int t=lbegin;
    while(l<=lend && r<=rend){
        if(a[l] <= a[r]){
            tmp[t++] = a[l++];    
        }else{
            tmp[t++] = a[r++];    
        }
    }
    if(l <= lend){
        tmp[t++] = a[l++];    
    }
    if(r <= rend){
        tmp[t++] = a[r++];    
    }
    for(int i=lbegin; i<= rend; i++){
        a[i] = tmp[i];    
    }
}

void mergeSort(int a[], int begin, int end, int tmp[]){
    if(begin >= end){
        return;    
    }
    int middle = begin+(end-begin)/2;
    mergeSort(a, begin, middle, tmp);
    mergeSort(a, middle+1, end, tmp);
    merge(a, begin, middle, middle+1, end, tmp);
}

void print(int n){
    cout << n << " ";        
}

int main(){
    int a[]={5,1,8,2,10,2,34};        
    for_each(a, a+7, print);
    cout << endl;
    //bubbleSort(a, 7);
    //for_each(a, a+7, print);
    //cout << endl;
    int *tmp = new int[7]();
    mergeSort(a, 0, 6, tmp);
    for_each(a, a+7, print);
    cout << endl;
    delete[] tmp;
}
