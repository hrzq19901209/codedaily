#include <stdio.h>

void print(int a[][9], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", a[i][j]);
        }    
        printf("\n");
    }
    printf("\n");
}

int rotate(int a[][9], int b[][9], int n){
    int degree = 0;
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n; j++){
            if(a[i][j] == b[i][j]){
                degree = 0;    
            }else{
                break;    
            }
        }    
        if(j < n){
            degree = -1;    
            break;
        }
    }
    if(degree == 0){
        return 0;    
    }
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n; j++){
            if(a[i][j] == b[j][n-i-1]){
                degree = 90;    
            }else{
                break;    
            }
        }    
        if(j < n){
            degree = -1;    
            break;
        }
    }
    if(degree == 90){
        return 90;
    }
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n; j++){
            if(a[i][j] == b[n-i-1][n-j-1]){
                degree = 180;    
            }else{
                break;    
            }
        }    
        if(j < n){
            degree = -1;    
            break;
        }
    }
    if(degree == 180){
        return 180;    
    }
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n; j++){
            if(a[i][j] == b[n-j-1][i]){
                degree = 270;    
            }else{
                break;    
            }
        }    
        if(j < n){
            degree = -1;    
            break;
        }
    }
    if(degree == 270){
        return 270;    
    }
    return -1;
}

//旋转90度 不救助另外一个大小的矩阵
int rotate90(int a[][9], int n){
    for(int layer =0; layer < n/2; layer++){
        int first = layer;
        int last = n-layer-1;
        for(int m=first; m<last; m++){
            int i=layer, j=m;
            int ni =j,nj = n-i-1;
            int save1 = a[ni][nj];
            a[ni][nj] = a[i][j];

            i=ni;j=nj;
            ni=j;nj=n-i-1;
            int save2 = a[ni][nj];
            a[ni][nj] = save1;

            i=ni;j=nj;
            ni=j;nj=n-i-1;
            int save3 = a[ni][nj];
            a[ni][nj] = save2;

            i=ni;j=nj;
            ni=j;nj=n-i-1;
            a[ni][nj] = save3;
        }
    }

    print(a, n);
}

int main(int argc, char **argv){
    int n;
    int a[9][9];
    int b[9][9];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", *(a+i)+j);    
        }    
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", *(b+i)+j);    
        }    
    }

    print(a, n);
    print(b, n);
    printf("%d\n", rotate(a,b,n));

    rotate90(a, n);
    rotate180(a, n);
    rotate270(a, n);
}
