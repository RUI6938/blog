#include<stdio.h>

int main() {
    int a, b, c; // ��������
    printf("����������������a,b,c:");
    scanf("%d %d %d", &a, &b, &c);
    if (((b + c) > a) && ((c + a) > b) && ((a + b) > c)) {
        if (a == b && b == c) {
            printf("��������Ϊ�ȱ�������\n");
        } else if (a == b || b == c || c == a) {
            printf("��������Ϊ����������\n");
        } else {
            printf("��������Ϊ��ͨ������\n");
        }
    } else {
        printf("����ֵ�������������!\n");
    }
    printf("�����39 �ź�");
    return 0;
}

