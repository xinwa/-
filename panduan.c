#include <stdio.h>

int main(){

	int n,i;
	char** ch;
	scanf("%d",&n);
	ch = (char**)malloc(sizeof(char*)*n);
	
	for(i = 0; i < n; i++){
		ch[i] = malloc(sizeof())
		scanf("%s",ch[i]);
	}

	for(i = 0; i < n;i++){
		printf("%s",ch[i]);
	}
	

	return 0;
}