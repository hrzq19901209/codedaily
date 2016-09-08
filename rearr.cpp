#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> array(n);
        for(int i=0; i<n; i++){
            cin >> array[i];    
        }
        int begin=0;
        int end=0;
        for(int i=0; i<n-1; i++){
            if(array[i] > array[i+1]){
                begin = i;    
                break;
            }    
        }

        end = begin;
        for(int i=begin; i<n-1; i++){
            if(array[i] > array[i+1]){
                end++;    
            }else{
                break;    
            }
        }
        int temp;
        while(begin < end){
            temp = array[begin];
            array[begin] = array[end];
            array[end] = temp;
            begin++;
            end--;
        }
        int i;
        for(i=0; i<n-1; i++){
            if(array[i] > array[i+1]){
                break;
            }    
        }
        if(i < n-1){
            cout << "no" << endl;    
        }else{
            cout << "yes" << endl;    
        }
    }
    return 0;
}
