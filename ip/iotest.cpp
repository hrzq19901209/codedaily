#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define N 32
#define FILEINDEX(x) x>>27
#define INDEX(x) x&0x07ffffff
#define VALUE(index,val) index<<27|val 
#define LEN 128*1024*1024

using namespace std;

void makeData(const int& n){
    ofstream outfile("ip.data", ios::out | ios::binary);
    srand((unsigned)(time(NULL)));
    if(outfile){
        for(int i=0; i<n; i++){
            unsigned ip = unsigned(rand());
            ip = (ip<<24) | ip;
            outfile.write((char *)&ip, sizeof(unsigned));
        }
        outfile.close();
    }
}

int main(int argc, char* argv[]){
    makeData(100000000);
    fstream files[N];
    for(int i=0; i<N; i++){
        char path[128];
        sprintf(path, "ip%d.data", i);
        files[i].open(path, ios::trunc | ios::in | ios::out | ios::binary);
    }

    ifstream infile("ip.data", ios::in | ios::binary);
    unsigned ip;
    while(infile.read((char *)&ip, sizeof(unsigned))){
        int fileIndex = FILEINDEX(ip);
        unsigned val = INDEX(ip);
        files[fileIndex].write((char *)&val, sizeof(unsigned));
    }

    for(int i=0; i<N; i++){
        files[i].seekg(0);    
    }
    unsigned targetIp;
    unsigned count=0;
    unsigned *ips = new unsigned[LEN]();
    for(int i=0; i<N; i++){
        unsigned val;
        while(files[i].read((char *)&val, sizeof(unsigned))){
            ips[val]++;    
        }
        for(int j=0; j<LEN; j++){
            if(ips[j] > count){
                count = ips[j];
                targetIp = VALUE(i, ips[j]);
            }    
        }
        memset(ips, 0, sizeof(unsigned)*LEN);
    }
    delete[] ips;
    cout << targetIp << endl;
    unsigned char* result = (unsigned char*)(&targetIp);
    printf("出现次数最多的 IP 为:%d.%d.%d.%d,共出现%d 次\n",
    result[0], result[1], result[2], result[3], count);

    return 0;
}
