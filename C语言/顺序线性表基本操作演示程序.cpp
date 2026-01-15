#include <stdio.h>

#define MAXSIZE 10   // 顺序表最大容量

typedef struct
{
    int data[MAXSIZE]; // 存放元素
    int length;        // 当前长度
} SeqList;

// 初始化顺序表
void initList(SeqList *L)
{
    L->length = 0;
}

// 在指定位置插入元素
int insertList(SeqList *L, int pos, int value)
{
    if (pos < 1 || pos > L->length + 1 || L->length >= MAXSIZE)
        return 0;

    for (int i = L->length; i >= pos; i--)
        L->data[i] = L->data[i - 1];

    L->data[pos - 1] = value;
    L->length++;
    return 1;
}

// 输出顺序表
void printList(SeqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%d ", L.data[i]);
    printf("\n");
}

int main()
{
    SeqList L;
    initList(&L);

    insertList(&L, 1, 10);
    insertList(&L, 2, 20);
    insertList(&L, 3, 30);

    printf("顺序表内容：");
    printList(L);

    return 0;
}

