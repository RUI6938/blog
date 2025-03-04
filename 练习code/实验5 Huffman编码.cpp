#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������������ڵ�ṹ��
typedef struct
{
    int weight;
    int parent;
    int LChild;
    int RChild;
} HTNode, *HuffmanTree;/* ��̬��������洢�������� */

typedef char **HuffmanCode; /* ��̬��������洢����������� */


void select(HuffmanTree *ht, int n, int *s1, int *s2)// ��(*ht)[1]~ (*ht)[i-1]�ķ�Χ��ѡ��weight��С(��parentΪ0)��������㣬����ŷֱ�ֵ��s1��s2���أ���*s1<*s2
{
    int i;
    // ��ʼ�������ϴ��ֵ�����ڱȽ��ҵ���С��Ȩֵ
    int min1 = 32767, min2 = 32767;  
    *s1 = *s2 = 0;

    for (i = 1; i <= n; i++)
    {
        // ֻ����parentΪ0�Ľڵ㣬��δ������ϲ��������������Ľڵ�
        if ((*ht)[i].parent == 0 && (*ht)[i].weight < min1)
        {
            // ����min2��*s2����Ϊ�ҵ��˸�С��min1��ԭ����min1��Ϊ��Сֵmin2
            min2 = min1;  
            *s2 = *s1;  
            // ����min1��*s1����¼��ǰ�ҵ�����СȨֵ�ڵ����
            min1 = (*ht)[i].weight;  
            *s1 = i;  
        }
        else if ((*ht)[i].parent == 0 && (*ht)[i].weight < min2)
        {
            // �ҵ���min2��С��������С��Ȩֵ�ڵ㣬����min2��*s2
            min2 = (*ht)[i].weight;
            *s2 = i;
        }
    }
}

// w���n���ַ���Ȩֵ(��>0)�������������ht�������n���ַ��Ĺ���������hc
void CrtHuffmanTree(HuffmanTree *ht, HuffmanCode *hc, int *w, int n)
{
    // 1. ��ʼ��
    int m = 2 * n - 1;  
    // ��̬�����������洢���������ڵ㣬��СΪm + 1��HTNode�ṹ��
    *ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    if (!(*ht))
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    int i;
    // ��ʼ��ǰn���ڵ㣬���������Ȩֵ����w����weight���������Գ�ʼ��Ϊ0
    for (i = 1; i <= n; i++)
    {
        (*ht)[i].weight = w[i - 1];
        (*ht)[i].parent = 0;
        (*ht)[i].LChild = 0;
        (*ht)[i].RChild = 0;
    }
    // ��ʼ����m - n���ڵ㣬weight��parent��LChild��RChild����ʼ��Ϊ0
    for (i = n + 1; i <= m; i++)
    {
        (*ht)[i].weight = 0;
        (*ht)[i].parent = 0;
        (*ht)[i].LChild = 0;
        (*ht)[i].RChild = 0;
    }

    // 2. ����������
    int s1, s2;
    for (i = n + 1; i <= m; i++)
    {
        select(ht, i - 1, &s1, &s2);
        // �����ҵ���������СȨֵ�ڵ�s1��s2�ĸ��ڵ�Ϊ��ǰ���ڹ������½ڵ�i
        (*ht)[s1].parent = i;
        (*ht)[s2].parent = i;
        // �����½ڵ�i������Ϊs1���Һ���Ϊs2
        (*ht)[i].LChild = s1;
        (*ht)[i].RChild = s2;
        // �½ڵ�i��ȨֵΪ�������ӽڵ�Ȩֵ֮��
        (*ht)[i].weight = (*ht)[s1].weight + (*ht)[s2].weight;
    }

    // 3. ��Ҷ�ӵ�����������ÿ���ַ��Ĺ���������
    *hc = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    if (!(*hc))
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    char *cd;
    cd = (char *)malloc(n * sizeof(char));
    if (!cd)
    {
        printf("�ڴ����ʧ�ܣ�\n");
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
            // �����ǰ�ڵ�c���丸�ڵ�f�����ӣ�����Ϊ0
            if ((*ht)[f].LChild == c)
                cd[--start] = '0';
            // �����ǰ�ڵ�c���丸�ڵ�f���Һ��ӣ�����Ϊ1
            else
                cd[--start] = '1';
            c = f;
            f = (*ht)[c].parent;
        }
        // Ϊ��ǰ�ַ��Ĺ�������������㹻���ڴ�ռ�
        (*hc)[i] = (char *)malloc((n - start) * sizeof(char));
        // �����ɵı����ַ������Ƶ��������Ӧλ��
        strcpy((*hc)[i], &cd[start]);
    }
    free(cd);
}

// �����㼰�����
void printCode(int *w, HuffmanCode *hc, int n)
{
    int i;
    for (i = 1; i <= n; ++i)
    {
        printf("%2d| %3d --> %s\n", i, w[i - 1], (*hc)[i]);
    }
}

// ����շ�������m��2n - 1
void printHT(HuffmanTree *ht, int m)
{
    int i;
    printf("   weight parent lchild rchild\n");
    for (i = 1; i <= m; i++)
    {
        printf("%2d|%4d   %4d   %4d   %2d \n", i, (*ht)[i].weight, (*ht)[i].parent, (*ht)[i].LChild, (*ht)[i].RChild);
    }
}

// main������������ڵ㣬����int���ͱ�ʾ�����˳�״̬
int main()
{
    int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
    int n = 8;
    HuffmanTree ht;
    HuffmanCode hc;

    // ���ú��������������������ɱ���
    CrtHuffmanTree(&ht, &hc, w, n);

    // ������������Ľڵ���Ϣ
    printHT(&ht, 2 * n - 1);

    // ���ÿ���ڵ�Ĺ���������
    printCode(w, &hc, n);

    // ����0��ʾ���������˳�
    return 0;
}
