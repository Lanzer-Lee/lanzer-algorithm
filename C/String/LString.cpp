//-----���Ŀ����洢��ʾ-----
#define CHUNKSIZE 80
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct {
	Chunk* head, * tail;
	int curlen;
}LString;