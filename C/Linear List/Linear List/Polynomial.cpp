#include<stdio.h>
#include<stdlib.h>
#include "LinkList2.cpp"
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define true 1
#define false 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

typedef struct {
	float coef;
	int expn;
}term,ElemType;

typedef LinkList polynomial;

void CreatPolyn(polynomial& P, int m) {
	//输入m项的系数和指数，建立表示一元多项式的有序链表P
	InitList(P);
	Link h = GetHead(P);
	term e;
	e.coef = 0.0;
	e.expn = -1;
	SetCurElem(h, e);
	for (int i = 2; i <= m; ++i) {
		scanf_s("%f%d", &e.coef, &e.expn);
		if (!LocateElem(P, e, q, (*cmp)())) {
			if (MakeNode(s, e))
				InsFirst(q, s);
		}
	}
}