#include <stdio.h>

int main() {
    // ����һ���޷��� long long ���͵ı��� sum�����ڴ洢��������
    unsigned long long sum = 0;
    // ����һ���޷��� long long ���͵ı��� current�����ڴ洢��ǰ�����е�����������ʼֵΪ 1
    unsigned long long current = 1;
    // ѭ���������̵� 64 ������
    for (int i = 0; i < 64; i++) {
        // ����ǰ�����е��������ӵ����� sum ��
        sum += current;
        // ���µ�ǰ�����е�������Ϊ��һ�����ӵ�����
        current *= 2;
    }
    // �����������
    printf("����Ҫ����������С������Ϊ��%llu ��\n", sum);

    // ��������С��������1m?С����Լ 14*10^8 �ţ�
    double volume = (double)sum / (14 * 100000000);
    // �������С������
printf("����С������ԼΪ��%.2f m?\n", volume);
printf("�������ź�  ѧ�ţ�2309030239");


    return 0;
}

