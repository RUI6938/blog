#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

// ���������Ѿ��д����������ĺ���ʵ�֣��ݲ����������ʵ��ϸ��
BinTree CreatBinTree(); 

// �����������˳�����Ҷ���
void PreorderPrintLeaves( BinTree BT ) {
    if (BT!= NULL) {
        // �����ǰ�ڵ���Ҷ��㣨����������Ϊ�գ���������ýڵ�
        if (BT->Left == NULL && BT->Right == NULL) {
            printf(" %c", BT->Data);
        }
        // �ȵݹ����������
        PreorderPrintLeaves(BT->Left);
        // �ٵݹ����������
        PreorderPrintLeaves(BT->Right);
    }
}

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}
