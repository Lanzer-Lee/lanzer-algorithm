#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----树的孩子链表存储表示-----
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct CTNode {				//孩子结点
	int child;
	struct CTNode* next;
}*ChildPtr;
typedef struct {
	TElemType data;
	ChildPtr firstchild;			//孩子链表头指针
}CTBox;
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;						//结点数和根的位置
}CTree;

