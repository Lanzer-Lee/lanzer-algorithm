#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----���ÿ�-----
/*
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S) {
	//����һ����ջ
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

Status Push(SqStack& S, SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}//Push

Status Pop(SqStack& S, SElemType& e) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}//Pop

Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	return ERROR;
}//StackEmpty

Status GetTop(SqStack S, SElemType& e) {
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}//GetTop
*/
//-----�������Ķ�������洢��ʾ-----
typedef int TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree,*SElemType;

Status visit(TElemType e) {
	printf("%d\t", e);
	return OK;
}


//-----��������ʵ��-----
Status CreateBiTree(BiTree& T) {
	//�������������������н���ֵ��һ���ַ������ո��ַ���ʾ����
	//������������ʾ�Ķ�����
	int ch;
	scanf_s("%d", &ch);
	if (ch == -1) T = NULL;
	else {
		if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}//CreateBiTree

Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	//�ݹ��������
	if (T) {
		if (visit(T->data))
			if (PreOrderTraverse(T->lchild, visit))
				if (PreOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	else return OK;
}//PreOrderTraverse

Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	//�ݹ��������
	if (T) {
		if (InOrderTraverse(T->lchild, visit))
			if (visit(T->data))
				if (InOrderTraverse(T->rchild, visit))
					return OK;
		return ERROR;
	}
	else return OK;
}

Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e)) {
	//�ݹ�������
	if (T) {
		if (PostOrderTraverse(T->lchild, visit))
			if (PostOrderTraverse(T->rchild, visit))
				if (visit(T->data))
					return OK;
		return ERROR;
	}
	else return OK;
}
/*
Status InOrderTraverse2(BiTree T, Status(*visit)(TElemType e)) {
	//�ǵݹ��������
	BiTree p;
	SqStack(S); InitStack(S);
	Push(S, T);
	while (!StackEmpty(S)) {
		while (GetTop(S, p) && p) Push(S, p->lchild);
		Pop(S, p);
		if (!StackEmpty(S)) {
			Pop(S, p);
			if (visit(p->data))
				return ERROR;
			Push(S, p->rchild);
		}
	}
	return OK;
}
*/

