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

//��ȻLinkList������һ���׵�ַ����û�пռ�
//ͷ���һ�㲻�洢���ݣ�����־��ͷ��β���洢
//����ͷ���Ϊͳһ�ձ���ǿձ�Ĳ��������������
//��Ϊ�ձ�,head->next=NULL

Status CreateList_L(LinkList& L, int n){
	//((��λ��))����n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) return ERROR;
	L->next = NULL;
	LinkList p;									
	for (int i = n; i > 0; --i) {
		p = (LinkList)malloc(sizeof(LNode));	//�����½��
		if (!p) return ERROR;
		scanf_s("%d", &p->data);				//����Ԫ��ֵ
		p->next = L->next;						//���뵽��ͷ
		L->next = p;
	}
	return OK;
}//CreateList_L

Status GetElem_L(LinkList L, int i, ElemType& e){
	//LΪ��ͷ���ĵ������ͷָ��
	//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	LinkList p = L->next;			//��ʼ����pָ���һ����㣬jΪ������
	int j = 1;
	while (p && j < i) {			//˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
		p = p->next;
		++j;
	}
	if (!p || j > i)return ERROR;	//��i��Ԫ�ز�����
	e = p->data;					//ȡ��i��Ԫ��
	return OK;
}//GetElem_L

Status ListInsert_L(LinkList& L, int i, ElemType e){
	//�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1) {						//Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return ERROR;				//iС��1���ߴ��ڱ���1
	LinkList s = (LinkList)malloc(sizeof(LNode));	//�����½��
	if (!s) return ERROR;
	s->data = e;
	s->next = p->next;								//����L��
	p->next = s;
	return OK;
}//ListInsert_L

Status ListDelete_L(LinkList& L, int i, ElemType& e) {
	//�ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p = L;
	int j = 0;
	while (p->next && j < i - 1) {				//Ѱ�ҵ�i����㣬����pָ����ǰ��
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return ERROR;	//ɾ��λ�ò�����
	LinkList q = p->next;
	p->next = q->next;							//ɾ�����ͷŽ��
	e = q->data;
	free(q);
	return OK;
}//ListDelete_L

void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc) {
	//��֪�������Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ�ذ�ֵ�ǵݼ�����
	LinkList pa = La->next, pb = Lb->next, pc;
	Lc = pc = La;						//��La��ͷ�����ΪLc��ͷ���
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
	pc->next = pa ? pa : pb;			//����ʣ���
	free(Lb);							//�ͷ�Lb��ͷ���
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