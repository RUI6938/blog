#include <stdio.h>

int main()
{
    int a[5] = {5, 3, 4, 1, 2};
    int i, j, temp;

    // 冒泡排序
    for (i = 0; i < 4; i++)          // 控制比较的轮数
    {
        for (j = 0; j < 4 - i; j++)  // 相邻元素比较
        {
            if (a[j] > a[j + 1])     // 如果前一个大
            {
                temp = a[j];         // 交换
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // 输出结果
    printf("排序结果：");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return 0;
}

