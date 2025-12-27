/*
 程序名称：SixNumberInsertionSort —— 六数插入排序练习
 功能：输入6个整数，使用插入排序按从小到大排序
*/

#include <stdio.h>

#define N 6

void insertionSort(int a[])
{
    int i, j, key;
    for (i = 1; i < N; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[N];
    int i;

    printf("请输入6个整数：\n");
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    insertionSort(a);

    printf("排序结果（从小到大）：\n");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}

