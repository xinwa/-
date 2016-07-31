#include <stdio.h>

void printMatrix(int a[][5],int headRow,int headCol,int endRow,int endCol){
	
	
	int i,j;
	j=headCol;
	while(j <= endCol){
		printf("%d ",a[headRow][j]);
		j++;
	}
	
	i = headRow+1;
	while(i <= endRow){
		printf("%d ",a[i][endCol]);
		i++;
	}
	
	j = endCol -1;
	while(j >= headCol){
		printf("%d ",a[endRow][j]);
		j--;
	}
	i = endRow -1;
	while(i > headRow){
		printf("%d ",a[i][headCol]);
		i--;
	}
}

void print(int a[][5]){
	int headRow = 0,headCol = 0;
	int endRow = 4,endCol = 4;
	while(headRow <= endRow || headCol <= endCol){
		printMatrix(a,headRow,headCol,endRow,endCol);
		printf("\n");
		headRow++;
		headCol++;
		endRow--;
		endCol--;
	}
}

int main(){
	int a[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	// printMatrix(a,0,0,3,3);
	print(a);
	return 0;
}