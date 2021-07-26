#include<stdio.h>
#include<stdlib.h>

#define Maxsize 10

//ѭ��˳�����
typedef struct {
	int data[50];
	int front, rear;
	//int count; //����ʹ��һ������������洢һ���ռ�����
} SqQueue;

//˳����г�ʼ��
void InitSqueue(SqQueue& Q) {
	Q.front = 0;
	Q.rear = 0;
}

//˳������п�
bool StackEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return false;
	return true;
}

//˳����н���
bool Entrance(SqQueue& Q, int x) {
	if (Q.front == Q.rear + 1 || Q.front == (Q.rear + 1) % Maxsize) //������Ҫ��һ��Ԫ�ز��ܴ��棬�����ӿյ�״̬�޷��жϣ�Ҳ����ʹ��һ��������
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
	return true;
}

//˳����г���
bool Goout(SqQueue& Q, int& x) {
	if (StackEmpty(Q)) {
		x = Q.data[Q.front];
		Q.front = (Q.front + 1) % Maxsize;
		return true;
	}
	else{
		return false;
	}
}

//���н��
typedef struct LinkNode{
	int data;
	struct LinkNode* next;
};

//����ͷ���Ķ��У���ͷ���������Ѿ�����������
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//��ʼ��
void InitLinkQueue(LinkQueue& Q) {
	Q.front = NULL;
	Q.rear = NULL;
}

//�п�
bool LinkEmpty(LinkQueue Q) {
	if (Q.front == NULL)
		return false;
	return true;
}

//����
bool Link_Entrance(LinkQueue& Q, int x) {
	LinkNode* Node;
	Node = (LinkNode*)malloc(sizeof(LinkNode));
	Node->data = x;
	Node->next = NULL;
	if (LinkEmpty(Q)) {
		Q.rear->next = Node;
		Q.rear = Node;
	}
	else {
		Q.front = Q.rear = Node;
	}
	return true;
}

//����
bool Link_Goout(LinkQueue& Q, int& x) {
	if (LinkEmpty(Q)) {
		x = Q.front->data;
		LinkNode* Node;
		Node = Q.front;
		Q.front = Q.front->next;
		free(Node);
		return true;
	}
	else {
		return false;
	}
}


int main() {
	int x;

	SqQueue Q;
	InitSqueue(Q);
	for (int i = 0; i < 10; i++) {
		Entrance(Q, i);
	}
	while (Goout(Q, x)) {
		printf("%d ", x);
	}
	printf("\n");

	LinkQueue LinkQ;
	InitLinkQueue(LinkQ);
	for (int i = 0; i < 10; i++) {
		Link_Entrance(LinkQ, i);
	}
	while (Link_Goout(LinkQ, x)) {
		printf("%d ", x);
	}
	return 0;
}