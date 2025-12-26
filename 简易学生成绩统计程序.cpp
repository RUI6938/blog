/*
 * 程序名称：简易学生成绩统计程序
 * 功    能：输入学生成绩，计算平均分、最高分和最低分
 * 作    者：XXX
 * 日    期：2025-12-26
 */
#include <stdio.h>

int main() {
    int n;
    float score, sum = 0;
    float max, min;

    printf("请输入学生人数：");
    scanf("%d", &n);

    if (n <= 0) {
        printf("人数输入不合法！\n");
        return 0;
    }

    printf("请输入第1个学生的成绩：");
    scanf("%f", &score);

    sum = score;
    max = score;
    min = score;

    for (int i = 2; i <= n; i++) {
        printf("请输入第%d个学生的成绩：", i);
        scanf("%f", &score);

        sum += score;

        if (score > max)
            max = score;
        if (score < min)
            min = score;
    }

    printf("\n平均分：%.2f\n", sum / n);
    printf("最高分：%.2f\n", max);
    printf("最低分：%.2f\n", min);

    return 0;
}
