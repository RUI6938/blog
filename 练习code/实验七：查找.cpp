#include<stdio.h>
typedef int KeyType; 
typedef int OtherType; 
#define LIST_SIZE 20
typedef struct{
    KeyType key;
    OtherType other_data;
}RecordType;
typedef struct{
    RecordType r[LIST_SIZE + 1];  /* r[0]Ϊ������Ԫ */
    int length;
}RecordList;

int SeqSearch(RecordList l, KeyType k) 
{
    // �˴���˳����Һ��������д���
} 

int BinSrch(RecordList l, KeyType k)
{
    // �˴��Ƕ��ֲ��Һ��������д���
}

int main()  // �����������޸�Ϊint
{
    RecordList L = { { {0, 0}, {21, 0}, {37, 0}, {88, 0}, {19, 0},
                       {92, 0}, {5, 0}, {64, 0}, {56, 0}, {80, 0}, {72, 0}, {13, 0} }, 11 };
    KeyType target = 37;
    int seq_result, bin_result;
    seq_result = SeqSearch(L, target);
    bin_result = BinSrch(L, target);
    if (seq_result) {
        printf("˳����ң�λ��Ϊ��%d\n", seq_result);
    }
    else {
        printf("˳����ң�δ�ҵ�Ŀ��Ԫ��\n");
    }
    if (bin_result) {
        printf("���ֲ��ң�λ��Ϊ��%d\n", bin_result);
    }
    else {
        printf("���ֲ��ң�δ�ҵ�Ŀ��Ԫ��\n");
    }
    return 0;  // ��ӷ�����䣬����0��ʾ������������
}
