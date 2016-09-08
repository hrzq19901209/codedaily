//差数组中的乘机最大的子串
//注意三个值得初始化为1
//意思是空数组的乘积为1
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

double max(double a, double b){
    return a>b ? a:b;        
}

double min(double a, double b){
    return a<b ? a:b;        
}

double maxCJ(double a[], int n){
    vector<double> maxArr(n);
    vector<double> minArr(n);
    maxArr[0] = a[0];
    minArr[0] = a[0];
    double ans = a[0];
    for(int i=1; i<n; i++){
        maxArr[i] = max(max(a[i], maxArr[i-1]*a[i]), minArr[i-1]*a[i]);
        minArr[i] = min(min(a[i], maxArr[i-1]*a[i]), minArr[i-1]*a[i]);
        ans = max(maxArr[i], ans);
    }
    return ans;
}

void print(double n){
    cout << n << " ";
}
int main(int argc, char* argv[]){
    double a[]={-1.1,2.2,-1.1,3.3,-1.1};
    for_each(a, a+sizeof(a)/sizeof(double), print);
    cout << endl;
    cout << maxCJ(a, sizeof(a)/sizeof(double)) << endl;

    double b[] = {-3.2, 5, -1.6, 1, 2.5};
    for_each(b, b+sizeof(b)/sizeof(double), print);
    cout << endl;
    cout << maxCJ(b, sizeof(b)/sizeof(double)) << endl;

    double c[] = {-2.5, 4, 0, 3, 0.5, 8, -1};
    for_each(c, c+sizeof(c)/sizeof(double), print);
    cout << endl;
    cout << maxCJ(c, sizeof(c)/sizeof(double)) << endl;
    return 0;
}
