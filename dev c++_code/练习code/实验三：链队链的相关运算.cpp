#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int QueueElementType;
typedef struct Node {
    QueueElementType data; /* ������ */
    struct Node *next; /* ָ���� */
    // Ϊ�˷�����ԣ�������ӽڵ���ţ���ѡ��
    // int nodeNumber; 
} LinkQueueNode;
typedef struct {
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

/************************
*     ����������ʵ��
************************/

// ��Q��ʼ��Ϊһ���յ�������
int InitQueue(LinkQueue *Q) {
    // Ϊͷ�ڵ�����ڴ�ռ�
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Q->front == NULL) {
        // �ڴ����ʧ�ܣ�����FALSE��ʾ��ʼ��ʧ��
        return FALSE;
    }

    // ��ʼ��ʱ����βָ��Ҳָ��ͷ�ڵ�
    Q->rear = Q->front;
    Q->front->next = NULL;

    // ��ʼ���ɹ�������TRUE
    return TRUE;
}

// ������Ԫ��x���뵽����Q��
int EnterQueue(LinkQueue *Q, QueueElementType x) {
    // �����½ڵ�
    LinkQueueNode *newNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (newNode == NULL) {
        // �ڴ����ʧ�ܣ�����FALSE��ʾ���ʧ��
        return FALSE;
    }

    // ����½ڵ�����
    newNode->data = x;
    newNode->next = NULL;

    // ���½ڵ���뵽����β��
    Q->rear->next = newNode;
    Q->rear = newNode;

    // ��ӳɹ�������TRUE
    return TRUE;
}

// ������Q�Ķ�ͷԪ�س��ӣ�����ŵ�x��ָ�Ĵ洢�ռ���
int DeleteQueue(LinkQueue *Q, QueueElementType *x) {
    if (Q->front == Q->rear) {
        // ����Ϊ�գ��޷����ӣ�����FALSE
        return FALSE;
    }

    // �����ͷ�ڵ�
    LinkQueueNode *temp = Q->front->next;
    *x = temp->data;

    // ������ͷָ��
    Q->front->next = temp->next;

    // ������Ӻ����Ϊ�գ����¶�βָ��ָ��ͷ�ڵ�
    if (Q->rear == temp) {
        Q->rear = Q->front;
    }

    // �ͷų��ӽڵ��ڴ�
    free(temp);

    // ���ӳɹ�������TRUE
    return TRUE;
}

// �������
void printQueue(LinkQueue Q) {
    LinkQueueNode *p = Q.front->next;
    printf("�����������");
    while (p!= NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/************************
*     ������
************************/
int main() {
    LinkQueue LQ;
    QueueElementType x;

    // 1 ���ö��г�ʼ�����㷨����һ���ն���
    if (InitQueue(&LQ) == TRUE) {
        printf("���г�ʼ���ɹ���\n");
    } else {
        printf("���г�ʼ��ʧ�ܣ�\n");
        return -1;
    }

    // 2 ������ӡ����ӡ�������е��㷨
    int num;
    printf("���������Ԫ�ظ�����");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("�������%d��Ԫ�أ�", i + 1);
        scanf("%d", &x);
        if (EnterQueue(&LQ, x) == FALSE) {
            printf("���ʧ�ܣ�\n");
            return -1;
        }
    }

    printQueue(LQ);

    for (int i = 0; i < num - 2; i++) {
        if (DeleteQueue(&LQ, &x) == TRUE) {
            printf("ִ�г��Ӳ���������Ԫ��Ϊ��%d\n", x);
        } else {
            printf("����ʧ�ܣ�\n");
            return -1;
        }
    }

    printQueue(LQ);

    // ���Ը�����Ҫ��Ӹ�������򱣳ֳ���ȴ��û���������
    printf("Press any key to continue\n");
    getchar(); // ������뻺�����Ļ��з�
    getchar();

    return 0;
}
