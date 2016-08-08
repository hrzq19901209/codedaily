#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int numOf2(int n){
    vector<int> preResult;
    preResult.push_back(0);
    preResult.push_back(1);
    for(int i=2; i<=n; i++){
        preResult.push_back(preResult[i/2]+i%2);    
    }
    int sum = accumulate(preResult.begin()+1, preResult.end(), 0);
    return sum;
}

int numOf10(int n){
    vector<int> preResult;
    preResult.push_back(0);
    preResult.push_back(1);
    for(int i=2; i<=n; i++){
        preResult.push_back(preResult[i/10]+(i%10==1?1:0));    
    }
    int sum = accumulate(preResult.begin()+1, preResult.end(), 0);
    return sum;
}


int main(int argc, char **argv){
    cout << "统计二进制中还有的1的个数和:" << numOf2(7) << endl;
    cout << "统计十进制中还有的1的个数和:" << numOf10(12) << endl;
    return 0;
}
