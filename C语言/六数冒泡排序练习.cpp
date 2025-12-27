/*
 程序名称：SixNumberBubbleSort —— 六数冒泡排序练习
 功能：输入6个整数，使用冒泡排序按从小到大排序
*/

#include <stdio.h>

#define N 6

void bubbleSort(int a[])
{
    int i, j, temp;
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int a[N];
    int i;

    printf("请输入6个整数：\n");
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    bubbleSort(a);

    printf("排序结果（从小到大）：\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}

