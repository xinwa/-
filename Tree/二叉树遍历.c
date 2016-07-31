#include <stdio.h>
#include "stack.h"
#include <string.h>
#include <malloc.h>
#include "queue.h"

void createTree(BiTree* root){
	char ch;
	scanf("%c",&ch);
	if(ch == '^'){
		*root = NULL;
		return;
	}
	*root = (BiTree)malloc(sizeof(BiTNode));
	(*root)->element = ch;
	//printf("%c ",(*root)->element);
	createTree(&((*root)->LChild));
	createTree(&((*root)->RChild));
}

void preOrder(BiTree root){
	if(root == NULL){
		return;
	}
	printf("%c ",root->element);
	preOrder(root->LChild);
	preOrder(root->RChild);

}
void inOrder(BiTree root){
	if(root == NULL){
		return;
	}
	inOrder(root->LChild);
	printf("%c ",root->element);
	inOrder(root->RChild);
}

void postOrder(BiTree root){
	if(root == NULL){
		return;
	}
	postOrder(root->LChild);
	postOrder(root->RChild);
	printf("%c ",root->element);
}

void visit(BiTree p){
	printf("%c ",p->element);
}

void diguiPreOrder(BiTree root){ // 先序非递归
								// 入栈：节点不为空 出栈：左子数为空，右子数为空
	BiTree p;
	SeqStack * stack;
	if(root == NULL){
		return;
	}
	stack = (SeqStack *)malloc(sizeof(SeqStack));
	p = root;
	while(p != NULL || !isEmpty(stack)){//这里表示某个节点的右孩子为空，但此时栈里还有元素，说明还没有遍历完
		while(p != NULL){
			push(stack,p);
			visit(p);
			p = p ->LChild;
		}

		if(!isEmpty(stack)){ 
			p = pop(stack);
			p = p->RChild;
		}
	}
	free(stack);

}

void diguiInOrder(BiTree root){
	BiTree p;
	SeqStack * stack;
	if(root == NULL){
		return;
	}
	stack = (SeqStack *)malloc(sizeof(SeqStack));
	p = root;   //入栈条件：节点不为空入栈  出栈：左子数为空出栈，访问栈顶元素，然后指向右子树，右子树为空，（出栈时访问元素）
	while(p != NULL || !isEmpty(stack)){
		while(p != NULL){
			push(stack,p);
			p = p->LChild;
		}
		if(!isEmpty(stack)){
			p = pop(stack);
			visit(p);
			p = p ->RChild;
		}

	}
	free(stack);
}

void diguiPostOrder(BiTree root){
	BiTree p,q;			//入栈条件：节点不为空入栈  出栈：右子数为空，或者右子树是上一次刚访问过的节点
	SeqStack * stack;	//每次出栈后，都会在去取栈顶元素，判断右子树是否为空，或者是否刚才被访问过
	if(root == NULL){
		return;
	}
	stack = (SeqStack *)malloc(sizeof(SeqStack));
	p = root;
	while(p != NULL || !isEmpty(stack)){
		while(p != NULL){
			push(stack,p);
			p = p ->LChild;
		}
		if(!isEmpty(stack)){
			p = getTop(stack);
			if(p ->RChild == NULL || p->RChild == q){  
				p = pop(stack);
				visit(p); 
				q = p;
				p = NULL; //由于p已经被访问过，而且他本身也是作为父树中的右子树
			}else{
				p = p ->RChild;
			}
		}
	}
}

int leafNum(BiTree root){//判断叶子节点的个数
	int nl,nr;
	if(root == NULL){
		return 0;
	}
	if(root ->LChild == NULL && root ->RChild == NULL){
		return 1;
	}
	nl = leafNum(root->LChild);
	nr = leafNum(root->RChild);
	return nl+nr;
} 


 int postTreeDepth(BiTree root){
 	int lh,rh,h;
 	if(root == 0){
 		return 0;
 	}else{
 		lh = postTreeDepth(root->LChild);
 		rh = postTreeDepth(root->RChild);
 		h = (lh > rh ?lh : rh) + 1;
 		return h;
 	}
 }

BiTree findNode(BiTree root,BiTree current){
	BiTree p;
	if(root == NULL){
		return NULL;
	}

	if((root->LChild != NULL && root->LChild->element  == current->element) || (root->RChild != NULL && root->RChild->element == current->element)){
		return root;
	}	
	p = findNode(root->LChild,current);
	if(p != NULL){
		return p;
	}else{
		return findNode(root->RChild,current);
	}
}

void printTree(BiTree root ,int h){
	int i;
	if(root == NULL){
		return;
	}
	printTree(root->RChild,h+4);
	for(i = 0;i< h;i++){
		printf(" ");
	}
	printf("%c\n",root->element);
	printTree(root->LChild,h+4);
}

void levelOrder(BiTree root){
	Queue *queue;
	BiTree q;
	q = root;
	if(root ==NULL){
		return;		
	}
	initQueue(&queue);
	inQueue(queue,root);
	
	while(!isQueueEmpty(queue)){
		
		q = outQueue(queue);
		visit(q);
		
		if(q != NULL){
			if(q->LChild != NULL){
				inQueue(queue,q->LChild);
			}
			if(q->RChild != NULL){
				inQueue(queue,q->RChild);
			}
		}
		
	}	
}



int main(){
	BiTree root,p,current;
	int h;
	current = (BiTree)malloc(sizeof(BiTNode));
	current->element = 'H';
	createTree(&root);
	diguiPostOrder(root);
	h = postTreeDepth(root);
	printf("%d\n",h);
	
	p = findNode(root,current);
	visit(p);
	printf("\n");
	printTree(root,0);
	levelOrder(root);
	return 0;
}