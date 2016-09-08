#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int getPath(int x, int y){
    if(x <= 1 && y <= 1){
        return 0;    
    }else if(x == 1 || y == 1){
        return 1;    
    }else{
        return getPath(x-1, y)+getPath(x, y-1);    
    }
}

int getPath(int x, int y, vector<vector<int> > grid){
    if((x <= 1 && y <= 1) || grid[x][y] == 1){
        return 0;    
    }else if(x == 1 || y == 1){
        return 1;    
    }else{
        return getPath(x-1, y, grid)+getPath(x, y-1, grid);    
    }
}

int main(int argc, char* agrv[]){
    int n, m, k;
    while(cin >> n >> m >> k){
        vector<vector<int> > grid;
        for(int i=0; i<=n; i++){
            vector<int> vec(m+1, 0);
            grid.push_back(vec);
        }
        int x, y;
        for(int i=0; i<k; i++){
            cin >> x >> y;
            grid[x][y] = 1;   
        }
        int mush = getPath(m,n,grid);
        int total = getPath(m, n);
        cout << setiosflags(ios::fixed) << setprecision(2) << (double)mush/total << endl;
    }
    return 0;
}
