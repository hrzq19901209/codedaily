#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    string s="32";        
    stringstream ss;
    ss << s;
    int a;
    ss >> a;
    cout << a << endl;
    return 0;
}
