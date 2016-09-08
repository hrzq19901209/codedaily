#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    int n = 9;
    const int *a = &n;
    int const *b = &n;
    int * const c = &n;
    *c = 9;
    return 0;
}
