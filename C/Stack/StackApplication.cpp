/*
#include"SqStack.cpp"
void conversion() {
	//�������������һ���Ǹ�ʮ������������ӡ��������ֵ�İ˽�����
	SqStack S;
	InitStack(S);
	int N;
	scanf_s("%d", &N);
	while (N) {
		Push(S, N % 8);
		N /= 8;
	}
	SElemType e;
	while (!StackEmpty(S)) {
		Pop(S, e);
		printf("%d", e);
	}
}//concerse
*/
/*
* typedef char SElemType;
*/
/*
void LineEdit() {
	//�����ַ�ջS�����ն˽���һ�в����������ù��̵�������
	SqStack S;
	InitStack(S);
	char ch = getchar();
	while (ch != EOF) {
		while (ch != EOF && ch != '\n') {
			switch (ch) {
			case'#':Pop(S, ch); break;		//SElemType->char
			case'@':ClearStack(S); break;
			default:Push(S, ch); break;
			}
			ch = getchar();
		}
		ClearStack(S);
		if (ch != EOF) ch = getchar();
	}
	DestroyStack(S);
}
*/
/*
typedef int MazeType;
typedef int PosType;
typedef struct{
	int ord;
	PosType seat;
	int di;
}SElemType;

Status MazePath(MazeType maze, PosType start, PosType end) {

}
*/