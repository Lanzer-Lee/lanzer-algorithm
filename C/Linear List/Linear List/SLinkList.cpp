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
#define MAXSIZE 1000	//链表的最大长度

typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE];

int LocateElem_SL(SLinkList S, ElemType e) {
	//在静态链表中查找第一个值为e的元素
	//若找到，则返回它在L中的位序，否则返回0；
	int i = S[0].cur;							//i表示表中第一个结点
	while (i && S[i].data != e) i = S[i].cur;	//在表中顺链查找
	return i;
}//LocateElem_SL

void InitSpace_SL(SLinkList& space) {
	//将一维数组space中各分量链成一个备用链表，space[0].cur为头指针
	//"0"表示空指针
	for (int i = 0; i < MAXSIZE - 1; ++i)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}//InitSpace_SL

int Malloc_SL(SLinkList& space) {
	//若备用空间链表非空，则返回分配的结点下标，否则返回0
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}//Malloc_SL

void Free_SL(SLinkList& space, int k) {
	//将下标为k的空闲结点回收到备用链表
	space[k].cur = space[0].cur;
	space[0].cur = k;
}//Free_SL

void difference(SLinkList& space, int& S) {
	//依次输入集合A和B的元素，在一维数组space中建立表示集合(A-B)∪(B-A)
	//的静态链表，S为其头指针。假设备用空间足够大，space[0].cur为其头指针
	InitSpace_SL(space);				//初始化备用空间
	S = Malloc_SL(space);				//生成S头结点
	int r = S, m, n, i, b, p, k;		//r指向S的当前最后结点
	scanf_s("%d%d", &m, &n);			//输入A和B的元素个数
	for (int j = 1; j <= m; ++j) {		//建立集合A的链表
		i = Malloc_SL(space);			//分配结点
		scanf_s("%d",&space[i].data);	//输入A的元素值
		space[r].cur = i;				//插入到表尾
		r = i;
	}//for								
	space[r].cur = 0;					//尾结点的指针为空		
	for (int j = 1; j <= n; ++j) {		//依次输入B的元素，若不在当前表中，则插入，否则删除
		scanf_s("%d", &b);
		p = S;
		k = space[S].cur;				//k指向集合A中第一个结点
		while (k != space[r].cur && space[k].data != b) {//在当前表中查找
			p = k;
			k = space[k].cur;
		}//while
		if (k == space[r].cur) {		//当前表中不存在该元素，插入在r所指结点之后，且r位置不变
			i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}//if
		else {							//该元素已在表中，删除之
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if (r == k) r = p;			//若删除的是r所指结点，则需修改尾指针
		}//else
	}//for
}//difference