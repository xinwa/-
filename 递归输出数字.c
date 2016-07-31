#include <stdio.h>


void printDigit(int number){
	printf("%d ",number);
}

void printNumber(int number){
	if(number >= 10){
		printNumber(number/10);
	}
		printDigit(number%10);
}

int main(){
	printNumber(765432);
	return 0;
}




/*

 这就是我写的程序和人家写的程序的差距
void printNumber(int number){
	int value;
	if(number >= 10){
		value = number % 10;
		number /=10;		
		printNumber(number);
	}else{
		value = number;
	}
	printDigit(value);
	
}
 */