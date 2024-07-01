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
//typedef int ElemType;

typedef struct {
	float coef;
	int expn;
}ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}*Link,*Position;

typedef struct {
	Link head, tail;
	int len;
}LinkList;

Status MakeNode(Link& p, ElemType e) {}

void FreeNode(Link& p) {}

Status InitList(LinkList& L){}

Status DestroyList(LinkList& L){}

Status ClearList(LinkList& L){}

Status InsFirst(Link h,Link s){}

Status DelFirst(Link h,Link& q){}

Status Append(LinkList& L,Link s){}

Status Remove(LinkList &L,Link &q){}

Status InsBefore(LinkList& L,Link& p,Link s){}

Status InsAfter(LinkList& L,Link& p,Link s){}

Status SetCurElem(Link& p,ElemType e){}

ElemType GetCurElem(Link p) {}

Status ListEmpty(LinkList L){}

int ListLength(LinkList L){}

Position GetHead(LinkList L){}

Position GetLast(LinkList L){}

Position PriorPos(LinkList L,Link p){}

Position NextPos(LinkList L,Link p){}

Status LocatePos(LinkList L,int i,Link& p){}

Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)){}

Status ListTraverse(LinkList L,Status(*visit)()){}

Status ListInsert_L(LinkList& L, int i, ElemType e) {
	//在带头结点的单链线性表L的第i个元素之前插入元素e
	Link s,h;
	if (!LocatePos(L, i - 1, h)) return ERROR;
	if (!MakeNode(s, e)) return ERROR;
	InsFirst(h, s);
	return OK;
}//ListInsert_L

Status MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc, int(*compare)(ElemType, ElemType)) {
	//已知单链线性表La和Lb的元素按值非递减排列
	//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列
	if (!InitList(Lc)) return ERROR;
	Link ha = GetHead(La), hb = GetHead(Lb);
	Link pa = NextPos(La, ha), pb = NextPos(Lb, hb);
	ElemType a, b;
	Link q;
	while (pa && pb) {
		a = GetCurElem(pa);
		b = GetCurElem(pb);
		if ((*compare)(a, b) <= 0) {
			DelFirst(ha, q);
			Append(Lc, q);
			pa = NextPos(La, ha);
		}
		else {
			DelFirst(hb, q);
			Append(Lc, q);
			pb = NextPos(Lb, hb);
		}
	}//while
	if (ha) Append(Lc, pa);
	else Append(Lc, pb);
	FreeNode(ha);
	FreeNode(hb);
	return OK;
}//MergeList_L

