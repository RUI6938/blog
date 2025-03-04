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

// 初始化栈
Status InitStack(LStack* S) {
    *S = NULL;
    return OK;
}

// 压栈
Status Push(LStack* top, SElemType e) {
    LStackNode* newNode = (LStackNode*)malloc(sizeof(LStackNode));
    if (!newNode) return ERROR;
    newNode->data = e;
    newNode->next = *top;
    *top = newNode;
    return OK;
}

// 出栈
Status Pop(LStack* top, SElemType* e) {
    if (!*top) return ERROR;
    LStackNode* temp = *top;
    *e = temp->data;
    *top = (*top)->next;
    free(temp);
    return OK;
}

// 取栈顶元素
Status GetTop(LStack top, SElemType* e) {
    if (!top) return ERROR;
    *e = top->data;
    return OK;
}

// 判断是否是空栈
Status StackEmpty(LStack S) {
    return S == NULL? TRUE : FALSE;
}

int main() {
    LStack LS;
    SElemType e;
    // 初始化栈
    if (InitStack(&LS)) {
        printf("栈初始化成功\n");
    }

    // 进栈操作
    printf("请输入进栈元素的值：");
    scanf("%d", &e);
    Push(&LS, e);
    printf("请输入进栈元素的值：");
    scanf("%d", &e);
    Push(&LS, e);

    // 出栈操作并显示出栈元素
    if (Pop(&LS, &e) == OK) {
        printf("出栈元素为：%d\n", e);
    }
    else {
        printf("出栈失败，栈可能为空。\n");
    }

    // 再次进栈操作
    printf("请输入进栈元素的值：");
    scanf("%d", &e);
    Push(&LS, e);
    printf("请输入进栈元素的值：");
    scanf("%d", &e);
    Push(&LS, e);
    printf("请输入进栈元素的值：");
    scanf("%d", &e);
    Push(&LS, e);

    // 取栈顶元素并显示
    if (GetTop(LS, &e) == OK) {
        printf("栈顶元素为：%d\n", e);
    }
    else {
        printf("获取栈顶元素失败，栈可能为空。\n");
    }

    // 循环出栈直到栈为空，并显示出栈元素
    printf("下面出栈直到栈为空，依次出栈的元素为：\n");
    while (!StackEmpty(LS)) {
        if (Pop(&LS, &e) == OK) {
            printf("%d ", e);
        }
        else {
            printf("出栈失败，栈可能为空。\n");
            break;
        }
    }
    printf("\n");

    // 输出输入进去的数
    printf("输入进去的数依次为：");
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
