#include <iostream>
#include <string>

using namespace std;

void remove(string str){
    size_t pos;
    while((pos = str.find(" ")) != string::npos){
        str.erase(pos, 1);
        str.insert(pos, "%20");
    }
    cout << str << endl;
}

int main(int argc, char** argv){
    string str = "I love  you ";
    remove(str);
    return 0;
}
