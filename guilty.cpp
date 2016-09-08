#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int n, c, t;
    while(cin >> n >> t >> c){
        vector<int> guiltor(n);
        for(int i=0; i< n; i++){
            cin >> guiltor[i];
        }
        if(c > n){
            continue;    
        }
        int sum = 0;
        for(int i=0; i< c; i++){
            sum += guiltor[i];    
        }
        int count =0;
        if(sum <= t){
            count++;            
        }
        for(int i=c; i<n; i++){
            sum += guiltor[i];
            sum -= guiltor[i-c];
            if(sum <= t){
                count++;            
            }
        }
        cout << count << endl;
    }
    return 0;
}
