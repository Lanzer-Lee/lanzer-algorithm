/*
#include"SqStack.cpp"
void conversion() {
	//对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
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
	//利用字符栈S，从终端接收一行并传送至调用过程的数据区
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