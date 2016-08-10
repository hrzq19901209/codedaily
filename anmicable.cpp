//求亲和书，结合和的原理是这样的，以2为例，能被2整除的数有4，6，8分别为2+2,2+2*2,2+2*3，
//所以2遍历sum数组，让所有能整除它的数加上2，就是能整除2的都加上2这个质因子
//判断的时候sum[i] > i是为了去重，sum[sum[i]] = i是根据亲和数的定义做判断
#include <iostream>

using namespace std;

int sum[5000010];

void amicable(){
    for(int i=1; i<=5000000; i++){
        sum[i] = 1;   
    }         
    for(int i=2; i+i <=5000000; i++){
        int j=i+i;
        while(j <= 5000000){
            sum[j] += i;
            j += i;
        }
    }

    for(int i=1; i<= 5000000; i++){
        if(sum[i] > i && sum[i] <= 5000000 && sum[sum[i]] == i){
            cout << i << " " << sum[i] << endl;    
        }    
    }
}

int main(int argc, char* argv[]){
    amicable();
    return 0;
}
