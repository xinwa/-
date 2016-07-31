#include <stdio.h>
#include <malloc.h>
#include <conio.h>

#define MAXSIZE 100

typedef struct Node
{
	char c;
	struct Node *LChild;
	struct Node *RChild;
}BitNode,* BiTree;

typedef struct
{
	BiTree data[MAXSIZE+1];
	int top;
}Seqstack;

void PrintTree(BiTree root,int h);
int IsEmpty(Seqstack *S);
void InitSeqStack(Seqstack **h);
void PushStack(Seqstack *S,BiTree data);
void PopStack(Seqstack *S,BiTree *data);
void CreateBiTree(BiTree *root);

int IsEmpty(Seqstack *S)
{
	if(S->top == 0)
		return 0;
	else
		return 1;
}

void InitSeqStack(Seqstack **h)//��ʼ��ջ
{
	(*h) =(Seqstack *)malloc(sizeof(Seqstack));
	(*h)->top = 0;
}

void PushStack(Seqstack *S,BiTree data)//��ջ
{
	(S->top)++;
	S->data[S->top] = data;
}

void PopStack(Seqstack *S,BiTree *data) //��ջ
{
	*data = S->data[S->top];
	S->data[S->top] = NULL;
	S->top--;
}

void Top(Seqstack *S,BiTree *data)
{
	*data = S->data[S->top];
}


void CreateBiTree(BiTree *root) //����������
{
	char ch;
	ch = getchar();
	if(ch == '^')
		(*root) = NULL;
	else
	{
		(*root) =(BiTree) malloc(sizeof(BitNode));
		(*root)->c = ch;
		CreateBiTree(&((*root)->LChild));
		CreateBiTree(&((*root)->RChild));
	}
}

void PreOrder(BiTree root)   //����ǵݹ����
{
	Seqstack *S;
	BiTree p;
	p = root;
	InitSeqStack(&S);
	while(p != NULL || IsEmpty(S))
	{
		while(p != NULL)
		{
			printf("%c ",p->c);
			PushStack(S,p);			
			p = p->LChild;
		}
		if(IsEmpty(S))
		{
			PopStack(S,&p);
			p = p->RChild; 
		}
	}
}

void PrintTree(BiTree root,int h)
{

	int i = 0;
	if(root == NULL)
		return 0;
	PrintTree(root->RChild, h+3);
	for(i=0;i < h;i++) 
		printf(" ");
	printf("%c\n",root->c);
	PrintTree(root->LChild,h+3);
}

void InOrder(BiTree root) //����ǵݹ����
{
		Seqstack *S;
	BiTree p;
	p = root;
	InitSeqStack(&S);
	while(p != NULL || IsEmpty(S))
	{
		while(p != NULL)
		{
			PushStack(S,p);
		
			p = p->LChild;
		}
		if(IsEmpty(S))
		{
			PopStack(S,&p);
			printf("%c ",p->c);
			p= p->RChild; 
		}
	}
}

void PostOrder(BiTree root)//�������
{
	Seqstack *S;
	BiTree p,q = NULL;
	p = root;
	InitSeqStack(&S);
	while(p != NULL || IsEmpty(S))
	{
		while(p != NULL)
		{
			PushStack(S,p);
			p = p ->LChild;
		}
		if(IsEmpty(S))
		{
			Top(S,&p);
			if((p -> RChild == NULL) || (p ->RChild==q))
			{
				PopStack(S,&p);
				printf("%c ",p->c);
				q = p;
				p = NULL;
			}
			else
				p = p ->RChild;
		}
	}
}


main()
{

	BiTree root;
	CreateBiTree(&root);
	printf("�������Ϊ:");
	PreOrder(root); 
	printf("\n");
	printf("�������Ϊ:");
	InOrder(root);
	printf("\n");
	printf("�������Ϊ:");
	PostOrder(root);
	printf("\n\n\n\n");

	PrintTree(root,8);


}



