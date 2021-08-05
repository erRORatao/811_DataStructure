#include<stdio.h>
#include<stdlib.h>

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

int main() {
	int p[8] = { 28, 16, 13, 22, 30, 29, 43 };
	int i[7] = { 13, 16, 22, 28, 29, 30, 43 };
	int start = 0;
	BiTree B = (BiTree)Preorder_To_Inorder(start, 0, 7, i, p);
	PostOrder(B);
	return 0;
}