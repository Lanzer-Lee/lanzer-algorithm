#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
//-----二叉树的二叉线索存储表示-----
typedef enum PointerTag{Link,Thread};
typedef int TElemType;
typedef struct BiThrNode {
	TElemType data;
	struct BiThrNode* lchild, * rchild;
	PointerTag LTag, RTag;
}BiThrNode,*BiThrTree;

Status visit(TElemType e) {
	printf("%d\t", e);
	return OK;
}
//-----基本操作实现-----
Status InOrderTravese_Thr(BiThrTree T, Status(*visit)(TElemType e)) {
	//非递归中序遍历二叉线索树
	BiThrTree p = T->lchild;
	while (p != T) {
		while (p->LTag == Link) p = p->lchild;
		if (!visit(p->data)) return ERROR;
		while (p->RTag == Thread && p->rchild != T) {
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
	return OK;
}//InOrderTravese_Thr

void InThreading(BiThrTree p,BiThrTree &pre) {
	if (p) {
		InThreading(p->lchild,pre);
		if (!p->lchild) {
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild) {
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;
		InThreading(p->rchild,pre);
	}
}