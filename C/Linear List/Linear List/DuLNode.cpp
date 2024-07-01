#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define true 1
#define false 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLinkList;

DuLinkList GetElemP_DuL(DuLinkList L, int i) {
	DuLinkList p = L;
	for (int j = 0; j < i; j++) {
		p = p->next;
	}
	return p;
}

Status ListInsert_DuL(DuLinkList& L, int i, ElemType e) {
	//在带头结点的双循环线性表L中第i各位置之前插入元素e
	//i的合法值为1<=i<=表长+1
	DuLinkList s, p;
	if (!(p = GetElemP_DuL(L, i)))			//在L中确定插入位置
		return ERROR;						//p=NULL，即插入位置合法
	if (!(s = (DuLinkList)malloc(sizeof(DuLNode)))) return ERROR;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}//ListInsert_DuL

Status ListDelete_DuL(DuLinkList& L, int i, ElemType& e) {
	//删除带头结点的双链循环线性表L的第i个元素，i的合法值为1<=i<=表长
	DuLinkList p;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;
	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return OK;
}//ListDelete_DuL