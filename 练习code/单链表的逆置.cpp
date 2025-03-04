#include <stdio.h>
#include <stdlib.h>
 
typedef struct List{
	int data;
	struct List* next;
}LIST;
//表的初始化，不带头节点，
LIST* CreatSlist()
 {
 	LIST* head=NULL;
 	for(int i=5;i>=1;i--)
 	{
	LIST* newhead=(LIST *)malloc(sizeof(LIST));
	newhead->data=i;
 	newhead->next=head;
 	head=newhead;
	}
	return head;
}
//打印输出 
void print(LIST* P)
{
	while(P!=NULL)
	{
		printf("%d ",P->data);
		P=P->next;
	}
	printf("\n");
	return; 
}
//单链表反转（头插法） 
LIST* reverse(LIST* head)
{
	LIST *temp=NULL,*Phead=NULL; 
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		temp->next=Phead;
		Phead=temp;
	}
	return Phead; 
 } 
 
int main ()
{
	printf("原来的链表的数据:\n"); 
	LIST* P=CreatSlist();
	print(P);
	printf("反转后链表的数据:\n"); 
	LIST* head=reverse(P);
	print(head);		
	return 0;
 } 
