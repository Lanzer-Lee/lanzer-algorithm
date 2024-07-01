#include<iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int Status;
typedef int QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue& Q) {
	//构造一个空队列Q
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue& Q) {
	//销毁队列Q
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return OK;
}

Status EnQueue(LinkQueue& Q, QElemType e) {
	//插入元素e为Q的新的队尾元素
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(LinkQueue& Q, QElemType& e) {
	//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK
	//否则返回ERROR
	if (Q.front == Q.rear) return ERROR;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	free(p);
	return OK;
}

Status ClearQueue(LinkQueue& Q) {
	//将Q清为空队列
	QElemType e;
	while (Q.front->next) 
		DeQueue(Q, e);
	return OK;
}

Status QueueEmpty(LinkQueue Q) {
	//若队列为空队列，返回TRUE，否则返回FALSE
	if (Q.front == Q.rear) return TRUE;
	return FALSE;
}

int QueueLength(LinkQueue Q) {
	//返回Q的元素个数，即为队列的长度
	int len = 0;
	for (QueuePtr p = Q.front; p->next; p = p->next) 
		len++;
	return len;
}

Status GetHead(LinkQueue Q, QElemType& e) {
	//若队列不空，用e返回Q的队头元素，并返回OK；否则返回ERROR
	if (Q.front == Q.rear) return ERROR;
	e = Q.front->next->data;
	return OK;
}

Status visit(QElemType x) {
	cout << x << "\t";
	return OK;
}

Status QueueTraverse(LinkQueue Q, Status(*visit)(QElemType)) {
	//从队头到队尾依次对队列Q中每个元素调用函数visit(),一旦visit失败，则操作失败
	if (Q.front == Q.rear) return ERROR;
	for (QueuePtr p = Q.front; p->next; p = p->next)
		visit(p->next->data);
	return OK;
}

int main()
{
	/*
	LinkQueue jw;
	QElemType lan;
	InitQueue(jw);
	for (int i = 1; i <= 10; i++) 
		EnQueue(jw, i);
	cout << QueueLength(jw) << endl;
	GetHead(jw, lan);
	cout << lan << endl;
	QueueTraverse(jw, visit);
	*/
	LinkQueue JingWei;
	InitQueue(JingWei);
	for (int i = 1; i <= 10; i++)
		EnQueue(JingWei, i);
	QueueTraverse(JingWei, visit);
	return 0;
}