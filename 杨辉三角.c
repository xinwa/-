#include <stdio.h>
#include <malloc.h>
/*
˼·��  1 
        1 1
        1 2 1
        1 3 3 1
        1 4 6 4 1

        ÿ�еĵ�һ�������һ��Ԫ�ض�Ϊ1��Ȼ���м��Ԫ�ص���ǰһ�ж�Ӧ��ǰһ��Ԫ�����һ��Ԫ��֮�ͣ�
        ������Ƕ�Ӧ�ڣ�a+b��^ n ������ϵ��
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


 