/*
 程序名称：SixNumberSelectionSort —— 六数选择排序练习
 功能：输入6个整数，使用选择排序按从小到大排序
*/

#include <stdio.h>

#define N 6

void selectionSort(int a[])
{
    int i, j, min, temp;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
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

    selectionSort(a);

    printf("排序结果（从小到大）：\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}

