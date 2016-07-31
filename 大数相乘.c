#include <stdio.h>
#include <string.h>
#include <malloc.h>
void reverseString(char* ch,int start,int end){
	char temp;
	while(start < end){
		temp = ch[start];
		ch[start] = ch[end];
		ch[end] = temp;
		start++;
		end--;
	}
}

void initString(char* ch,int l){
	int i;
	
	for(i = 0;i < l;i++){
		ch[i] = '0';	
	}
}

int main()
{
	// char ch1[] = "1231231234324234";
	// char ch2[] = "3453467567457";
	char ch1[] = "99999";
	char ch2[] = "999";
	char* ch3;
	int m,n,i,j;
	int multiFlag,addFlag;
	int temp1,temp2;
	m = strlen(ch1);
	n = strlen(ch2);
	reverseString(ch1,0,m-1);
	reverseString(ch2,0,n-1);
	puts(ch1);
	puts(ch2);
	ch3 = (char *)malloc(m+n+1);
	initString(ch3,m+n);
	ch3[m+n]='\0';
	puts(ch3);
	for(i = 0; i < n;i++){
		multiFlag = 0;
		addFlag = 0;
		for(j = 0; j < m;j++){
			temp1 = (ch1[j] - '0') * (ch2[i] - '0') + multiFlag; // 加上上次相乘进位
			multiFlag = temp1 /10; // 计算本次的进位
			temp1 = temp1 % 10; //拿到相乘之后的个位
			temp2 = (ch3[i+j] - '0') + temp1 + addFlag; // 加上上一位相加之后的进位
			addFlag = temp2 / 10;//计算本次相加的进位

			ch3[i+j] = temp2 % 10 + 48; //覆新值
			printf("ch[%d+%d]=%c ",i,j,ch3[i+j]);
		}
			ch3[i+j] += multiFlag + addFlag;  //1. 由于是每乘一行就把结果放到数组里，所以在与最后一位相乘时的进位，他的
											//位置在数组的左侧，然后正好由j++滚到到了下一位，这时将上一位相加的进位与
											//乘法的进位相加放到结果里面。
											//总结起来就是末位相乘有进位
											//末位相加有进位
											
		printf("\n");
	}
	reverseString(ch3,0,m+n-1);
	puts(ch3);
	return 0;	
}