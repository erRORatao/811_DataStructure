#include<stdio.h>
#include<stdlib.h>

//ջ��˳�򴢴�
#define MaxSize 50

typedef struct {
	int data[MaxSize]; //��������
	int top; //ָ��ջ��
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S) {
	S.top = -1;
}

//�ж��Ƿ�ջ��
bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return false;
	return true;
}

//��ջ
bool Push(SqStack& S, int x) {
	if (S.top + 1 == MaxSize)
		return false;
	S.data[++S.top] = x;
	return true;
}

//��ջ
bool Pop(SqStack& S, int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}

//ȡջ��ֵ
bool GetTop(SqStack S, int& x) {
	if (S.top == -1)
		return false;
	x = S.data[S.top];
	return true;
}

void DestroyStack(SqStack& S) {
}


//ջ����ʽ����
typedef struct Linknode {
	int data;
	struct Linknode* next;
} *LiStack;

//����ͷ����ջ��ʼ��
void InitLinknode(LiStack& L) {
	L = NULL;
}

//����ͷ�����п�
bool LiStackEmpty(LiStack L) {
	if (L == NULL)
		return false;
	return true;
}

//����ͷ���Ľ�ջ
void Li_Push(LiStack& L, int x) {
	Linknode *node;
	node = (Linknode*)malloc(sizeof(Linknode));
	node->next = L;
	node->data = x;
	L = node;
}

//����ͷ���ĳ�ջ
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

//����ͷ����ȡջ��ֵ
bool Li_GetTop(LiStack L, int& x) {
	if (L == NULL)
		return false;
	x = L->data;
	return true;
}


//��ͷ����ջ��ʼ��
void H_InitLinknode(LiStack& L) {
	L = (LiStack)malloc(sizeof(Linknode));
	L->next = NULL;
}

//��ͷ�����п�
bool H_LiStackEmpty(LiStack L) {
	if (L->next == NULL)
		return false;
	return true;
}

//��ͷ���Ľ�ջ
void H_Li_Push(LiStack& L, int x) {
	Linknode* node;
	node = (Linknode*)malloc(sizeof(Linknode));
	node->next = L->next;
	node->data = x;
	L->next = node;
}

//��ͷ���ĳ�ջ
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

//��ͷ����ȡջ��ֵ
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
		printf("ջ��Ϊ�� ");
	else
		printf("ջΪ�� ");
	for (int i = 0; i < 10; i++) {
		Push(S, i);
	}
	GetTop(S, x);
	if (StackEmpty(S))
		printf("ջ��Ϊ�� ");
	else
		printf("ջΪ�� ");
	printf("%d ", x);
	for (int j = 0; j < 10; j++) {
		Pop(S, x);
		printf("%d ", x);
	}
	printf("\n");

	LiStack L;
	InitLinknode(L);
	if (LiStackEmpty(L))
		printf("ջ��Ϊ�� ");
	else
		printf("ջΪ�� ");
	for (int i = 0; i < 10; i++) {
		Li_Push(L, i);
	}
	if (LiStackEmpty(L))
		printf("ջ��Ϊ�� ");
	else
		printf("ջΪ�� ");
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
		printf("ջ��Ϊ�� ");
	else
		printf("ջΪ�� ");
	for (int i = 0; i < 10; i++) {
		H_Li_Push(headL, i);
	}
	if (H_LiStackEmpty(headL))
		printf("ջ��Ϊ�� ");
	else
		printf("ջΪ�� ");
	H_Li_GetTop(headL, x);
	printf("%d ", x);
	for (int j = 0; j < 10; j++) {
		H_Li_Pop(headL, x);
		printf("%d ", x);
	}
	return 0;
}