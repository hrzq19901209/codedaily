#include <iostream>
#include <stdio.h>

void remove(char *str){
    if(str == NULL){
        return;    
    }        
    char *index = str;
    unsigned int exist= 0 | 1<<(*index-'a');//第一个元素已经插入
    char *check = str+1;
    while(*check){
        int shift = *check -'a';
        if(exist & (1 << shift)){
            check++;    
        }else{
            exist |= 1<<shift;
            index++;
            *index=*check;
            check++;
        }
    }
    index++;
    *index = '\0';
}

int main(){
    char str[] = "fabcfeddf";
    printf("%s\n", str);
    remove(str);
    printf("%s\n", str);
    return 0;
}
