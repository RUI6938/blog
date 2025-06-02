#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;
typedef struct StackNode {
    SElemType data;
    struct StackNode* next;
} LStackNode, *LStack;

Status InitStack(LStack* S);
Status Push(LStack* top, SElemType e);
Status Pop(LStack* top, SElemType* e);
Status GetTop(LStack top, SElemType* e);
Status StackEmpty(LStack S);

// ��ʼ��ջ
Status InitStack(LStack* S) {
    *S = NULL;
    return OK;
}

// ѹջ
Status Push(LStack* top, SElemType e) {
    LStackNode* newNode = (LStackNode*)malloc(sizeof(LStackNode));
    if (!newNode) return ERROR;
    newNode->data = e;
    newNode->next = *top;
    *top = newNode;
    return OK;
}

// ��ջ
Status Pop(LStack* top, SElemType* e) {
    if (!*top) return ERROR;
    LStackNode* temp = *top;
    *e = temp->data;
    *top = (*top)->next;
    free(temp);
    return OK;
}

// ȡջ��Ԫ��
Status GetTop(LStack top, SElemType* e) {
    if (!top) return ERROR;
    *e = top->data;
    return OK;
}

// �ж��Ƿ��ǿ�ջ
Status StackEmpty(LStack S) {
    return S == NULL? TRUE : FALSE;
}

int main() {
    LStack LS;
    SElemType e;
    // ��ʼ��ջ
    if (InitStack(&LS)) {
        printf("ջ��ʼ���ɹ�\n");
    }

    // ��ջ����
    printf("�������ջԪ�ص�ֵ��");
    scanf("%d", &e);
    Push(&LS, e);
    printf("�������ջԪ�ص�ֵ��");
    scanf("%d", &e);
    Push(&LS, e);

    // ��ջ��������ʾ��ջԪ��
    if (Pop(&LS, &e) == OK) {
        printf("��ջԪ��Ϊ��%d\n", e);
    }
    else {
        printf("��ջʧ�ܣ�ջ����Ϊ�ա�\n");
    }

    // �ٴν�ջ����
    printf("�������ջԪ�ص�ֵ��");
    scanf("%d", &e);
    Push(&LS, e);
    printf("�������ջԪ�ص�ֵ��");
    scanf("%d", &e);
    Push(&LS, e);
    printf("�������ջԪ�ص�ֵ��");
    scanf("%d", &e);
    Push(&LS, e);

    // ȡջ��Ԫ�ز���ʾ
    if (GetTop(LS, &e) == OK) {
        printf("ջ��Ԫ��Ϊ��%d\n", e);
    }
    else {
        printf("��ȡջ��Ԫ��ʧ�ܣ�ջ����Ϊ�ա�\n");
    }

    // ѭ����ջֱ��ջΪ�գ�����ʾ��ջԪ��
    printf("�����ջֱ��ջΪ�գ����γ�ջ��Ԫ��Ϊ��\n");
    while (!StackEmpty(LS)) {
        if (Pop(&LS, &e) == OK) {
            printf("%d ", e);
        }
        else {
            printf("��ջʧ�ܣ�ջ����Ϊ�ա�\n");
            break;
        }
    }
    printf("\n");

    // ��������ȥ����
    printf("�����ȥ��������Ϊ��");
    LStack tempStack;
    InitStack(&tempStack);
    LStackNode* node = LS;
    while (node!= NULL) {
        Push(&tempStack, node->data);
        node = node->next;
    }
    while (!StackEmpty(tempStack)) {
        Pop(&tempStack, &e);
        printf("%d ", e);
    }
    printf("\n");

    return 0;
}
