#include <stdio.h>
#include <math.h>
void printNumberFlower(int n){
	int sum,i,j,num;
	int* a;
	a = (int *)malloc(sizeof(int)*n);
	num = pow(10,n);
	for(i = pow(10,n-1)+1; i <=num; i++){
		sum = 0;
		for(j = 0;j < n; j++){
			a[j] = ((int)(i / pow(10,j)))%10;
			sum += pow(a[j],n);

		}
		// printf("%d ",sum);
		if(sum == i){
			printf("%d\t",i);
		}
	}
	printf("\n");
}


//这个程序有问题，由于c语言pow(double a,double r)中参数与返回值都是double型，例如2的C语言可能会把他定义为1.99999999，这样情况的话pow(10,2)其结果可能为99；
//
int main(){

	// int i = 153;
	// int n;
	// n = (int)(i / pow(10,2) )% 10;
	// printf("%d",n);
	printNumberFlower(3);
	return 0;
}