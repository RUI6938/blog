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

// 假设这里已经有创建二叉树的函数实现，暂不考虑其具体实现细节
BinTree CreatBinTree(); 

// 按照先序遍历顺序输出叶结点
void PreorderPrintLeaves( BinTree BT ) {
    if (BT!= NULL) {
        // 如果当前节点是叶结点（左右子树都为空），则输出该节点
        if (BT->Left == NULL && BT->Right == NULL) {
            printf(" %c", BT->Data);
        }
        // 先递归遍历左子树
        PreorderPrintLeaves(BT->Left);
        // 再递归遍历右子树
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
