#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define true 1
#define false 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;

//显然LinkList构建了一个首地址，但没有空间
//头结点一般不存储数据，仅标志表头，尾结点存储
//设置头结点为统一空表与非空表的操作，简化链表操作
//若为空表,head->next=NULL

Status CreateList_L(LinkList& L, int n){
	//((逆位序))输入n个元素的值，建立带表头结点的单链线性表
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) return ERROR;
	L->next = NULL;
	LinkList p;									
	for (int i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));	//生成新结点
		if (!p) return ERROR;
		scanf_s("%d", &p->data);				//输入元素值
		p->next = L->next;						//插入到表头
		L->next = p;
	}
	return OK;
}//CreateList_L

Status GetElem_L(LinkList L, int i, ElemType& e){
	//L为带头结点的单链表的头指针
	//当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
	LinkList p = L->next;			//初始化，p指向第一个结点，j为计数器
	int j = 1;
	while (p && j < i) {			//顺指针向后查找，直到p指向第i个元素或p为空
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;	//第i个元素不存在
	e = p->data;					//取第i个元素
	return OK;
}//GetElem_L

Status ListInsert_L(LinkList& L, int i, ElemType e){
	//在带头结点的单链线性表L中第i个位置之前插入元素e
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1) {						//寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;				//i小于1或者大于表长加1
	LinkList s = (LinkList)malloc(sizeof(LNode));	//生成新结点
	if (!s) return ERROR;
	s->data = e;
	s->next = p->next;								//插入L中
	p->next = s;
	return OK;
}//ListInsert_L

Status ListDelete_L(LinkList& L, int i, ElemType& e) {
	//在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1) {				//寻找第i个结点，并令p指向其前驱
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;	//删除位置不合理
	LinkList q = p->next;
	p->next = q->next;							//删除并释放结点
	e = q->data;
	free(q);
	return OK;
}//ListDelete_L

void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc) {
	//已知单链线性表La和Lb的元素按值非递减排列
	//归并La和Lb得到新的单链线性表Lc，Lc的元素按值非递减排列
	LinkList pa = La->next, pb = Lb->next, pc;
	Lc = pc = La;						//用La的头结点作为Lc的头结点
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;			//插入剩余段
	free(Lb);							//释放Lb的头结点
}//MergeList_L

/*
int main()
{
	LinkList jw, ljy, lan;
	int n = 5;
	CreateList_L(jw, n);
	CreateList_L(ljy, n);
	MergeList_L(jw, ljy, lan);
	ElemType temp;
	
	for (int i = 0; i < 10; i++) {
		GetElem_L(lan, i + 1, temp);
		printf("%d\t", temp);
	}
	
	
	return 0;
}
*/