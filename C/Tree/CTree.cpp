#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----���ĺ�������洢��ʾ-----
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct CTNode {				//���ӽ��
	int child;
	struct CTNode* next;
}*ChildPtr;
typedef struct {
	TElemType data;
	ChildPtr firstchild;			//��������ͷָ��
}CTBox;
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;						//������͸���λ��
}CTree;

