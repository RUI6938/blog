#include<stdio.h>
typedef int KeyType; 
typedef int OtherType; 
#define LIST_SIZE 20
typedef struct{
    KeyType key;
    OtherType other_data;
}RecordType;
typedef struct{
    RecordType r[LIST_SIZE + 1];  /* r[0]为工作单元 */
    int length;
}RecordList;

int SeqSearch(RecordList l, KeyType k) 
{
    // 此处是顺序查找函数的已有代码
} 

int BinSrch(RecordList l, KeyType k)
{
    // 此处是二分查找函数的已有代码
}

int main()  // 将返回类型修改为int
{
    RecordList L = { { {0, 0}, {21, 0}, {37, 0}, {88, 0}, {19, 0},
                       {92, 0}, {5, 0}, {64, 0}, {56, 0}, {80, 0}, {72, 0}, {13, 0} }, 11 };
    KeyType target = 37;
    int seq_result, bin_result;
    seq_result = SeqSearch(L, target);
    bin_result = BinSrch(L, target);
    if (seq_result) {
        printf("顺序查找：位置为：%d\n", seq_result);
    }
    else {
        printf("顺序查找：未找到目标元素\n");
    }
    if (bin_result) {
        printf("二分查找：位置为：%d\n", bin_result);
    }
    else {
        printf("二分查找：未找到目标元素\n");
    }
    return 0;  // 添加返回语句，返回0表示程序正常结束
}
