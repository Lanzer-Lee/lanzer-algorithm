#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----����˫�ױ�洢��ʾ-----
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode {		//���ṹ
	TElemType data;
	int parent;				//˫��λ����
};
typedef struct {					//���ṹ
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;						//����λ�úͽ����
}PTree;