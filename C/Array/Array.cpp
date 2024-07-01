#include<iostream>
#include<stdlib.h>
#include<stdarg.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0;
#define INFEASIBLE -1

using namespace std;
typedef int Status;
typedef int ElemType;
//-----�����˳��洢��ʾ-----
#define MAX_ARRAY_DIM 8		//��������ά�����ֵΪ8
typedef struct {
	ElemType* base;		//����Ԫ�ػ�ַ
	int dim;			//����ά��
	int* bounds;		//����ά���ַ
	int* constants;		//����ӳ����������ַ
}Array;

typedef ElemType mat[20][10];

//-----�����������㷨����-----

Status InitArray(Array& A, int dim,...) {
	//��ά��dim�͸�ά���ȺϷ���������Ӧ������A��������OK
	if (dim<1 || dim>MAX_ARRAY_DIM) return ERROR;
	A.dim = dim;
	A.bounds = (int*)malloc(dim * sizeof(int));
	if (!A.bounds) exit(OVERFLOW);
	//����ά���ȺϷ��������A.bounds,�����A��Ԫ������elemtotal
	int elemtotal = 1;
	va_list ap;
	va_start(ap, dim);
	for (int i = 0; i < dim; ++i) {
		A.bounds[i] = va_arg(ap, int);
		if (A.bounds[i] < 0) return UNDERFLOW;
		elemtotal *= A.bounds[i];
	}
	va_end(ap);
	A.base = (ElemType*)malloc(elemtotal * sizeof(ElemType));
	if (!A.base) exit(OVERFLOW);
	//��ӳ�����ĳ���c[i],������A.constants[i-1],1,...,dim
	A.constants = (int*)malloc(dim * sizeof(int));
	if (!A.constants) exit(OVERFLOW);
	A.constants[dim - 1] = 1;
	for (int i = dim - 2; i >= 0; --i)
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];
	return OK;
}

Status DestroyArray(Array& A) {
	//��������A
	if (!A.base) return ERROR;
	free(A.base);
	A.base = NULL;
	if (!A.bounds) return ERROR;
	free(A.bounds);
	A.bounds = NULL;
	if (!A.constants) return ERROR;
	free(A.constants);
	A.constants = NULL;
	return OK;
}

Status Locate(Array A, va_list ap, int& off) {
	//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A����Ե�ַoff
	off = 0;
	int ind;
	for (int i = 0; i < A.dim; ++i) {
		ind = va_arg(ap,int);
		if (ind < 0 || ind >= A.bounds[i]) return OVERFLOW;
		off += A.constants[i] * ind;
	}
	return OK;
}

ElemType Value(Array A, ...) {
	//A��nά���飬�����n���±�ֵ
	//�����±겻���磬�򷵻�ָ����A��Ԫ��ֵ
	va_list ap;
	int off, result;
	va_start(ap, A);
	if ((result = Locate(A, ap, off)) <= 0) return result;
	return *(A.base + off);
}

Status Assign(Array& A, ElemType e, ...) {
	//A��nά���飬eΪԪ�ر����������n���±�ֵ
	//���±겻���磬��e��ֵ������ָ����A��Ԫ�أ�������OK
	va_list ap;
	int result, off;
	va_start(ap, e);
	if ((result = Locate(A, ap, off)) <= 0) return result;
	*(A.base + off) = e;
	return OK;
}

//-----����-----
int main() {
	Array mat1;
	InitArray(mat1, 2, 3, 3);
	int k = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Assign(mat1, k, i, j);
			k++;
		}
	}
	ElemType e = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << Value(mat1, i, j) << '\t';
		}
		cout << endl;
	}
	return 0;
}
