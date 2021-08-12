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

//�ݹ�ķ�ʽͨ��ǰ����������ݲ��������
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

//�������
void PostOrder(BiTree B) {
	if (B != NULL) {
		PostOrder(B->Lchild);
		PostOrder(B->Rchild);
		printf("%d ", B->data);
	}
}

//�������
void InOrder(BiTree B) {
	if (B != NULL) {
		PostOrder(B->Lchild);
		printf("%d ", B->data);
		PostOrder(B->Rchild);
	}
}

//ǰ�����
void PreOrder(BiTree B) {
	if (B != NULL) {
		printf("%d ", B->data);
		PostOrder(B->Lchild);
		PostOrder(B->Rchild);
	}
}

//͵��Boy������ֱ�ӳ����еĴ��룬���Կ����������������е����
typedef struct {
	BiTree Node[50];
	int front, rear;
} BiT_Q;

//����α����Ķ��г�ʼ��
void InitSqueue(BiT_Q& Q) {
	Q.front = 0;
	Q.rear = 0;
}

//�жϲ�α����Ķ������Ƿ��н��
bool StackEmpty(BiT_Q Q) {
	if (Q.front == Q.rear)
		return false;
	return true;
}

//�ֱ��ڵݹ�ʱ���ý��Ӻͳ���

//˳����н���
bool Entrance(BiT_Q& Q, BiTree x) {
	if (Q.front == Q.rear + 1 || Q.front == (Q.rear + 1) % Maxsize) //������Ҫ��һ��Ԫ�ز��ܴ��棬�����ӿյ�״̬�޷��жϣ�Ҳ����ʹ��һ��������
		return false;
	Q.Node[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
	return true;
}

//˳����г���
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

//��α���
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