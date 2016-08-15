#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(int n){
    cout << n << " ";        
}

void selectK(int arr[], int start, int end, int k, vector<int>& result){
    if(start > end){
        return;    
    }
    if(start == end){
        if(start == k){
            result.push_back(arr[start]);    
        }    
        return;
    }
    int x=arr[start];
    int i=start, j=end;
    while(i < j){
        while(i < j && arr[j] >= x){
            j--;    
        }
        if(i < j){
            arr[i++] = arr[j];
        }

        while(i < j && arr[i] < x){
            i++;    
        }
        if(i < j){
            arr[j--] = arr[i];
        }
    }
    arr[i] = x;
    if(i == k){
        result.push_back(x);    
    }else if(i < k){
        selectK(arr, i+1, end, k, result);
    }else{
        selectK(arr, start, i-1, k, result);
    }
}

void topK(int arr[], int start, int end, int k, vector<int>& result){
    if(start > end){
        return;    
    }
    if(start == end){
        if(start == k){
            for(int i=0; i<= k; i++){
                result.push_back(arr[i]);    
            }
        }    
        return;
    }
    int x=arr[start];
    int i=start, j=end;
    while(i < j){
        while(i < j && arr[j] >= x){
            j--;    
        }    
        if(i < j){
            arr[i++] = arr[j];
        }
        while(i < j && arr[i] < x){
            i++;    
        }
        if(i < j){
            arr[j--] = arr[i];
        }
    }
    arr[i] = x;
    if(i == k){
        for(int i=0; i<= k; i++){
            result.push_back(arr[i]);    
        }
    }else if(i < k){
        topK(arr, i+1, end, k, result);
    }else{
        topK(arr, start, i-1, k, result);
    }
}


int main(int argc, char* argv[]){
    int arr[] = {3, 2, 1, 4, 5, 6};
    //int arr[] = {3, 2};
    int k=4;
    vector<int> result;
    selectK(arr, 0, 5, k-1, result);
    if(result.size() == 0){
        cout << "没找到" << endl;    
    }else{
        cout << "第"<< k << "小的数：" << result.back() << endl;
    }
    int arrN[] = {3, 2, 1, 4, 5, 6};
    int kN=4;
    vector<int> resultN;
    topK(arrN, 0, 5, kN-1, resultN);
    cout << "top " << kN << " is:" << endl;
    for_each(resultN.begin(), resultN.end(), print);
    cout << endl;

    return 0;
}
