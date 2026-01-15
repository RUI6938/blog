#include <stdio.h>
#include <stdlib.h>

// 定义结点
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 创建链表（尾插法）
Node* createList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    Node *tail = head;
    int x;

    printf("请输入整数（-1结束）：");
    while (1)
    {
        scanf("%d", &x);
        if (x == -1)
            break;

        Node *p = (Node *)malloc(sizeof(Node));
        p->data = x;
        p->next = NULL;

        tail->next = p;
        tail = p;
    }
    return head;
}

// 输出链表
void printList(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *head = createList();

    printf("链表内容：");
    printList(head);

    return 0;
}

