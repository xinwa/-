#include <stdio.h>

typedef struct Node{
	int element;
	int height;
	struct Node *LChild;
	struct Node *RChild;
}BiTNode,*BiTree,*Position;

int height(BiTree root){
	if(p = NULL){
		return 0;
	}else{
		root->height;
	}
}

int max(int a,int b){
	return a>b?a:b;
}

BiTree insertElement(BiTree root,int element){
	if(root == NULL){
		root = (BiTree)malloc(sizeof(BiTNode));
		root->element = element;
		root->height = 0;
		root->LChild = root->RChild = NULL;
	}else{
		if(element < root->element){
			root->LChild = insertElement(root->LChild,element);
		}else if(element > root->element){
			root->RChild = insertElement(root->RChild,element);
		}
	}
	root->height = max(height(root->LChild),height(root->RChild))+1;	
	return root;
}

BiTree singleRotateWithLeft(BiTree k2){//往左儿子的左子树插入节点    这个函数是不完整的，只有k2有一个左孩子
	Position k1;
	k1 = k2->LChild;
	k2->LChild = k1->RChild;
	k1->RChild = k2;
	k1->height = max(height(k1->LChild),height(k1->RChild))+1;
	k2->height = max(height(k2->LChild),height(k2->RChild))+1;
	return k1;
}

BiTree singleRotateWithRight(BiTree k2){//往右儿子的右子树插入节点
	Position k1;
	k1= k2->RChild;
	k2->RChild = k1->LChild;
	k1->LChild = k2;
	k1->height = max(height(k1->LChild),height(k1->RChild))+1;
	k2->height = max(height(k2->LChild),height(k2->RChild))+1;
	return k1;
}

BiTree doubleRotateWithLeft(BiTree k3){//往右儿子的左子树插入节点
	
}

BiTree doubleRotateWithRight(BiTree k3){//往左儿子的右子树插入节点

}

BiTree findNode(BiTree root,int element){
	if(root == NULL){
		return NULL;
	}
	if(element < root->element){			 //之前写的时候在这里把return给丢了，当你进入左子树的时候，并且在某个节点找到的时候，
		return findNode(root->LChild,element);//那个节点会把他的地址返回，可是在往上回溯时，发现上层的函数没有返回值，这样在
	}else if(element > root->element){			//主函数中就没有返回值可以拿了。所以在输出的时候就会生错误
		return findNode(root->RChild,element);
	}else{
		return root;
	}

}

BiTree findMaxNode(BiTree root){
	if(root == NULL){
		return NULL;
	}
	while(root->RChild != NULL){
		root = root->RChild;
	}
	return root;
}

BiTree findMinNode(BiTree root){
	if(root == NULL){
		return NULL;
	}
	while(root->LChild != NULL){
		root = root->LChild;
	}
	return root;
}


BiTree deleteElement(BiTree root,int element){
	if(root == NULL){
		return;
	}
	printf("%d ",root->element);
	if(element < root->element){
		root->LChild = deleteElement(root->LChild,element);

	}else if(element > root->element){
		root ->RChild = deleteElement(root->RChild,element);
	}else if(root ->LChild != NULL && root->RChild != NULL){  //要删除的节点有俩个子节点，
		printf("two node don't empty\n");
		root->element = findMinNode(root->RChild)->element;	//	从他的右子树中找出一个一个最小的节点,放到要删除的节点位置，
		printf("min element is %d\n",root->element); //这里之前犯过一个错误，由于findMinNode的返回的是最小元素的地址，而不是值
		root->RChild = deleteElement(root->RChild,root->element);			//把那个最小的节点的位置元素释放
	}else if(root->LChild == NULL && root->RChild == NULL){//要删除的节点叶子节点
		printf("two node all empty\n");
		return NULL; 
	}else{   //要删除的节点有一个节点
		if(root->LChild != NULL){//如果要删除的节点有一个左节点
			return root->LChild;
		}								//上面这三种情况可以归+结为一种情况
		if(root->RChild != NULL){
			return root->RChild;
		}
	}
	return root;      //上次写程序的时候把这行代码又给没写，在写有返回值递归的时候，需要注意这个问题了。
}					  // 如果你不写返回值的话，那么当后面的递归结束时，返回了值给前面的值，由于这个程序他的
					  //if,else 只能执行一次，没有返回值的话，那么这颗树就给断掉了


void printTree(BiTree root ,int h){
	int i;
	if(root == NULL){
		return;
	}
	printTree(root->RChild,h+4);
	for(i = 0;i< h;i++){
		printf(" ");
	}
	printf("%d\n",root->element);
	printTree(root->LChild,h+4);
}

void preOrder(BiTree root){
	if(root == NULL){
		return;
	}
	printf("%d ",root->element);
	preOrder(root->LChild);
	preOrder(root->RChild);

}

int main(){
	BiTree root = NULL;
	BiTree p ;
	root = insertElement(root,2,1);
	insertElement(root,1,2);
	insertElement(root,3,2);
	insertElement(root,4,3);
	insertElement(root,5,4);
	printTree(root,0);
	return 0;
}
