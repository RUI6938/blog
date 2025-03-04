#include <stdio.h>

int main() {
    // 定义一个无符号 long long 类型的变量 sum，用于存储麦粒总数
    unsigned long long sum = 0;
    // 定义一个无符号 long long 类型的变量 current，用于存储当前格子中的麦粒数，初始值为 1
    unsigned long long current = 1;
    // 循环遍历棋盘的 64 个格子
    for (int i = 0; i < 64; i++) {
        // 将当前格子中的麦粒数加到总数 sum 上
        sum += current;
        // 更新当前格子中的麦粒数为上一个格子的两倍
        current *= 2;
    }
    // 输出麦粒总数
    printf("国王要给达依尔的小麦总数为：%llu 颗\n", sum);

    // 计算所需小麦的体积（1m?小麦有约 14*10^8 颗）
    double volume = (double)sum / (14 * 100000000);
    // 输出所需小麦的体积
printf("所需小麦的体积约为：%.2f m?\n", volume);
printf("姓名：张浩  学号：2309030239");


    return 0;
}

