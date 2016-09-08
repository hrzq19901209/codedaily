#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(int argc, char *agrv[]){
    int n, m, x, y, t;
    while(cin >> n >> m >> x >> y >> t){
        vector<vector<double> > grid;
        double ss=0.0;
        for(int i=0; i<n; i++){
            vector<double> vec(m);
            for(int j=0; j<m; j++){
                cin >> vec[j];    
                ss += vec[j];
            }
            grid.push_back(vec);
        }
        double cc = grid[x-1][y-1];
        ss = ss/(n*m);
        
        cc = 1-pow(1-cc, t);
        ss = 1-pow(1-ss, t);

        cout.flags(ios::fixed);
        if( cc > ss){
            cout << "cc" << endl;    
            cout << setprecision(2) << cc << endl;    
        }else if(cc < ss){
            cout << "ss" << endl;    
            cout << setprecision(2) << ss << endl;    
        }else{
            cout << "equal" << endl;    
            cout << setprecision(2) << cc << endl;    
        }
    }
    return 0;
}
