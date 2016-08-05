#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

set<string> permutation(string s){
    set<string> result;
    size_t len = s.size();
    if(len == 1){
        result.insert(s);
        return result;
    }
    string sub(s, 0, len-1);
    set<string> subP = permutation(sub);
    char c = s[len-1];
    set<string>::iterator iter = subP.begin();
    while(iter != subP.end()){
        string element = *iter;
        for(size_t j=0; j<=element.size(); j++){
            string ts = element;
            ts.insert(ts.begin()+j,1,c);
            result.insert(ts);
        }
        iter++;
    }
    return result;
}

void print(string s){
    cout << s << " ";        
}

int main(){
    string s = "abb";
    set<string> ps = permutation(s);
    for_each(ps.begin(), ps.end(), print);
    cout << endl;
    return 0;
}
