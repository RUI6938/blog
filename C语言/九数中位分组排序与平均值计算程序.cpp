/*
程序名称：NineNumberCenterSort
功能：
1. 输入9个互不相同的整数
2. 找出一个“比4个大、比4个小”的中间数
3. 小于中间数的4个数：从大到小排序
4. 大于中间数的4个数：从小到大排序
5. 计算并输出9个数的平均值
*/

#include <stdio.h>

#define N 9

int main()
{
    int a[N];
    int i, j;

    printf("请输入9个不相同的整数：\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    // 判断是否有重复
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (a[i] == a[j])
            {
                printf("存在重复数字，程序退出。\n");
                return 0;
            }
        }
    }

    // 找中间数
    int centerIndex = -1;

    for (i = 0; i < N; i++)
    {
        int less = 0, greater = 0;

        for (j = 0; j < N; j++)
        {
            if (a[j] < a[i]) less++;
            if (a[j] > a[i]) greater++;
        }

        if (less == 4 && greater == 4)
        {
            centerIndex = i;
            break;
        }
    }

    if (centerIndex == -1)
    {
        printf("不存在符合条件的数，程序退出。\n");
        return 0;
    }

    int center = a[centerIndex];
    int low[4], high[4];
    int li = 0, hi = 0;

    // 分组
    for (i = 0; i < N; i++)
    {
        if (a[i] < center)
            low[li++] = a[i];
        else if (a[i] > center)
            high[hi++] = a[i];
    }

    // 小于部分：从大到小排序
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (low[i] < low[j])
            {
                int temp = low[i];
                low[i] = low[j];
                low[j] = temp;
            }
        }
    }

    // 大于部分：从小到大排序
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (high[i] > high[j])
            {
                int temp = high[i];
                high[i] = high[j];
                high[j] = temp;
            }
        }
    }

    // 计算平均值
    int sum = 0;
    for (i = 0; i < N; i++)
    {
        sum += a[i];
    }
    double avg = sum / 9.0;

    // 输出结果
    printf("\n小于中间数的4个数（从大到小）：\n");
    for (i = 0; i < 4; i++)
        printf("%d ", low[i]);

    printf("\n\n中间数：%d\n", center);

    printf("\n大于中间数的4个数（从小到大）：\n");
    for (i = 0; i < 4; i++)
        printf("%d ", high[i]);

    printf("\n\n9个数的平均值：%.2f\n", avg);

    return 0;
}

