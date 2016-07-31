#include <stdio.h>
#include "queue.h"

int main(){
	Queue *q = initQueue();
	int i,j,n;
	int last,new;
	int value;
	printf("input line number\n");
    scanf("%d",&n);

    for(i = 0; i < n;i++){
    	last = 1;
    	for(j = 0; j <= i; j++){
    		if(j == 0 || j == i){
    			printf("%d ",1);
    		}else{
    			if(j == i-1){
    				if(i == 2){
    					printf("2 ");
    					InQueue(q,2);
    				}else{
    					new = last +1;
    					printf("%d ",new);
						InQueue(q,new);
    				}
    			}else{
    				value = OutQueue(q);
					new = value + last;
					last = value;
					InQueue(q,new);
					printf("%d ",new);
    			}
    		}

    	}
    	printf("\n");
    }
	return 0;
}