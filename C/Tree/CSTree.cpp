#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----���Ķ�����������-�ֵܣ��洢��ʾ-----
typedef int ElemType;
typedef struct CSNode {
	ElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;