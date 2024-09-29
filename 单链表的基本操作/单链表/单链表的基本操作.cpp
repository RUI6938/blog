#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;			//������
	struct node* next;	//ָ����
}LinkNode;

LinkNode* InitList()
{
	//��ʼ��һ����ͷ��������
	LinkNode* temp = (LinkNode*)malloc(sizeof(LinkNode));
	temp->next = NULL;
	return temp;
}
int LinkEmpty(LinkNode* L)
{
	if (L)
	{
		return 1;
	}
	return 0;
}

int LinkInsert(LinkNode* L, int i, int e)
{
	//LΪ��¼ͷ����ָ��, iΪ����λ��, eΪ����Ԫ��
	LinkNode* temp = L;
	int count = 0;		//Ĭ�ϳ���Ϊ0
	while (temp->next && count < i - 1)
		//ȷ�� temp ָ���ƶ����� i-1 ������λ�ã���������ʿ�ָ�뵼�µĴ���
	{
		//Ѱ�ҵ�i�����,��ʹtempָ���i-1�����
		temp = temp->next;
		count++;
	}
	//����ѭ�����Ѿ�����i��count��ֵ���м���,count���ʱ����������,
	//��i-1����������ʱ,���޷�����i���(û��i������)
	if (!(temp) || count < i - 1)
	{
		///��i��λ�ò�����,�������ʾ������0
		printf(">>>����Խ��,������!\n");
		return 0;
	}
	//������ĵ�i��λ�ò����½��P
	LinkNode* P = (LinkNode*)malloc(sizeof(LinkNode));
	P->data = e;
	P->next = temp->next;		//��temp��һ������P�ĵ�ַ��
	temp->next = P;				//��P�ĵ�ַ��ֵ��temp�ĵ�ַ��
	return 1;					//�ɹ������򷵻�1
}

void LinkPrint(LinkNode* L)
{

	LinkNode* P = L->next;
	printf(">�����е�Ԫ��Ϊ:");
	while (P)
	{
		printf(" %d", P->data);
		P = P->next;
	}
	printf("\n");
}
int LinkLenght(LinkNode* L)
{
	LinkNode* temp = L;
	int len = 0;		//Ĭ�ϳ���Ϊ0
	while (temp->next)
	{
		temp = temp->next;
		len++;	//�����õ�������
	}
	return len;
}
int LinkDelect(LinkNode* L, int i) {
	LinkNode* temp = L;
	int count = 0;
	while (temp->next && count < i - 1)
	{
		//Ѱ�ҵ�i�����,��ʹtempָ���i-1�����
		temp = temp->next;
		count++;
	}
	if (!(temp->next) || count < i - 1)
	{
		///��i��λ�ò�����,�������ʾ������0
		printf(">ɾ��λ�ò�����,������!\n");
		return 0;
	}
	LinkNode* P = temp->next;//��ʱ�洢Ҫɾ�����ĵ�ַ,���ں����ͷ�
	temp->next = P->next;
	free(P);	//�ͷű�ɾ���ĵ�ַ
}
void LinkDestroy(LinkNode* L)
{
	LinkNode* P;
	while (L)//��LΪNULLʱֹͣ
	{
		P = L;
		L = L->next;
		free(P);
	}
}

int main()
{
	//����һ���ṹ�����ָ��
	LinkNode* L = InitList();
	printf("^�����ʼ���ɹ�.\n");
	printf("\n");

	//�ж������Ƿ�Ϊ��
	int flag = LinkEmpty(L);
	flag ? printf(">>>����Ϊ��\n") : printf(">>>����Ϊ��\n");
	printf("\n");

	//������Ԫ�� + ��ӡ�����е�Ԫ��
	LinkInsert(L, 1, 11);//L,i,e
	LinkPrint(L);
	LinkInsert(L, 2, 12);
	LinkPrint(L);
	LinkInsert(L, 3, 13);
	LinkPrint(L);
	LinkInsert(L, 4, 14);
	LinkPrint(L);
	LinkInsert(L, 3, 3);
	LinkPrint(L);
	LinkInsert(L, 6, 5);
	LinkPrint(L);
	LinkInsert(L, 9, 5);//Խ�����
	LinkPrint(L);
	printf("\n");

	//��������Ԫ�ظ���
	int len = LinkLenght(L);
	printf(">>>�����Ԫ�ظ���Ϊ: %d\n", len);
	printf("\n");


	//��������ɾ����i��Ԫ�� ����ӡ
	LinkDelect(L, 2);
	LinkPrint(L);
	LinkDelect(L, 5);
	LinkPrint(L);
	printf("\n");

	//���ٵ�����
	LinkDestroy(L);

	return 0;
}
