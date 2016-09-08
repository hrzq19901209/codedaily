#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    int n;
    while(cin >> n){
        int x,y;
        int minX, minY;
        int maxX, maxY;
        cin >> minX >> minY;
        maxX = minX;
        maxY = minY;
        for(int i=1; i< n;i++){
            cin >> x >> y;
            if(x < minX){
                minX = x;    
            }else if(x > maxX){
                maxX = x;    
            }

            if(y < minY){
                minY = y;    
            }else if(y > maxY){
                maxY = y;    
            }
        }

        int border = maxX-minX > maxY-minY ? maxX-minX : maxY-minY;
        cout << border*border << endl;
    }
    return 0;
}
