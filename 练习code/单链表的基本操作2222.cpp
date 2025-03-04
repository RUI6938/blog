/*ͷ�ļ�����*/
#include <stdio.h>
#include <stdlib.h>

/*��������*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

/*���Ͷ���*/
typedef int Status;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;// LNodeΪ�ṹ�壬
					// LinkListΪ�ṹ��ָ�롣


/*************
*  ��������  *
*************/

void InitList(LinkList *H); //��ʼ��������
void CreateList_L(LinkList H,int n);//����������
void printReverse(LinkList H);//��������������ֵ������
Status GetElem_L(LinkList H, int i, ElemType *e); //����
Status ListInsert_L(LinkList H, int i, ElemType e);//����
Status ListDelete_L(LinkList H, int i, ElemType *e);//ɾ��


/*************
*  �� �� ��  *
*************/
int main(){
    LinkList L;
    int n,i;
    ElemType e;

    //��ʼ��������
    InitList(&L);

    // ��ʾ��������
    printf(">>�����뵥����ĳ��ȣ�");
    scanf("%d",&n);
    CreateList_L(L,n);

    // �������������
    printReverse(L);

    // ��ʾ���������
    printf(">>������Ҫ���ҵĽ�� i��");
    scanf("%d",&i);
    if(GetElem_L(L,i,&e)==OK){
        printf("�������ҳɹ�\n�������Ԫ��ֵΪ %d\n",e);
    }else{
        printf("����ʧ��\n");
    }

    // ��ʾ�������������
    printf(">>������������㣬���������λ�� i��Ԫ��ֵ e��");
    scanf("%d%d",&i,&e);
    // ���������ԭʼ����
    int originalLength = 0;
    LinkList temp = L->next;
    while (temp!= NULL) {
        originalLength++;
        temp = temp->next;
    }
    // ���ݵ���λ�ü����µĲ���λ��
    int newPosition = originalLength - i + 1;
    if(ListInsert_L(L,newPosition,e)==OK){
        printf("...��������ɹ�\n");
    }else{
        printf("�������ʧ��\n");
    }

    // ��ʾ������ɾ������
    printf(">>������ɾ�����㣬������ɾ��λ�� i��");
    scanf("%d",&i);
    originalLength = 0;
    temp = L->next;
    while (temp!= NULL) {
        originalLength++;
        temp = temp->next;
    }
    newPosition = originalLength - i + 1;
    if(ListDelete_L(L,newPosition,&e)==OK){
        printf("����ɾ�������ɹ�\n����ɾ�����Ԫ��ֵΪ %d\n",e);
    }else{
        printf("ɾ������ʧ��\n");
    }

    // �������������
    printReverse(L);

    return 0;
}

/*************
*  ����ʵ��  *
*************/
void InitList(LinkList *H) {
    *H = (LinkList)malloc(sizeof(LNode));
    (*H)->next = NULL;
}

void CreateList_L(LinkList H, int n) {
    LinkList p, rear = H;
    for (int i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(LNode));
        printf(">������� %d ����㣺", n - i);
        scanf("%d", &p->data);
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
}

void printReverse(LinkList H) {
    LinkList p = H->next;
    if (p == NULL) {
        printf("����Ϊ�ա�\n");
        return;
    }
    // ʹ��ջ���洢����ڵ��ֵ
    int stack[100];
    int top = -1;
    while (p!= NULL) {
        stack[++top] = p->data;
        p = p->next;
    }
    printf("�����������");
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
    // �����������ָ�룬ʹ�ñ�ɾ����λ����ʧ
    LinkList temp = H;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
    return OK;
}
