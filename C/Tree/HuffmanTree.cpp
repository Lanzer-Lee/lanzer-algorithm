#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXVALUE 32767		//����ֵ�൱�������
#define NODENUM 10			//Ҷ�ӽ����
typedef struct
{
	char data;				//������
	int weight;				//����Ȩֵ
	int parent, lch, rch;	//˫���뺢�ӵ��±�
}htNode, * huffmanTree;

typedef char** huffmanCode;	//��һ��*�Ǵ�������ָ�������˵����������
							//�ڶ���*˵������ָ�����飬�������char����������ÿ��Ԫ�ض���*huffmanCode����

int initHuffmanTree(huffmanTree& HT);								//��ʼ����������
void creatHuffmanTree(huffmanTree& HT, int n);						//������������
void createHuffmanCode(huffmanTree HT, huffmanCode& HC, int n);		//��д����������
int main()
{
	huffmanTree HT;
	initHuffmanTree(HT);
	huffmanCode HC;
	creatHuffmanTree(HT, NODENUM);
	createHuffmanCode(HT, HC, NODENUM);
	/*for (int i = NODENUM + 1; i <= 2 * NODENUM - 1; i++)
		printf("%d ", HT[i].weight);*/
	for (int i = 1; i <= NODENUM; i++)								//�����������
	{
		printf("%c:\t", HT[i].data);
		printf("%s\n", HC[i]);
	}
	return 0;
}
int initHuffmanTree(huffmanTree& HT)
{
	HT = (htNode*)malloc(sizeof(htNode) * (2 * NODENUM));			//��HT����2 * NODENUM��htNOde��С��htNode���͵�����
	for (int i = 1; i <= 2 * NODENUM - 1; i++)						//�±��1��ʼ��2 * NODENUM
	{
		HT[i].parent = HT[i].lch = HT[i].rch = -1;					//˫�׺ͺ��ӵ�ֵ����Ϊ-1
	}
	printf("please input some weight!\n");
	for (int i = 1; i <= NODENUM; i++)								//Ȩֵֻ��1-n��
	{
		scanf("%d", &HT[i].weight);									//��ÿ����㸳��Ȩֵ
	}
	char c = getchar();											//�������������Ļس�
	printf("please input some data!\n");
	for (int i = 1; i <= NODENUM; i++)
	{
		//scanf("%c ",&HT[i].data);
		char a = getchar();
		if (a == '\n')												//�����س��ͽ���
			break;
		else
			HT[i].data = a;											//��ÿ����㸳������
	}

	return 1;
}

void creatHuffmanTree(huffmanTree& HT, int n)
{
	if (n <= 1)															//��������С�ڵ���1��������
		return;
	int min1, min2;														//���������������洢ÿ��ѡȡ��С��������Ȩֵ
	int rnode, lnode;													//���������±�ֵ�����洢ÿ��ѡȡ��С���������±�
	for (int i = n + 1; i <= 2 * n - 1; i++)								//Ҫ����n-1����㣬����Ҫ����n��1���Ҵ��±�Ϊn+1��ʼ�洢
	{
		int min1 = MAXVALUE; int lnode = -1;							//����Сֵ��ʼ��Ϊ����ֵ������Ҷ�ӽ������ֵ�ٴ�Ҳ���ᳬ�����ֵ��							
		int min2 = MAXVALUE; int rnode = -1;
		for (int j = 1; j <= i - 1; j++)								//��Ϊ��������ǰn����ѡ����С����������Ȩֵ����������һ����͵���ǰn+1����ѡ����С����������Ȩֵ							
		{																//����n = 10 �ܽ�����͵�Ϊ19�������Ǿ�ֻҪ�Ƚ�18�ξͿ��Եó�����ˣ���ס�ȽϵĴ��������ɵ��ܽ������1
			if (HT[j].weight < min1 && HT[j].parent == -1)			//���С�ھ�ʹ�õ�������ͬ��Ȩֵʱ���ȿ����ȳ��ֵ�ֵ�����Լ�����
			{
				min2 = min1;	rnode = lnode;						//������min1С�ģ���min1��ֵ�͸��ڶ�С��min2���±�Ҳ����
				min1 = HT[j].weight; lnode = j;						//Ȼ����С�ĸ�min1���±�ͬ��
			}
			else if (HT[j].weight < min2 && HT[j].parent == -1)		//���ǵڶ�С���ж�
			{
				min2 = HT[j].weight;
				rnode = j;
			}
		}
		HT[lnode].parent = HT[rnode].parent = i;						//��С��������parent��Ϊ���ɽ����±�
		HT[i].lch = lnode; HT[i].rch = rnode;							//���ɽ�������Ϊ��С��min1���±꣬�Һ���ͬ��
		HT[i].weight = HT[lnode].weight + HT[rnode].weight;				//���ɽ���Ȩֵ������С����Ȩֵ���
	}

}

void createHuffmanCode(huffmanTree HT, huffmanCode& HC, int n)
{
	HC = (huffmanCode)malloc(sizeof(huffmanCode) * n + 1);				//����n + 1��huffmanCode��СhuffmanCode���͵���ʱ�ռ�
																		//��Ϊ�±��Ǵ�һ��ʼ����������Ҫ����Ƚ���һ���Ľ�㣬�͹��������Ľṹ��Ӧ���������
	char* cd = (char*)malloc(sizeof(char) * n);							//����n��char��Сchar���͵���ʱ�ռ䣬�����ʱ�����¼ÿ�α��������ı���
	int start = 0, c = 0, f = 0;											//startΪcd�����¼�±꣬c��ʼΪҶ�ӽ���±꣬������Ǻ��ӽ����±꣬f��¼˫�׽����±�
	cd[n - 1] = '\0';													//������Ǹ�printf���ŵģ���Ϊprintf��������'\0'�������puts�Ͳ�����������
	for (int i = 1; i <= n; i++)										//ֻҪҶ�ӽ��ı���
	{
		start = n - 1;													//���Ҫ��ֵn�Ļ���start--Ҫд���жϺ�
		c = i;
		f = HT[c].parent;
		while (f != -1)													//���ڵ�û��˫��
		{
			start--;
			if (HT[f].lch == c)											//�����Ӿ���0���Һ��Ӿ�Ϊ1
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f; f = HT[c].parent;									//������ӽ�
		}
		HC[i] = (char*)malloc(sizeof(char) * (n - start));				//�����������������n - start��char��С��char*���͵���ʱ�ռ�
		strcpy(HC[i], &cd[start]);										//cd���¼�ı����HC�ĵ�i������
	}
	free(cd);															//�ͷ���ʱ�ռ�
}
