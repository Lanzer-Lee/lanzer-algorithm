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

//����һ���յ�˳��� 
Status InitList(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
//����L������Ԫ�ظ��� 
int ListLength(SqList& L) {
	return L.length;
}
//�������Ա�L 
Status DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	return OK;
}
//�ж����Ա�L�Ƿ�Ϊ�ձ�
Status ListEmpty(SqList& L) {
	if (L.length == 0) return true;
	else return false;
}
//����ĵ�i��Ԫ�ط��ظ�e
Status GetElem(SqList& L, int i, ElemType& e) {
	if (i <= 0 || i > L.length) exit(OVERFLOW);
	e = L.elem[i - 1];
	return OK;
}
//��ϵ����
Status compare(ElemType x, ElemType y) {
	if (x > y) return 1;
	else if (x = y) return 0;
	else return -1;
}
//���ر��е�һ����e�����ϵcompare��Ԫ�����
int LocateElem(SqList L, ElemType& e, Status(*compare)(ElemType, ElemType)) {
	int i = 1;
	ElemType* p = L.elem;
	while (i <= L.length && !(*compare)(*p++, e)) ++i;
	if (i <= L.length) return i;
	else return -1;
}
//����cur_e��ǰ��
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	if (L.elem[0] == cur_e) return ERROR;
	for (int i = 1; i < L.length; i++) 
		if (L.elem[i] == cur_e) { pre_e = L.elem[i - 1]; return OK;}
	return ERROR;
}
//����е�i��Ԫ��λ�ò���e
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
//��next_x����cur_e�ĺ��
Status NextElem(SqList L, ElemType cur_e, ElemType& next_e)
{
	if (L.elem[L.length - 1] == cur_e) return ERROR;
	for(int i=0;i<L.length-1;i++)
		if (L.elem[i] == cur_e) { next_e = L.elem[i + 1]; return OK; }
	return ERROR;
}
//ɾ��L�е�i������Ԫ�أ�����e������ֵ��L���ȼ�1
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
//���ʺ���
Status visit(ElemType &x)
{
	x++;
	if (x < 1000) return OK;
	return ERROR;
}
//���ζ�L��ÿ������Ԫ�ص���visit(),������ʧ�ܣ������ʧ��
Status ListTraverse(SqList L, Status (*visit)(ElemType&))
{
	for (int i = 0; i < L.length; i++)
		if (!visit(L.elem[i])) return ERROR;
	return OK;
}
//�鲢La��Lb��Lc�����ǵݼ�����
void MergeList(SqList La, SqList Lb, SqList& Lc)
{
	//��֪La��Lb��ֵ�ǵݼ�����
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

