#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    string word;
    int count;
    Node(string w="", int c=0):word(w),count(c){}
};

//小根堆
void shiftDown(Node arr[], int i, int size){
    Node x = arr[i];
    for(int j=2*i; j<size; j=2*j){
        if(j+1 < size && arr[j+1].count < arr[j].count){
            j++;
        }    
        if(x.count <= arr[j].count){
            break;
        }else{
            arr[i] = arr[j];
            i = j;
        }
    }
    arr[i] = x;
}

//调整堆
void adjust(Node arr[], int size){
    for(int i=(size-1)/2; i>= 0; i--){
        shiftDown(arr, i, size);    
    }        
}

map<string, int> getMap(){
    map<string, int> res;
    FILE *fd = fopen("log.txt", "r");
    char buf[256];
    while(fscanf(fd, "%s", buf) != EOF){
        string word(buf);
        if(res.find(word) == res.end()){
            res[word] = 1;    
        }else{
            res[word] += 1;    
        }
    }
    return res;
}

void print(pair<string, int> p){
    cout << p.first << " " << p.second << endl;        
}

void topN(Node arr[], int size){
    map<string, int> wordHash = getMap();
    int len = wordHash.size();
    map<string, int>::iterator iter = wordHash.begin();
    int index = 0;
    while(iter != wordHash.end()){
        if(index >= size){
            break;    
        }
        Node node(iter->first, iter->second);
        arr[index++] = node;
        iter++;
    }
    if(len <= size){
        return;    
    }
    adjust(arr, size);
    while(iter != wordHash.end()){
        if(arr[0].count < iter->second){
            arr[0].word = iter->first;
            arr[0].count = iter->second;
            shiftDown(arr, 0, size);
        }   
        iter++;
    }
}

void printNode(Node node){
    cout << node.word << "\t\t" << node.count << endl;        
}

int main(int argc, char* argv[]){
    Node arr[10];
    topN(arr, 10);
    for_each(arr, arr+10, printNode);
    
    return 0;
}
