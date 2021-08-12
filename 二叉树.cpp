#include<stdio.h>
#include<stdlib.h>

#define Maxsize 10

typedef struct BiTNode {
	int data;
	BiTNode* Lchild, * Rchild;
}BiTNode,*BiTree;

void InitBiTree(BiTree& B,int x) {
	B = (BiTNode*)malloc(sizeof(BiTree));
	B->data = x;
	B->Lchild = B->Rchild = NULL;
}

//递归的方式通过前序和中序将数据插入二叉树
BiTNode* Preorder_To_Inorder(int &start,int Istart,int Iend, int I[], int P[]) {
	if (Istart >= Iend)
		return NULL;
	int end;
	for (int i = Istart; i < Iend; i++) {
		if (I[i] == P[start]) {
			end = i;
			break;
		}
	}
	BiTNode* Node = (BiTNode*)malloc(sizeof(BiTNode));
	Node->data = P[start];
	start++;
	Node->Lchild = Preorder_To_Inorder(start, Istart,end, I, P);
	Node->Rchild = Preorder_To_Inorder(start, end+1, Iend, I, P);
	return Node;
}

//后序遍历
void PostOrder(BiTree B) {
	if (B != NULL) {
		PostOrder(B->Lchild);
		PostOrder(B->Rchild);
		printf("%d ", B->data);
	}
}

//中序遍历
void InOrder(BiTree B) {
	if (B != NULL) {
		PostOrder(B->Lchild);
		printf("%d ", B->data);
		PostOrder(B->Rchild);
	}
}

//前序遍历
void PreOrder(BiTree B) {
	if (B != NULL) {
		printf("%d ", B->data);
		PostOrder(B->Lchild);
		PostOrder(B->Rchild);
	}
}

//偷懒Boy，这里直接抄队列的代码，所以看起来变量看起来有点奇怪
typedef struct {
	BiTree Node[50];
	int front, rear;
} BiT_Q;

//将层次遍历的队列初始化
void InitSqueue(BiT_Q& Q) {
	Q.front = 0;
	Q.rear = 0;
}

//判断层次遍历的队列内是否还有结点
bool StackEmpty(BiT_Q Q) {
	if (Q.front == Q.rear)
		return false;
	return true;
}

//分别在递归时调用进队和出队

//顺序队列进队
bool Entrance(BiT_Q& Q, BiTree x) {
	if (Q.front == Q.rear + 1 || Q.front == (Q.rear + 1) % Maxsize) //这里需要空一个元素不能储存，队满队空的状态无法判断；也可以使用一个计算器
		return false;
	Q.Node[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
	return true;
}

//顺序队列出队
bool Goout(BiT_Q& Q, BiTree& x) {
	if (StackEmpty(Q)) {
		x = Q.Node[Q.front];
		Q.front = (Q.front + 1) % Maxsize;
		return true;
	}
	else {
		return false;
	}
}

//层次遍历
void Leveltraversal(BiTree B) {
	BiT_Q Q;
	BiTNode* node;
	InitSqueue(Q);
	Entrance(Q, B);
	while (StackEmpty(Q)) {
		Goout(Q, node);
		printf("%d ", node->data);
		if (node->Lchild) {
			Entrance(Q, node->Lchild);
		}
		if (node->Rchild) {
			Entrance(Q, node->Rchild);
		}
	}
}


int main() {
	int p[8] = { 28, 16, 13, 22, 30, 29, 43 };
	int i[7] = { 13, 16, 22, 28, 29, 30, 43 };
	int start = 0;
	BiTree B = (BiTree)Preorder_To_Inorder(start, 0, 7, i, p);
	PostOrder(B);
	printf("\n");
	Leveltraversal(B);
	return 0;
}