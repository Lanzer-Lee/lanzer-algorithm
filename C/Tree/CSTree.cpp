#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----树的二叉链表（孩子-兄弟）存储表示-----
typedef int ElemType;
typedef struct CSNode {
	ElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;