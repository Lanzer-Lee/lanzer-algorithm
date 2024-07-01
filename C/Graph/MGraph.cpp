#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
//-----图的数组（邻接矩阵）存储表示-----
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20		//最大顶点个数
typedef int VRType;
typedef int InfoType;
typedef int VertexType;
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef struct ArcCell {
	VRType adj;				//顶点关系类型。对无权图用1或0表示相邻否；对带权图，则为权值类型
	InfoType* info;			//该弧相关信息的指针
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];	//顶点向量
	AdjMatrix arcs;						//邻接矩阵
	int vexnum, arcnum;					//图当前顶点数和弧数
	GraphKind kind;						//图的种类标志
}MGraph;

int LocateVex(MGraph G, int v) {
	if (v <= 0) return OVERFLOW;
	return v - 1;
}

Status CreateUDN(MGraph& G) {
	//采用数组（邻接矩阵）表示法，构造无向网G
	int IncInfo, v1, v2, w, i, j, k;
	scanf_s("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);
	for (i = 0; i < G.vexnum; ++i)
		scanf_s("%d", & G.vexs[i]);
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = { INFINITY,NULL };
	for (k = 0; k < G.arcnum; ++k) {
		scanf_s("%d%d%d", &v1, &v2, &w);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		if (IncInfo) scanf_s("&d", G.arcs[i][j].info);
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}//CreateUDN

Status CreateUDG(MGraph& G) {
	//采用数组（邻接矩阵）表示法，构造无向图G
	int IncInfo, v1, v2, i, j, k;
	scanf_s("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);
	for (i = 0; i < G.vexnum; ++i)
		scanf_s("%d", &G.vexs[i]);
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = { 0,NULL };
	for (k = 0; k < G.arcnum; ++k) {
		scanf_s("%d%d", &v1, &v2);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;
		if (IncInfo) scanf_s("&d", G.arcs[i][j].info);
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

Status CreateDN(MGraph& G) {
	//采用数组（邻接矩阵）表示法，构造有向网G
	int IncInfo, v1, v2, w, i, j, k;
	scanf_s("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);
	for (i = 0; i < G.vexnum; ++i)
		scanf_s("%d", &G.vexs[i]);
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = { INFINITY,NULL };
	for (k = 0; k < G.arcnum; ++k) {
		scanf_s("%d%d%d", &v1, &v2, &w);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		if (IncInfo) scanf_s("&d", G.arcs[i][j].info);
	}
	return OK;
}

Status CreateDG(MGraph& G) {
	//采用数组（邻接矩阵）表示法，构造有向图G
	int IncInfo, v1, v2, i, j, k;
	scanf_s("%d%d%d", &G.vexnum, &G.arcnum, &IncInfo);
	for (i = 0; i < G.vexnum; ++i)
		scanf_s("%d", &G.vexs[i]);
	for (i = 0; i < G.vexnum; ++i)
		for (j = 0; j < G.vexnum; ++j)
			G.arcs[i][j] = { 0,NULL };
	for (k = 0; k < G.arcnum; ++k) {
		scanf_s("%d%d", &v1, &v2);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = 1;
		if (IncInfo) scanf_s("&d", G.arcs[i][j].info);
	}
	return OK;
}

Status CreateGraph(MGraph& G) {
	//采用数组（邻接矩阵）表示法，构造图G
	scanf_s("%d", &G.kind);
	switch (G.kind) {
	case DG:return CreateDG(G);
	case DN:return CreateDN(G);
	case UDG:return CreateUDG(G);
	case UDN:return CreateUDN(G);
	default:return ERROR;
	}
}

