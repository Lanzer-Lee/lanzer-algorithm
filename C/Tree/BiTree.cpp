#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----调用库-----
/*
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;

Status InitStack(SqStack& S) {
	//构造一个空栈
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

Status Push(SqStack& S, SElemType e) {
	//插入元素e为新的栈顶元素
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
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
	if (S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}//Pop

Status StackEmpty(SqStack S) {
	if (S.base == S.top) return TRUE;
	return ERROR;
}//StackEmpty

Status GetTop(SqStack S, SElemType& e) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}//GetTop
*/
//-----二叉树的二叉链表存储表示-----
typedef int TElemType;
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree,*SElemType;

Status visit(TElemType e) {
	printf("%d\t", e);
	return OK;
}


//-----基本操作实现-----
Status CreateBiTree(BiTree& T) {
	//按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树
	//构造二叉链表表示的二叉树
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
	//递归先序遍历
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
	//递归中序遍历
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
	//递归后序遍历
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
	//非递归中序遍历
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

