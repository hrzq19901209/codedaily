#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(const vector<int>& array, int left, int right){
    int middle = (left+right)/2;
    if(array[middle] >= array[left]){
        if(array[middle] <= array[right]){
            return array[left];    
        }else{
            return min(array, middle+1, right);    
        }
    }else{
        return min(array, left, middle);    
    }
}

void print(int n){
    cout << n << " ";
}
int main(int argc, char** argv){
    int a[7] = {3,4,5,6,7,1,2};
    vector<int> array(a, a+7);
    for_each(array.begin(), array.end(), print);
    cout << "最小值：" << min(array, 0, array.size()-1) << endl;
    return 0;
}
