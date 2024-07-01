#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----树的双亲表存储表示-----
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode {		//结点结构
	TElemType data;
	int parent;				//双亲位置域
};
typedef struct {					//树结构
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;						//根的位置和结点数
}PTree;