#include <stdio.h>

#define MAXSIZE 100


typedef struct{
	BiTree data[MAXSIZE];
	int rear,front;
}Queue;

void initQueue(Queue **q){
	(*q) = (Queue*)malloc(sizeof(Queue));
	 (*q)->rear = (*q)->front = -1;
}

void inQueue(Queue *q,BiTree data){//入队操作就不判断是否队列已经满了，由调用者处理
	q->rear = (q->rear+1) % MAXSIZE;//top位于存放数据的前一个位置。出队头元素得+1
	q->data[q->rear] = data;
}

BiTree outQueue(Queue *q){
	q->front = (q->front+1) % MAXSIZE;
	return q->data[q->front];
}


int isQueueEmpty(Queue *q){
	if(q->rear == q->front){
		return 1;
	}else{
		return 0;
	}
}

int isQueueFull(Queue *q){
	if(q->front =(q->rear+1) % MAXSIZE){
		return 1;
	}else{
		return 0;
	}
}