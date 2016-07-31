#include <stdio.h>
#include <string.h>

char *reverseString(char *origin){
	int length,i;
	char* result;
	char t;
	length = strlen(origin);
	strcpy(result,origin);
	for(i = 0;i < length /2;i++){
		t = result[i];
		result[i] = result[length-i-1] ;
		result[length-i-1] = t;
	}
	return result;
}


int main(){
	char * ch;
	gets(ch);
	puts(reverseString(ch));
	return 0;
}


/*

char * reverseString(char *origin){
	int i,length=0;
	char *result;
	char t;
	printf("%d\n",length);
	for(i = 0;*(origin+i)!='\0';length++,i++);				
	for(i = 0;i < length /2;i++){
		t = origin[i];
		origin[i] = origin[length-i-1];
		origin[length-i-1]=t;
		puts(origin);
	}
	return origin;
}
 */