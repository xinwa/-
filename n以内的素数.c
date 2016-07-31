#include <stdio.h>
#include <math.h>

void calPrime(int n){
	int i,j;
	int a[n+1],h;
	h = sqrt(n);
	for(i = 2; i <= n; i++){
		a[i] = i;
	}

	for(i = 2; i <= h; i++){
		if(a[i] != 0){
			for(j = i+i; j <= n;j+=i){
				a[j] = 0;
			}
		}	
	}

	for(i = 2;i <= n;i++){
		if(a[i] != 0){
			printf("%d ",a[i]);
		}
	}
}

int main(){
	calPrime(200);

return 0;
}