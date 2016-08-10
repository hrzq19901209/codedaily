//差数组中的乘机最大的子串
//注意三个值得初始化为1
//意思是空数组的乘积为1
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

double maxCJ(double a[], int n){
    double maxProduct = 1;
    double minCurrent = 1;
    double maxCurrent = 1;
    for(int i=0; i<n; i++){
        if(a[i] > 0){
            maxProduct *= a[i];
            minCurrent *= a[i];
            if(maxCurrent > maxProduct){
                maxProduct = maxCurrent;    
            }
        }else if(a[i] < 0){
            double temp = minCurrent;
            minCurrent = maxCurrent*a[i]; 
            maxCurrent = temp*a[i];
            if(maxCurrent > maxProduct){
                maxProduct = maxCurrent;    
            }
        }else{
            if(0 > maxProduct){
                maxProduct = 0;    
            }

            maxProduct = 1;
            minCurrent = 1;
        }
    }
    return maxProduct;
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
