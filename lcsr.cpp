#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void lcs(string s1, string s2, int i, int j, string& substr){
    if(i < 0 || j < 0){
        return;    
    }
    if(s1[i] == s2[j]){
        substr.push_back(s1[i]);    
        lcs(s1, s2, i-1,j-1, substr);
    }else{
        string sub1="";
        lcs(s1, s2, i,j-1, sub1);
        string sub2="";
        lcs(s1, s2, i-1,j, sub2);
        string toAppend = sub1.size() > sub2.size() ? sub1 : sub2;
        substr.append(toAppend);
    }
}

int main(int argc, char* argv[]){
    string str1 = "ABCBDAB";        
    string str2 = "BDCABA";
    //string str1 = "1,-1,2,-3,4,-5,6,-7";
    //string str2 = "-7,-5,-3,-1,1,2,4,6";

    string ans="";
    lcs(str1, str2, str1.size()-1, str2.size()-1, ans);
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
