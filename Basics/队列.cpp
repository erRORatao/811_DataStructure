#include<stdio.h>
#include<stdlib.h>

#define Maxsize 10

//循环顺序队列
typedef struct {
	int data[50];
	int front, rear;
	//int count; //可以使用一个计数器来多存储一个空间内容
} SqQueue;

//顺序队列初始化
void InitSqueue(SqQueue& Q) {
	Q.front = 0;
	Q.rear = 0;
}

//顺序队列判空
bool StackEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return false;
	return true;
}

//顺序队列进队
bool Entrance(SqQueue& Q, int x) {
	if (Q.front == Q.rear + 1 || Q.front == (Q.rear + 1) % Maxsize) //这里需要空一个元素不能储存，队满队空的状态无法判断；也可以使用一个计算器
		return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Maxsize;
	return true;
}

//顺序队列出队
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

//队列结点
typedef struct LinkNode{
	int data;
	struct LinkNode* next;
};

//不带头结点的队列，带头的王道书已经给出代码了
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//初始化
void InitLinkQueue(LinkQueue& Q) {
	Q.front = NULL;
	Q.rear = NULL;
}

//判空
bool LinkEmpty(LinkQueue Q) {
	if (Q.front == NULL)
		return false;
	return true;
}

//进队
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

//出队
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