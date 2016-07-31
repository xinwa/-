#include <stdio.h>
#include <malloc.h>
/*
思路：  1 
        1 1
        1 2 1
        1 3 3 1
        1 4 6 4 1

        每行的第一个和最后一个元素都为1，然后中间的元素等于前一行对应的前一个元素与后一个元素之和，
        杨辉三角对应于（a+b）^ n 的项数系数
 */

int main(){

    int n,i,j;
    int **a;
    printf("input line number\n");
    scanf("%d",&n);
    
    a =(int**)malloc(sizeof(int*)*n);

    for(i = 0; i < n;i++){
        a[i] = (int *)malloc(sizeof(int)*n);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            if(j == 0 || j == i){
                a[i][j] = 1;
                printf("1 ");
            }else{
                a[i][j] = a[i-1][j-1]+a[i-1][j];
                printf("%d ",a[i][j]);
            }
        }
        printf("\n");
    }  

    for(i = 0 ; i < n; i++){
        free(a[i]);
    }
    free(a);
    
    return 0;
}


 