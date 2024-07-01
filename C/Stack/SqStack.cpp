/*
* Stack��ջ��Ԫ��a1��ջ��Ԫ��an��ջ��Ϊtop��ջ��Ϊbottom
* ����ȳ�(Last In First Out,LIFO)
* 
* ��Ϊbase==top��ջ�ձ�־������topָ��ֻ��ָʾ������ջ��Ԫ��
* ֮�ϵ�����Ԫ�ص��±��ַ���������ì�ܣ�
* 
* ջ��ʱ������������||�����¿ռ�
*/
#include<iostream>
#include<stdlib.h>

#define STACK_INIT_SIZE 100	//��������
#define STACKINCREMENT 10	//����
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
	//����һ����ջ
	S.base=(SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;					//��ջ��־
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}//InitStack

Status GetTop(SqStack S, SElemType& e) {
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base) return ERROR;
	e = *(S.top - 1);
	return OK;
}//GetTop

Status Push(SqStack& S, SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
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
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
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
	//����S��Ԫ�ظ�������ջ�ĳ���
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
	//����ת��
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
	//����ƥ����
	//L�д����Ҫ���ı��ʽ
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
