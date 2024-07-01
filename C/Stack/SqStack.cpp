/*
* Stack有栈顶元素a1和栈底元素an，栈顶为top，栈底为bottom
* 后进先出(Last In First Out,LIFO)
* 
* 因为base==top是栈空标志，所以top指针只能指示真正的栈顶元素
* 之上的数组元素的下标地址，否则造成矛盾；
* 
* 栈满时处理方法：出错||分配新空间
*/
#include<iostream>
#include<stdlib.h>

#define STACK_INIT_SIZE 100	//基本容量
#define STACKINCREMENT 10	//增量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
using namespace std;
typedef int SElemType;
typedef int Status;

typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
enum { A, B };
Status InitStack(SqStack& S);
Status GetTop(SqStack S, SElemType& e);
Status Push(SqStack& S, SElemType e);
Status Pop(SqStack& S, SElemType& e);
Status StackEmpty(SqStack S);
Status ClearStack(SqStack& S);
Status DestroyStack(SqStack& S);
int StackLength(SqStack S);
Status visit(SElemType e);
Status StackTraverse(SqStack S, Status(*visit)(SElemType));
void conversion();

int main()
{
	/*
	SqStack S;
	InitStack(S);
	SElemType e;
	for (int i = 0; i < 10; i++)
		Push(S, i);
	StackTraverse(S, visit);
	*/
	printf("%d\t%d\n", A, B);
	conversion();
	return 0;
}

Status InitStack(SqStack& S) {
	//构造一个空栈
	S.base=(SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;					//空栈标志
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S, SElemType& e) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}//GetTop

Status Push(SqStack& S, SElemType e) {
	//插入元素e为新的栈顶元素
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base) exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++=e;
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
}

Status ClearStack(SqStack& S) {
	if (S.top == S.base) return ERROR;
	S.top = S.base;
	return OK;
}

Status DestroyStack(SqStack& S) {
	S.top = S.base;
	free(S.base);
	return OK;
}

int StackLength(SqStack S) {
	//返回S的元素个数，即栈的长度
	if (S.top == S.base) return 0;
	int len = 0;
	SElemType* p;
	for (p = S.top; p > S.base; p--)
		len++;
	return len;
}

Status visit(SElemType e) {
	cout << e << "\t";
	return OK;
}

Status StackTraverse(SqStack S, Status(*visit)(SElemType)) {
	if (S.top == S.base) return ERROR;
	for (SElemType* p = S.top-1; p >= S.base; p--) 
		visit(*p);
	return OK;
}

void conversion() {
	//数制转换
	SqStack S;
	InitStack(S);
	int N;
	scanf_s("%d", &N);
	while (N) {
		Push(S, N % 8);
		N /= 8;
	}
	int e;
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
}
/*
Status clarity(SqList L) {
	//括号匹配检查
	//L中存放需要检查的表达式
	SqStack S;
	InitStack(S);
	SElemType e1, e2;
	int i;
	for (i = 1; i <= ListLength(L); i++) {
		GetElem(L, i, e1);
		if ((e1 == '(') || (e1 == '[')) Push(S, e1);
		else if((e1==')')||(e1==']'))
			if((Pop(S,e2)==ERROR) || (e1 == ')'&&e2!='(')||(e1==']'&&e2!='['))
				return ERROR;
	}
	if (StackEmpty(S)) return OK;
	else return ERROR;
}
*/
