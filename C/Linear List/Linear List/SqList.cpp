#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 5
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define true 1
#define false 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;

//构造一个空的顺序表 
Status InitList(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//返回L中数据元素个数 
int ListLength(SqList& L) {
	return L.length;
}
//销毁线性表L 
Status DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}
//判断线性表L是否为空表
Status ListEmpty(SqList& L) {
	if (L.length == 0) return true;
	else return false;
}
//将表的第i个元素返回给e
Status GetElem(SqList& L, int i, ElemType& e) {
	if (i <= 0 || i > L.length) exit(OVERFLOW);
	e = L.elem[i - 1];
	return OK;
}
//关系函数
Status compare(ElemType x, ElemType y) {
	if (x > y) return 1;
	else if (x = y) return 0;
	else return -1;
}
//返回表中第一个与e满足关系compare的元素序号
int LocateElem(SqList L, ElemType& e, Status(*compare)(ElemType, ElemType)) {
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return -1;
}
//返回cur_e的前驱
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	if (L.elem[0] == cur_e) return ERROR;
	for (int i = 1; i < L.length; i++) 
		if (L.elem[i] == cur_e) { pre_e = L.elem[i - 1]; return OK;}
	return ERROR;
}
//向表中第i个元素位置插入e
Status ListInsert(SqList& L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1) return ERROR;
	if (L.length >= L.listsize) {
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType* q = &(L.elem[i - 1]);
	for (ElemType* p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return OK;
}
//用next_x返回cur_e的后继
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e)
{
	if (L.elem[L.length - 1] == cur_e) return ERROR;
	for(int i=0;i<L.length-1;i++)
		if (L.elem[i] == cur_e) { next_e = L.elem[i + 1]; return OK; }
	return ERROR;
}
//删除L中第i个数据元素，并用e返回其值，L长度减1
Status ListDelete(SqList& L, int i, ElemType& e)
{
	if (i<1 || i>L.length) return ERROR;
	ElemType* p = &(L.elem[i - 1]);
	e = *p;
	ElemType* q = L.elem + L.length - 1;
	for (++p; p <= q; ++p) *(p - 1) = *p;
	--L.length;
	return OK;
}
//访问函数
Status visit(ElemType &x)
{
	x++;
	if (x < 1000) return OK;
	return ERROR;
}
//依次对L的每个数据元素调用visit(),若调用失败，则操作失败
Status ListTraverse(SqList L, Status (*visit)(ElemType&))
{
	for (int i = 0; i < L.length; i++)
		if (!visit(L.elem[i])) return ERROR;
	return OK;
}
//归并La、Lb到Lc，按非递减序列
void MergeList(SqList La, SqList Lb, SqList& Lc)
{
	//已知La、Lb按值非递减序列
	ElemType* pa = La.elem;
	ElemType* pb = Lb.elem;
	Lc.listsize = Lc.length=La.length + Lb.length;
	ElemType* pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)exit(OVERFLOW);
	ElemType* pa_last = La.elem + La.length - 1;
	ElemType* pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa < *pb) *pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last) *pc++ = *pa++;
	while (pb <= pb_last) *pc++ = *pb++;
}

void MergeList2(SqList La, SqList Lb, SqList& Lc)
{
	InitList(Lc);
	int i = 1,j = 1, k = 0;
	ElemType ai, bj;
	int La_len = ListLength(La), Lb_len = ListLength(Lb);
	while ((i <= La_len) && (j <= Lb_len)) {
		GetElem(La, i, ai);
		GetElem(Lb, j, bj);
		if (ai < bj) { ListInsert(Lc, ++k, ai); ++i; }
		else { ListInsert(Lc, ++k, bj); ++j; }
	}
	while (i <= La_len) {
		GetElem(La, i++, ai); ListInsert(Lc, ++k, ai);
	}
	while (j <= Lb_len) {
		GetElem(Lb, j++, bj); ListInsert(Lc, ++k, bj);
	}
}

int main()
{
	SqList jw, ljy, lan;
	InitList(jw);
	InitList(ljy);
	InitList(lan);
	int i, e = 520;
	for (i = 0; i < 10; i++)
	{
		ListInsert(jw, i + 1, i + 1);
		ListInsert(ljy, i + 1, i + 11);
	}
	//for(i=0;i<10;i++)
	//	printf("%d\t", jw.elem[i]);
	//printf("\n");
	//for (i = 0; i < 10; i++)
	//	printf("%d\t", ljy.elem[i]);
	//printf("\n");
	MergeList2(jw, ljy, lan);
	for (i = 0; i < lan.length; i++)
		printf("%d\t", lan.elem[i]);
	return 0;
}

