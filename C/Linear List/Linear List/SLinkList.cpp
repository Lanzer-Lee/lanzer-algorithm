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
#define MAXSIZE 1000	//�������󳤶�

typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e) {
	//�ھ�̬�����в��ҵ�һ��ֵΪe��Ԫ��
	//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0��
	int i = S[0].cur;							//i��ʾ���е�һ�����
	while (i && S[i].data != e) i = S[i].cur;	//�ڱ���˳������
	return i;
}//LocateElem_SL

void InitSpace_SL(SLinkList& space) {
	//��һά����space�и���������һ����������space[0].curΪͷָ��
	//"0"��ʾ��ָ��
	for (int i = 0; i < MAXSIZE - 1; ++i)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}//InitSpace_SL

int Malloc_SL(SLinkList& space) {
	//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}//Malloc_SL

void Free_SL(SLinkList& space, int k) {
	//���±�Ϊk�Ŀ��н����յ���������
	space[k].cur = space[0].cur;
	space[0].cur = k;
}//Free_SL

void difference(SLinkList& space, int& S) {
	//�������뼯��A��B��Ԫ�أ���һά����space�н�����ʾ����(A-B)��(B-A)
	//�ľ�̬����SΪ��ͷָ�롣���豸�ÿռ��㹻��space[0].curΪ��ͷָ��
	InitSpace_SL(space);				//��ʼ�����ÿռ�
	S = Malloc_SL(space);				//����Sͷ���
	int r = S, m, n, i, b, p, k;		//rָ��S�ĵ�ǰ�����
	scanf_s("%d%d", &m, &n);			//����A��B��Ԫ�ظ���
	for (int j = 1; j <= m; ++j) {		//��������A������
		i = Malloc_SL(space);			//������
		scanf_s("%d",&space[i].data);	//����A��Ԫ��ֵ
		space[r].cur = i;				//���뵽��β
		r = i;
	}//for								
	space[r].cur = 0;					//β����ָ��Ϊ��		
	for (int j = 1; j <= n; ++j) {		//��������B��Ԫ�أ������ڵ�ǰ���У�����룬����ɾ��
		scanf_s("%d", &b);
		p = S;
		k = space[S].cur;				//kָ�򼯺�A�е�һ�����
		while (k != space[r].cur && space[k].data != b) {//�ڵ�ǰ���в���
			p = k;
			k = space[k].cur;
		}//while
		if (k == space[r].cur) {		//��ǰ���в����ڸ�Ԫ�أ�������r��ָ���֮����rλ�ò���
			i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}//if
		else {							//��Ԫ�����ڱ��У�ɾ��֮
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if (r == k) r = p;			//��ɾ������r��ָ��㣬�����޸�βָ��
		}//else
	}//for
}//difference