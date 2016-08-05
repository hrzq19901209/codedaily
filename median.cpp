#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void shiftDownLittle(deque<int> dq, int i, int size){
    int val = dq[i];
    for(int j=2*i; j<size; j = 2*j){
        if(j+1 < size && dq[j+1] < dq[j]){
            j++;    
        }
        if(val <= dq[j]){
            break;    
        }else{
            dq[i] = dq[j];
            i=j;
        }
    }
    dq[i] = val;
}

void shiftDownBig(deque<int> dq, int i, int size){
    int val = dq[i];
    for(int j=2*i; j<size; j=2*j){
        if(j+1 < size && dq[j+1] > dq[j]){
            j++;    
        }   
        if(val >= dq[j]){
            break;    
        }else{
            dq[i] = dq[j];
            i = j;
        }
    }
    dq[i] = val;
}

void adjustLittle(deque<int> dq, int size){
    for(int i=(size-1)/2; i>=0; i--){
        shiftDownLittle(dq, i, size);    
    }        
}

void adjustBig(deque<int> dq, int size){
    for(int i=(size-1)/2; i>=0; i--){
        shiftDownBig(dq, i, size);    
    }        
}

void print(int n){
    cout << n << " ";        
}

int main(){
    int a[] = {3,6,1,8,9,0,2,4,5,7};
    deque<int> minHeap;
    deque<int> maxHeap;
    float median = 0;
    for(int i=0; i<10; i++){
        int minSize = minHeap.size();
        int maxSize = maxHeap.size();
        if(minSize == 0 && maxSize == 0){
            minHeap.push_back(a[i]);    
        }else{
            if(minSize != 0 && maxSize == 0){
                if(a[i]>=minHeap[0]){
                    maxHeap.push_back(a[i]);
                }else{
                    maxHeap.push_back(minHeap[0]);
                    minHeap.pop_front();
                    minHeap.push_back(a[i]);
                }
            }else{
                if(a[i]>= minHeap[0] && a[i]<= maxHeap[0]){
                    if(minSize <= maxSize){
                        minHeap.push_back(a[i]);
                        adjustBig(minHeap, minHeap.size());
                    }else{
                        maxHeap.push_back(a[i]);
                        adjustLittle(maxHeap, maxHeap.size());
                    }
                }else{
                    if(a[i] < minHeap[0]){
                        if(minSize <= maxSize){
                            minHeap.push_back(a[i]);
                            adjustBig(minHeap, minHeap.size());
                        }else{
                            maxHeap.push_back(minHeap[0]);
                            adjustLittle(maxHeap, maxHeap.size());
                            minHeap.pop_front();
                            minHeap.push_back(a[i]);
                            adjustBig(minHeap, minHeap.size());
                        }
                    }else{
                        if(maxSize <= minSize){
                            maxHeap.push_back(a[i]);
                            adjustLittle(maxHeap, maxHeap.size());
                        }else{
                            minHeap.push_back(maxHeap[0]);
                            adjustBig(minHeap, minHeap.size());
                            maxHeap.pop_front();
                            maxHeap.push_back(a[i]);
                            adjustLittle(maxHeap, maxHeap.size());
                        }
                    }  
                }
            }
        }
        if(i == 0){
            continue;        
        }
        minSize = minHeap.size();
        maxSize = maxHeap.size();
        if(minSize != 0 && minSize == maxSize){
            median = (minHeap[0]+maxHeap[0])/2.0;
        }else{
            median = minSize > maxSize ? minHeap[0]:maxHeap[0];
        }
        cout << "较小一半数值的大根堆：";
        for_each(minHeap.begin(), minHeap.end(), print);
        cout << endl;
        cout << "较大一半数值的小根堆：";
        for_each(maxHeap.begin(), maxHeap.end(), print);
        cout << endl;
        cout << "中位数：" << median << endl;
        cout << "---------------------------" << endl;
    }
    return 0;
}
