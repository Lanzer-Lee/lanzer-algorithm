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
//-----数组的顺序存储表示-----
#define MAX_ARRAY_DIM 8		//假设数组维数最大值为8
typedef struct {
	ElemType* base;		//数组元素基址
	int dim;			//数组维数
	int* bounds;		//数组维界基址
	int* constants;		//数组映像函数常量基址
}Array;

typedef ElemType mat[20][10];

//-----基本操作的算法描述-----

Status InitArray(Array& A, int dim,...) {
	//若维数dim和各维长度合法，则构造相应的数组A，并返回OK
	if (dim<1 || dim>MAX_ARRAY_DIM) return ERROR;
	A.dim = dim;
	A.bounds = (int*)malloc(dim * sizeof(int));
	if (!A.bounds) exit(OVERFLOW);
	//若各维长度合法，则存入A.bounds,并求出A的元素总数elemtotal
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
	//求映像函数的常数c[i],并存入A.constants[i-1],1,...,dim
	A.constants = (int*)malloc(dim * sizeof(int));
	if (!A.constants) exit(OVERFLOW);
	A.constants[dim - 1] = 1;
	for (int i = dim - 2; i >= 0; --i)
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];
	return OK;
}

Status DestroyArray(Array& A) {
	//销毁数组A
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
	//若ap指示的各下标值合法，则求出该元素在A中相对地址off
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
	//A是n维数组，随后是n个下标值
	//若各下标不超界，则返回指定的A的元素值
	va_list ap;
	int off, result;
	va_start(ap, A);
	if ((result = Locate(A, ap, off)) <= 0) return result;
	return *(A.base + off);
}

Status Assign(Array& A, ElemType e, ...) {
	//A是n维数组，e为元素变量，随后是n个下标值
	//若下标不超界，则将e的值赋给所指定的A的元素，并返回OK
	va_list ap;
	int result, off;
	va_start(ap, e);
	if ((result = Locate(A, ap, off)) <= 0) return result;
	*(A.base + off) = e;
	return OK;
}

//-----测试-----
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
