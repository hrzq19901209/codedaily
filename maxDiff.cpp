//数对之差的最大值
#include <iostream>
#include <vector>
#include <limits.h>

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

int main(){
    int a[] = {2, 4, 1, 16, 7, 5, 11, 9};
    vector<int> array(a, a+8);
    int result = maxDiff(array, 0, array.size()-1);
    cout << result << endl;

    int max_, min_;
    result = maxDiff(a, a+7, &max_, &min_);
    cout << max_ << " " << min_ << endl;
    cout << result << endl;
    return 0;
}
