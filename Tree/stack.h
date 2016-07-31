#include <stdio.h>

typedef struct Node{
	char element;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree;

typedef struct{
	BiTNode* element[100];
	int top;
}SeqStack;

void push(SeqStack * stack,BiTree element){
	if(stack->top == 100){
		printf("stack is full");
	}else{
		stack->element[stack->top] = element;
		stack->top++;
	}
}

BiTree pop(SeqStack * stack){
	printf("");
	return stack->element[--stack->top];//由于入栈之后top++一次，所以top的位置处于实际所拥有元素的上一位置
}

BiTree getTop(SeqStack *stack){
	return stack->element[stack->top-1];
}

int isEmpty(SeqStack* stack){
	if(stack->top == 0){
		return 1;
	}else{
		return 0;
	}
}

int isFull(SeqStack *stack){
	if(stack->top == 100){
		return 1;
	}else{
		return 0;
	}
}

