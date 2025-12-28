/*
 程序名称：SixNumberInsertionSort —— 六数插入排序练习
 功能：输入6个整数，使用插入排序按从小到大排序
*/

#include <stdio.h>

#define N 6   // 定义数组长度为6

// 插入排序函数：将数组按从小到大排序
void insertionSort(int a[])
{
    int i, j, key;
    
    // 从第二个元素开始插入
    for (i = 1; i < N; i++)
    {
        key = a[i];   // 当前要插入的元素
        j = i - 1;    // 已排序部分的最后一个下标
        
        // 将比 key 大的元素整体向后移动
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        
        // 将 key 插入到正确位置
        a[j + 1] = key;
    }
}

int main()
{
    int a[N];
    int i;

    printf("请输入6个整数：\n");
    
    // 输入数组
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    insertionSort(a);

    printf("排序结果（从小到大）：\n");
    
    // 输出排序后的数组
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);

    return 0;
}

