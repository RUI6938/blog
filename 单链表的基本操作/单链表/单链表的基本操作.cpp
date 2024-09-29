#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;			//数据域
	struct node* next;	//指针域
}LinkNode;

LinkNode* InitList()
{
	//初始化一个带头结点的链表
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
	//L为记录头结点的指针, i为插入位置, e为插入元素
	LinkNode* temp = L;
	int count = 0;		//默认长度为0
	while (temp->next && count < i - 1)
		//确保 temp 指针移动到第 i-1 个结点的位置，并避免访问空指针导致的错误。
	{
		//寻找第i个结点,并使temp指向第i-1个结点
		temp = temp->next;
		count++;
	}
	//上面循环中已经根据i对count的值进行计数,count最大时等于链表长度,
	//当i-1大于链表长度时,则无法访问i结点(没有i这个结点)
	if (!(temp) || count < i - 1)
	{
		///第i个位置不存在,则进行提示并返回0
		printf(">>>访问越界,请重试!\n");
		return 0;
	}
	//在链表的第i个位置插入新结点P
	LinkNode* P = (LinkNode*)malloc(sizeof(LinkNode));
	P->data = e;
	P->next = temp->next;		//将temp下一个结点给P的地址域
	temp->next = P;				//将P的地址赋值给temp的地址域
	return 1;					//成功插入则返回1
}

void LinkPrint(LinkNode* L)
{

	LinkNode* P = L->next;
	printf(">链表中的元素为:");
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
	int len = 0;		//默认长度为0
	while (temp->next)
	{
		temp = temp->next;
		len++;	//遍历得到链表长度
	}
	return len;
}
int LinkDelect(LinkNode* L, int i) {
	LinkNode* temp = L;
	int count = 0;
	while (temp->next && count < i - 1)
	{
		//寻找第i个结点,并使temp指向第i-1个结点
		temp = temp->next;
		count++;
	}
	if (!(temp->next) || count < i - 1)
	{
		///第i个位置不存在,则进行提示并返回0
		printf(">删除位置不合理,请重试!\n");
		return 0;
	}
	LinkNode* P = temp->next;//临时存储要删除结点的地址,用于后续释放
	temp->next = P->next;
	free(P);	//释放被删除的地址
}
void LinkDestroy(LinkNode* L)
{
	LinkNode* P;
	while (L)//当L为NULL时停止
	{
		P = L;
		L = L->next;
		free(P);
	}
}

int main()
{
	//创建一个结构体变量指针
	LinkNode* L = InitList();
	printf("^链表初始化成功.\n");
	printf("\n");

	//判断链表是否为空
	int flag = LinkEmpty(L);
	flag ? printf(">>>链表不为空\n") : printf(">>>链表为空\n");
	printf("\n");

	//插入新元素 + 打印链表中的元素
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
	LinkInsert(L, 9, 5);//越界访问
	LinkPrint(L);
	printf("\n");

	//求链表中元素个数
	int len = LinkLenght(L);
	printf(">>>链表的元素个数为: %d\n", len);
	printf("\n");


	//从链表中删除第i个元素 并打印
	LinkDelect(L, 2);
	LinkPrint(L);
	LinkDelect(L, 5);
	LinkPrint(L);
	printf("\n");

	//销毁单链表
	LinkDestroy(L);

	return 0;
}
