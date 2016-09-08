#include <iostream>
#include <vector>

using namespace std;

enum DIRECTION {
        LEFT, 
        RIGHT, 
        UP, 
        DOWN
} direc;

void move(int begin, int end, int left, int right, int up, int down, vector<vector<int> >& grid){
    direc = DOWN;
    int x=up, y = right;
    while(begin <= end){
        grid[x][y] = begin++;
        switch(direc){
            case DOWN:{
                if(x < down){
                    x++;
                }else{
                    y--;
                    direc = LEFT;
                }
            };break;
            case LEFT:{
                if(y > left){
                    y--;    
                }else{
                    x--;
                    direc = UP;
                }
            };break;
            case UP:{
                if(x > up){
                    x--;    
                }else{
                    y++;
                    direc = RIGHT;
                }
            };break;
            case RIGHT:{
                if(y < right){
                    y++;    
                }
            };break;
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        int nn = n;
        vector<vector<int> > grid(n, vector<int>(n));
        int totalNum = n*n;
        int begin=1,end;
        int left, right=n-1, up=0, down;
        
        while(n > 0){
            if(n != 1){
                end = begin+totalNum-(n-2)*(n-2)-1;
            }else{
                end = begin;    
            }
            left = right-(n-1);
            down = up+(n-1);
            move(begin, end, left, right, up, down, grid);
            n -= 2;;
            totalNum = n*n;
            begin=end+1;
            right--;
            up++;
        }
        for(int i=0; i<nn; i++){
            for(int j=0; j<nn; j++){
                cout << grid[i][j] << " ";
            }    
            cout << endl;
        }
    }
    return 0;
}
