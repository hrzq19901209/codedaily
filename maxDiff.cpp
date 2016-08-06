//数对之差的最大值
#include <iostream>
#include <vector>
#include <limits.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

static inline
int max(int a, int b){
    return a>b ? a:b;        
}

static inline
int min(int a, int b){
    return a<b ? a:b;        
}
//自己的，用循环去找最大值，最小值，不好
int maxDiff(const vector<int>&array, int begin, int end){
    if(begin >= end){
        return INT_MIN;    
    }else{
        int middle = begin+(end-begin)/2;
        int leftMax = array[begin];
        int rightMin = array[middle+1];
        for(int i=begin; i<=middle; i++){
            if(array[i] > leftMax){
                leftMax = array[i];    
            }
        }
        for(int i=middle+1; i<=end; i++){
            if(array[i] < rightMin){
                rightMin = array[i];    
            }    
        }
        int diffMiddle = leftMax-rightMin;
        int diffLeft = maxDiff(array, begin, middle);
        int diffRight = maxDiff(array, middle+1, end);
        int result = max(diffMiddle, diffLeft);
        result = max(result, diffRight);
        return result;
    }
}

//别人的，没用循环去找最大值，最小值没有用循环，用的是递归，这种通过指针求值得方式就是深度遍历是引用的用法
//分治法，因为取中间位置，结果可能出现在左边，也可能出现在右边，也可能是左边的最大值减去右边的最小值
int maxDiff(int *start, int *end, int *max_, int *min_){
    if(start == end){
        *min_ = *max_ = *start;
        return INT_MIN;
    }else{
        int *middle = start+(end-start)/2;

        int leftMax, leftMin;
        int leftDiff = maxDiff(start, middle, &leftMax, &leftMin);

        int rightMax, rightMin;
        int rightDiff = maxDiff(middle+1, end, &rightMax, &rightMin);
        
        *max_ = max(leftMax, rightMax);
        *min_ = min(leftMin, rightMin);

        int result = max(leftDiff, rightDiff);

        return max(result, leftMax-rightMin);
    }
}
//假设最大的数值差由i, j指出
//(a[i]-a[j]) = (a[i]-a[i+1]) + (a[i+1]-a[i+2]) +....+(a[j-1]-a[j])
//所以将a数组转换成上面准话你后的,结果转换成求数组连续子数组的最大值问题
int maxSequence(int array[], int size, int* start, int *end){
    int result = array[0];
    int current = array[0];
    int cstart = 0,  cend = 0;
    for(int i=1; i<size; i++){
        if(current>0){
            current += array[i];
            cend = i;
        }else{
            current = array[i];
            cstart = i;
            cend = i;
        }
        if(current > result){
            result = current;
            *start = cstart;
            *end = cend;
        }
    }
    return result;
}
//通过动态数组直接求解，这样就不需要再分配空间了
//实现方法， 改动上面的函数即可
int maxDiff(int* array, int size, int* start, int* end){
    int result = array[0]-array[1];
    int current = result;
    int cstart=0, cend=1;
    int diff=0;
    for(int i=1; i<size-1; i++){
        diff = array[i]-array[i+1];
        if(current > 0){
            current += diff;
            cend = i+1;
        }else{
            current = diff;
            cstart = i;
            cend = i;
        }
        if(current > result){
            result = current;    
            *start = cstart;
            *end = cend;
        }
    }
    return result;
}

void print(int n){
    cout << n << " ";        
}

int main(){
    int a[] = {2, 4, 1, 16, 7, 5, 11, 9};
    for_each(a, a+8, print);
    vector<int> array(a, a+8);
    int result = maxDiff(array, 0, array.size()-1);
    cout << result << endl;

    int max_, min_;
    result = maxDiff(a, a+7, &max_, &min_);
    cout << max_ << " " << min_ << endl;
    cout << result << endl;
    int *b = new int[7]();
    for(int i=0; i<7; i++){
        b[i] = a[i]-a[i+1];   
    }
    int start, end;
    cout << "最大差:" << maxSequence(b, 7, &start, &end) << endl;
    cout << "start:" << start << "   end:" << end+1 << endl;
    delete[] b;

    cout << "最大差:" << maxDiff(a, 8 , &start, &end) << endl;
    cout << "start:" << start << "   end:" << end << endl;
    return 0;
}
