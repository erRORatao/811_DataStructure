#include<stdio.h>
#include<stdlib.h>

//栈的顺序储存
#define MaxSize 50

typedef struct {
	int data[MaxSize]; //储存数据
	int top; //指向栈顶
}SqStack;

//初始化栈
void InitStack(SqStack &S) {
	S.top = -1;
}

//判断是否栈空
bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return false;
	return true;
}

//进栈
bool Push(SqStack& S, int x) {
	if (S.top + 1 == MaxSize)
		return false;
	S.data[++S.top] = x;
	return true;
}

//出栈
bool Pop(SqStack& S, int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//取栈顶值
bool GetTop(SqStack S, int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

void DestroyStack(SqStack& S) {
}


//栈的链式储存
typedef struct Linknode {
	int data;
	struct Linknode* next;
} *LiStack;

//不带头结点的栈初始化
void InitLinknode(LiStack& L) {
	L = NULL;
}

//不带头结点的判空
bool LiStackEmpty(LiStack L) {
	if (L == NULL)
		return false;
	return true;
}

//不带头结点的进栈
void Li_Push(LiStack& L, int x) {
	Linknode *node;
	node = (Linknode*)malloc(sizeof(Linknode));
	node->next = L;
	node->data = x;
	L = node;
}

//不带头结点的出栈
bool Li_Pop(LiStack& L, int& x) {
	if (L == NULL)
		return false;
	x = L->data;
	Linknode* node;
	node = L;
	L = L->next;
	free(node);
	return true;
}

//不带头结点的取栈顶值
bool Li_GetTop(LiStack L, int& x) {
	if (L == NULL)
		return false;
	x = L->data;
	return true;
}


//带头结点的栈初始化
void H_InitLinknode(LiStack& L) {
	L = (LiStack)malloc(sizeof(Linknode));
	L->next = NULL;
}

//带头结点的判空
bool H_LiStackEmpty(LiStack L) {
	if (L->next == NULL)
		return false;
	return true;
}

//带头结点的进栈
void H_Li_Push(LiStack& L, int x) {
	Linknode* node;
	node = (Linknode*)malloc(sizeof(Linknode));
	node->next = L->next;
	node->data = x;
	L->next = node;
}

//带头结点的出栈
bool H_Li_Pop(LiStack& L, int& x) {
	if (L->next == NULL)
		return false;
	x = L->next->data;
	Linknode* node;
	node = L->next;
	L->next = L->next->next;
	free(node);
	return true;
}

//带头结点的取栈顶值
bool H_Li_GetTop(LiStack L, int& x) {
	if (L->next == NULL)
		return false;
	x = L->next->data;
	return true;
}


int main() {
	int x;

	SqStack S;
	InitStack(S);
	if (StackEmpty(S))
		printf("栈不为空 ");
	else
		printf("栈为空 ");
	for (int i = 0; i < 10; i++) {
		Push(S, i);
	}
	GetTop(S, x);
	if (StackEmpty(S))
		printf("栈不为空 ");
	else
		printf("栈为空 ");
	printf("%d ", x);
	for (int j = 0; j < 10; j++) {
		Pop(S, x);
		printf("%d ", x);
	}
	printf("\n");

	LiStack L;
	InitLinknode(L);
	if (LiStackEmpty(L))
		printf("栈不为空 ");
	else
		printf("栈为空 ");
	for (int i = 0; i < 10; i++) {
		Li_Push(L, i);
	}
	if (LiStackEmpty(L))
		printf("栈不为空 ");
	else
		printf("栈为空 ");
	Li_GetTop(L, x);
	printf("%d ", x);
	for (int j = 0; j < 10; j++) {
		Li_Pop(L, x);
		printf("%d ", x);
	}
	printf("\n");

	LiStack headL;
	H_InitLinknode(headL);
	if (H_LiStackEmpty(headL))
		printf("栈不为空 ");
	else
		printf("栈为空 ");
	for (int i = 0; i < 10; i++) {
		H_Li_Push(headL, i);
	}
	if (H_LiStackEmpty(headL))
		printf("栈不为空 ");
	else
		printf("栈为空 ");
	H_Li_GetTop(headL, x);
	printf("%d ", x);
	for (int j = 0; j < 10; j++) {
		H_Li_Pop(headL, x);
		printf("%d ", x);
	}
	return 0;
}