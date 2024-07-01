#include<iostream>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
using namespace std;
		//=====ADT String �ı�ʾ��ʵ��
//-----���Ķѷ���洢��ʾ-----
typedef int Status;
typedef struct {
	char* ch;
	int length;
}HString;

//-----�����������㷨����-----
Status StrAssign(HString& T, char* chars) {
	//����һ����ֵ���ڴ�����chars�Ĵ�T
	//if (T.ch) free(T.ch);
	int i;
	char* c;
	for (i = 0, c = chars; *c; ++i, ++c);
	if (!i) { T.ch = NULL; T.length = 0; }
	else {
		if (!(T.ch = (char*)malloc(i * sizeof(char))))
			exit(OVERFLOW);
		for (int j = 0; j < i; j++)
			T.ch[j] = chars[j];
		T.length = i;
	}
	return OK;
}//StrAssign

int StrLength(HString S) {
	//����S��Ԫ�ظ�������Ϊ���ĳ���
	return S.length;
}//StrLength

int StrCompare(HString S, HString T) {
	//��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0����S<T,�򷵻�ֵ<0
	for (int i = 0; i < S.length && i < T.length; ++i)
		if (S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.length - T.length;
}//StrCompare

Status ClearString(HString& S) {
	//��S��Ϊ�մ�
	if (S.ch) { free(S.ch); S.ch = NULL; }
	S.length = 0;
	return OK;
}//ClearString

Status Concat(HString& T, HString S1, HString S2) {
	//��T������S1��S2���Ӷ��ɵ��´�
	//if (T.ch) free(T.ch);
	if (!(T.ch = (char*)malloc((S1.length + S2.length) * sizeof(char))))
		exit(OVERFLOW);
	for (int j = 0; j < S1.length; j++)
		T.ch[j] = S1.ch[j];
	T.length = S1.length + S2.length;
	for (int j = 0; j < S2.length; j++)
		T.ch[S1.length + j] = S2.ch[j];
	return OK;
}//Concat

Status SubString(HString& Sub, HString S, int pos, int len) {
	//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
	//����,1<=pos<=StrLength(S)&&0<=len<=StrLength(S)-pos+1
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return ERROR;
	//if (Sub.ch) free(Sub.ch);
	if (!len) { Sub.ch = NULL; Sub.length = 0; }
	else {
		Sub.ch = (char*)malloc(len * sizeof(char));
		if (!Sub.ch) exit(OVERFLOW);
		for (int i = 0; i < len; i++)
			Sub.ch[i] = S.ch[pos + i - 1];
		Sub.length = len;
	}
	return OK;
}//SubString


//���´���������
int Index(HString S, HString T, int pos) {
	//�����Ӵ�T������S�е�pos���ַ�֮���λ�ã��������ڣ�����ֵΪ0
	//���У�T�ǿգ�1<=pos<=StrLength(S)
	int i = pos-1, j = 0;
	while (i < S.length && j < T.length) {
		if (S.ch[i] == T.ch[j]) { ++i; ++j; }
		else { i = i - j + 2; j = 0; }
	}
	if (j >= T.length) return i - T.length+1;
	else return 0;
}

void get_next(HString T, int next[]) {
	//��ģʽ��T��next����ֵ����������next
	int i = 1, j = 0;
	next[1] = 0;
	j = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}//get_next

Status StrPrint(HString S) {
	char* p;
	for (p = S.ch; p < S.ch + S.length; p++)
		printf("%c", *p);
	printf("\n");
	return OK;
}

int Index_KMP(HString S, HString T, int pos,int next[]) {
	//����ģʽ��T�е�next������T������S�е�pos���ַ�֮���λ�õ�
	//KMP�㷨�����У�T�ǿգ�1<=pos<=StrLength(S)
	int i = pos, j = 1;
	while (j <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) { ++i; ++j; }
		else j = next[j];
	}
	if (j > T.length) return i - T.length;
	else return 0;
}//Index_KMP

int main() {
	HString JingWei1, JingWei2, JingWei3;
	char str1[20] = "Love";
	char str2[20] = "JingWei";
	StrAssign(JingWei1, str1);
	StrAssign(JingWei2, str2);
	StrPrint(JingWei1);
	StrPrint(JingWei2);
	printf("%d\n", StrCompare(JingWei1, JingWei2));
	Concat(JingWei3, JingWei1, JingWei2);
	StrPrint(JingWei3);

	
	return 0;
}