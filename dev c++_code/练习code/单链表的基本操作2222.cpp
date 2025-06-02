/*头文件包含*/
#include <stdio.h>
#include <stdlib.h>

/*常量定义*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

/*类型定义*/
typedef int Status;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;// LNode为结构体，
					// LinkList为结构体指针。


/*************
*  函数声明  *
*************/

void InitList(LinkList *H); //初始化单链表
void CreateList_L(LinkList H,int n);//创建单链表
void printReverse(LinkList H);//输出单链表各结点的值（倒序）
Status GetElem_L(LinkList H, int i, ElemType *e); //查找
Status ListInsert_L(LinkList H, int i, ElemType e);//插入
Status ListDelete_L(LinkList H, int i, ElemType *e);//删除


/*************
*  主 函 数  *
*************/
int main(){
    LinkList L;
    int n,i;
    ElemType e;

    //初始化单链表
    InitList(&L);

    // 演示单链表创建
    printf(">>请输入单链表的长度：");
    scanf("%d",&n);
    CreateList_L(L,n);

    // 链表输出（倒序）
    printReverse(L);

    // 演示单链表查找
    printf(">>请输入要查找的结点 i：");
    scanf("%d",&i);
    if(GetElem_L(L,i,&e)==OK){
        printf("……查找成功\n……结点元素值为 %d\n",e);
    }else{
        printf("查找失败\n");
    }

    // 演示单链表插入运算
    printf(">>单链表插入运算，请输入插入位置 i及元素值 e：");
    scanf("%d%d",&i,&e);
    // 计算链表的原始长度
    int originalLength = 0;
    LinkList temp = L->next;
    while (temp!= NULL) {
        originalLength++;
        temp = temp->next;
    }
    // 根据倒序位置计算新的插入位置
    int newPosition = originalLength - i + 1;
    if(ListInsert_L(L,newPosition,e)==OK){
        printf("...插入操作成功\n");
    }else{
        printf("插入操作失败\n");
    }

    // 演示单链表删除运算
    printf(">>单链表删除运算，请输入删除位置 i：");
    scanf("%d",&i);
    originalLength = 0;
    temp = L->next;
    while (temp!= NULL) {
        originalLength++;
        temp = temp->next;
    }
    newPosition = originalLength - i + 1;
    if(ListDelete_L(L,newPosition,&e)==OK){
        printf("……删除操作成功\n……删除结点元素值为 %d\n",e);
    }else{
        printf("删除操作失败\n");
    }

    // 链表输出（倒序）
    printReverse(L);

    return 0;
}

/*************
*  函数实现  *
*************/
void InitList(LinkList *H) {
    *H = (LinkList)malloc(sizeof(LNode));
    (*H)->next = NULL;
}

void CreateList_L(LinkList H, int n) {
    LinkList p, rear = H;
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(LNode));
        printf(">请输入第 %d 个结点：", n - i);
        scanf("%d", &p->data);
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
}

void printReverse(LinkList H) {
    LinkList p = H->next;
    if (p == NULL) {
        printf("链表为空。\n");
        return;
    }
    // 使用栈来存储链表节点的值
    int stack[100];
    int top = -1;
    while (p!= NULL) {
        stack[++top] = p->data;
        p = p->next;
    }
    printf("【链表输出】");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

Status GetElem_L(LinkList H, int i, ElemType *e) {
    int j = 1;
    LinkList p = H->next;
    while (p!= NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

Status ListInsert_L(LinkList H, int i, ElemType e) {
    int j = 0;
    LinkList p = H, s;
    while (p!= NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i - 1) {
        return ERROR;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete_L(LinkList H, int i, ElemType *e) {
    int j = 0;
    LinkList p = H, q;
    while (p->next!= NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i - 1) {
        return ERROR;
    }
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    // 更新链表遍历指针，使得被删除的位置消失
    LinkList temp = H;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
    return OK;
}
