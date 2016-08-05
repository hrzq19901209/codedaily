//使用大根堆和小根堆
//用遍历数组模拟数组的动态增加
//创建一个双端队列表示堆
//大根对存放当前数组中较小的那半部分数
//小根堆存放当前数组中较大的那半部分数
//因此，两个堆得根节点即为median的候选
//数组扩容时，根据新增数值的大小与两个堆当前的大小插入到大、小根堆中
//新增的值如果小于大根堆得根，则它必须插入大根堆。如果大根对当前的大小小于等于小根堆，则直接插入，调整大根堆，否则先弹出大根对的跟，插入到小根堆，调整小根堆，然后将新增值插入大根堆，调整大根堆
//新增的值大于小根堆的根，与上述类似
//否则，插入到节点较少的那个堆里面，调整对应的堆
//时间复杂度为n*log(n)

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void shiftDownLittle(deque<int> dq, int i, int size){//调整小根堆
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

void shiftDownBig(deque<int> dq, int i, int size){//调整大跟堆
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

void adjustLittle(deque<int> dq, int size){//创建小根堆
    for(int i=(size-1)/2; i>=0; i--){
        shiftDownLittle(dq, i, size);    
    }        
}

void adjustBig(deque<int> dq, int size){//创建大根堆
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
        if(i == 0){//由于i=0,说明目前只有一个数值，中位数就是当前的数，但是为了显示效果的方便，不显示这一步的结果
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
