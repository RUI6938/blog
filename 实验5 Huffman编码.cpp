#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义哈夫曼树节点结构体
typedef struct
{
    int weight;
    int parent;
    int LChild;
    int RChild;
} HTNode, *HuffmanTree;/* 动态分配数组存储哈夫曼树 */

typedef char **HuffmanCode; /* 动态分配数组存储哈夫曼编码表 */


void select(HuffmanTree *ht, int n, int *s1, int *s2)// 在(*ht)[1]~ (*ht)[i-1]的范围内选择weight最小(且parent为0)的两个结点，其序号分别赋值给s1和s2返回，设*s1<*s2
{
    int i;
    // 初始化两个较大的值，用于比较找到最小的权值
    int min1 = 32767, min2 = 32767;  
    *s1 = *s2 = 0;

    for (i = 1; i <= n; i++)
    {
        // 只考虑parent为0的节点，即未参与过合并构建哈夫曼树的节点
        if ((*ht)[i].parent == 0 && (*ht)[i].weight < min1)
        {
            // 更新min2和*s2，因为找到了更小的min1，原来的min1变为次小值min2
            min2 = min1;  
            *s2 = *s1;  
            // 更新min1和*s1，记录当前找到的最小权值节点序号
            min1 = (*ht)[i].weight;  
            *s1 = i;  
        }
        else if ((*ht)[i].parent == 0 && (*ht)[i].weight < min2)
        {
            // 找到比min2更小但不是最小的权值节点，更新min2和*s2
            min2 = (*ht)[i].weight;
            *s2 = i;
        }
    }
}

// w存放n个字符的权值(均>0)，构造哈夫曼树ht，并求出n个字符的哈夫曼编码hc
void CrtHuffmanTree(HuffmanTree *ht, HuffmanCode *hc, int *w, int n)
{
    // 1. 初始化
    int m = 2 * n - 1;  
    // 动态分配数组来存储哈夫曼树节点，大小为m + 1个HTNode结构体
    *ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    if (!(*ht))
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    int i;
    // 初始化前n个节点，根据输入的权值数组w设置weight，其他属性初始化为0
    for (i = 1; i <= n; i++)
    {
        (*ht)[i].weight = w[i - 1];
        (*ht)[i].parent = 0;
        (*ht)[i].LChild = 0;
        (*ht)[i].RChild = 0;
    }
    // 初始化后m - n个节点，weight、parent、LChild、RChild都初始化为0
    for (i = n + 1; i <= m; i++)
    {
        (*ht)[i].weight = 0;
        (*ht)[i].parent = 0;
        (*ht)[i].LChild = 0;
        (*ht)[i].RChild = 0;
    }

    // 2. 建哈夫曼树
    int s1, s2;
    for (i = n + 1; i <= m; i++)
    {
        select(ht, i - 1, &s1, &s2);
        // 设置找到的两个最小权值节点s1和s2的父节点为当前正在构建的新节点i
        (*ht)[s1].parent = i;
        (*ht)[s2].parent = i;
        // 设置新节点i的左孩子为s1，右孩子为s2
        (*ht)[i].LChild = s1;
        (*ht)[i].RChild = s2;
        // 新节点i的权值为其左、右子节点权值之和
        (*ht)[i].weight = (*ht)[s1].weight + (*ht)[s2].weight;
    }

    // 3. 从叶子到根，逆向求每个字符的哈夫曼编码
    *hc = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    if (!(*hc))
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    char *cd;
    cd = (char *)malloc(n * sizeof(char));
    if (!cd)
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    cd[n - 1] = '\0';
    for (i = 1; i <= n; i++)
    {
        int start = n - 1;
        int c = i;
        int f = (*ht)[c].parent;
        while (f!= 0)
        {
            // 如果当前节点c是其父节点f的左孩子，编码为0
            if ((*ht)[f].LChild == c)
                cd[--start] = '0';
            // 如果当前节点c是其父节点f的右孩子，编码为1
            else
                cd[--start] = '1';
            c = f;
            f = (*ht)[c].parent;
        }
        // 为当前字符的哈夫曼编码分配足够的内存空间
        (*hc)[i] = (char *)malloc((n - start) * sizeof(char));
        // 将生成的编码字符串复制到编码表相应位置
        strcpy((*hc)[i], &cd[start]);
    }
    free(cd);
}

// 输出结点及其编码
void printCode(int *w, HuffmanCode *hc, int n)
{
    int i;
    for (i = 1; i <= n; ++i)
    {
        printf("%2d| %3d --> %s\n", i, w[i - 1], (*hc)[i]);
    }
}

// 输出赫夫曼树，m即2n - 1
void printHT(HuffmanTree *ht, int m)
{
    int i;
    printf("   weight parent lchild rchild\n");
    for (i = 1; i <= m; i++)
    {
        printf("%2d|%4d   %4d   %4d   %2d \n", i, (*ht)[i].weight, (*ht)[i].parent, (*ht)[i].LChild, (*ht)[i].RChild);
    }
}

// main函数，程序入口点，返回int类型表示程序退出状态
int main()
{
    int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
    int n = 8;
    HuffmanTree ht;
    HuffmanCode hc;

    // 调用函数构建哈夫曼树并生成编码
    CrtHuffmanTree(&ht, &hc, w, n);

    // 输出哈夫曼树的节点信息
    printHT(&ht, 2 * n - 1);

    // 输出每个节点的哈夫曼编码
    printCode(w, &hc, n);

    // 返回0表示程序正常退出
    return 0;
}
