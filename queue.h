#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
typedef struct{
	int data[MAXSIZE];
	int front,rear;
}Queue;

Queue* initQueue(){
	Queue* q = (Queue *) malloc(sizeof(Queue));
	q->rear = q->front = MAXSIZE -1;
	return q;
}

int InQueue(Queue *q,int number){
	if(q->rear + 1 == q->front){
		printf("Queue is already full");
		return FALSE;
	}

	q->rear = (q->rear+1) % MAXSIZE;
	q->data[q->rear] = number;
	return TRUE;
}

int OutQueue(Queue * q){
	if(q->rear == q->front){
		printf("Queue is already empty");
		return FALSE;
	}
	q->front = (q->front+1)% MAXSIZE;
	return q->data[q->front];
}

int IsEmpty(Queue * q){
	if(q->rear == q->front){
		return TRUE;
	}else{
		return FALSE;
	}
}

int IsFull(Queue *q){
	if(q->rear + 1 == q->front){
		return TRUE;
	}else{
		return FALSE;
	}
}