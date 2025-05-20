#include<stdio.h>

int main() {
    int a, b, c; // 声明变量
    printf("请输入三个整数：a,b,c:");
    scanf("%d %d %d", &a, &b, &c);
    if (((b + c) > a) && ((c + a) > b) && ((a + b) > c)) {
        if (a == b && b == c) {
            printf("该三角形为等边三角形\n");
        } else if (a == b || b == c || c == a) {
            printf("该三角形为等腰三角形\n");
        } else {
            printf("该三角形为普通三角形\n");
        }
    } else {
        printf("该组值不能组成三角形!\n");
    }
    printf("计算机39 张浩");
    return 0;
}

