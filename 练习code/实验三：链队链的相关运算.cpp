#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int QueueElementType;
typedef struct Node {
    QueueElementType data; /* 数据域 */
    struct Node *next; /* 指针域 */
    // 为了方便调试，可以添加节点序号（可选）
    // int nodeNumber; 
} LinkQueueNode;
typedef struct {
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

/************************
*     函数声明及实现
************************/

// 将Q初始化为一个空的链队列
int InitQueue(LinkQueue *Q) {
    // 为头节点分配内存空间
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (Q->front == NULL) {
        // 内存分配失败，返回FALSE表示初始化失败
        return FALSE;
    }

    // 初始化时，队尾指针也指向头节点
    Q->rear = Q->front;
    Q->front->next = NULL;

    // 初始化成功，返回TRUE
    return TRUE;
}

// 将数据元素x插入到队列Q中
int EnterQueue(LinkQueue *Q, QueueElementType x) {
    // 创建新节点
    LinkQueueNode *newNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (newNode == NULL) {
        // 内存分配失败，返回FALSE表示入队失败
        return FALSE;
    }

    // 填充新节点数据
    newNode->data = x;
    newNode->next = NULL;

    // 将新节点插入到队列尾部
    Q->rear->next = newNode;
    Q->rear = newNode;

    // 入队成功，返回TRUE
    return TRUE;
}

// 将队列Q的队头元素出队，并存放到x所指的存储空间中
int DeleteQueue(LinkQueue *Q, QueueElementType *x) {
    if (Q->front == Q->rear) {
        // 队列为空，无法出队，返回FALSE
        return FALSE;
    }

    // 保存队头节点
    LinkQueueNode *temp = Q->front->next;
    *x = temp->data;

    // 调整队头指针
    Q->front->next = temp->next;

    // 如果出队后队列为空，更新队尾指针指向头节点
    if (Q->rear == temp) {
        Q->rear = Q->front;
    }

    // 释放出队节点内存
    free(temp);

    // 出队成功，返回TRUE
    return TRUE;
}

// 输出队列
void printQueue(LinkQueue Q) {
    LinkQueueNode *p = Q.front->next;
    printf("【队列输出】");
    while (p!= NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/************************
*     主函数
************************/
int main() {
    LinkQueue LQ;
    QueueElementType x;

    // 1 调用队列初始化的算法创建一个空队列
    if (InitQueue(&LQ) == TRUE) {
        printf("队列初始化成功！\n");
    } else {
        printf("队列初始化失败！\n");
        return -1;
    }

    // 2 调用入队、出队、输出队列等算法
    int num;
    printf("请输入入队元素个数：");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("请输入第%d个元素：", i + 1);
        scanf("%d", &x);
        if (EnterQueue(&LQ, x) == FALSE) {
            printf("入队失败！\n");
            return -1;
        }
    }

    printQueue(LQ);

    for (int i = 0; i < num - 2; i++) {
        if (DeleteQueue(&LQ, &x) == TRUE) {
            printf("执行出队操作，出队元素为：%d\n", x);
        } else {
            printf("出队失败！\n");
            return -1;
        }
    }

    printQueue(LQ);

    // 可以根据需要添加更多操作或保持程序等待用户输入后结束
    printf("Press any key to continue\n");
    getchar(); // 清除输入缓冲区的换行符
    getchar();

    return 0;
}
