#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> getNext(string s){
    int len = s.size();
    if(len == 0){
        vector<int> next;
        return next;
    }
    vector<int> next(len);
    next[0] = 0;
    for(int i=1; i<len; i++){
        int k=i;
        while(next[k-1] > 0 && s[next[k-1]] != s[i]){
            k = next[k-1];    
        }
        if(s[next[k-1]] == s[i]){
            next[i] = next[k-1]+1;    
        }else{
            next[i] = 0;    
        }
    }
    return next;
}

bool isSubstring(string str, string sub){
    int lstr = str.size();
    int lsub = sub.size();
    vector<int> next = getNext(sub);
    int j=0;
    int i=0;
    while(i<lstr){
        while(i < lstr && j < lsub){
            if(str[i] != sub[j]){
                if(j == 0){
                    j = 0;    
                    i++;
                }else{
                    j=next[j-1];    
                }
                break;
            }
            i++;
            j++;
        }
        if(j == lsub){
            return true;    
        }
    }
    return false;
}

void print(int n){
    cout << n << " ";        
}

bool rotate(string s1, string s2){
    if(s1.size() != s2.size()){
        return false;    
    }else{
        string s1s1 = s1+s1;
//        if(isSubstring(s1s1, s2)){
        if(strstr(s1s1.data(), s2.data()) != NULL){
            return true;    
        }
        return false;
    }
}
int main(int argc, char* argv[]){
    string str(argv[1]);
    string sub(argv[2]);
    if(rotate(str, sub)){
        cout << "yes";    
    }else{
        cout << "no";
    }
    cout << endl;
    return 0;
}
