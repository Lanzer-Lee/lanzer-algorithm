#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
//-----ͼ�����飨�ڽӾ��󣩴洢��ʾ-----
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20		//��󶥵����
typedef int VRType;
typedef int InfoType;
typedef int VertexType;
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef struct ArcCell {
	VRType adj;				//�����ϵ���͡�����Ȩͼ��1��0��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ����
	InfoType* info;			//�û������Ϣ��ָ��
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];	//��������
	AdjMatrix arcs;						//�ڽӾ���
	int vexnum, arcnum;					//ͼ��ǰ�������ͻ���
	GraphKind kind;						//ͼ�������־
}MGraph;

int LocateVex(MGraph G, int v) {
	if (v <= 0) return OVERFLOW;
	return v - 1;
}

Status CreateUDN(MGraph& G) {
	//�������飨�ڽӾ��󣩱�ʾ��������������G
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
	//�������飨�ڽӾ��󣩱�ʾ������������ͼG
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
	//�������飨�ڽӾ��󣩱�ʾ��������������G
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
	//�������飨�ڽӾ��󣩱�ʾ������������ͼG
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
	//�������飨�ڽӾ��󣩱�ʾ��������ͼG
	scanf_s("%d", &G.kind);
	switch (G.kind) {
	case DG:return CreateDG(G);
	case DN:return CreateDN(G);
	case UDG:return CreateUDG(G);
	case UDN:return CreateUDN(G);
	default:return ERROR;
	}
}

