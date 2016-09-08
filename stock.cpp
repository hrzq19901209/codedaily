#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 1){
            cout << 1 << endl;    
            continue;
        }
        int stock = 1;
        int peak = 2;
        int up=2;
        int i=2;
        while(i<=n){
            i++;
            if(stock < peak){
                stock++;    
            }else{
                stock--;
                peak = stock+up;
                up++;
            }
        }
        cout << stock << endl;
    }
    return 0;
}
