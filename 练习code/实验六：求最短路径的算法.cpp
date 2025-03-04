#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define INF 999 // ���ֵ��
#define MAX_VERTEX_NUM 20 // ��󶥵���

typedef struct {
    int vexs[MAX_VERTEX_NUM]; // ��������
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // �ڽӾ���
    int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���
} MGraph;

typedef int Patharc;   /*���ڴ洢���·���±������*/
typedef int ShortPathTable;  /*���ڴ洢���������·����Ȩֵ��*/

// Dijkstra�㷨ʵ�ֺ���
void ShortestPath_DIJ(MGraph G, int v0, Patharc* P, ShortPathTable* D)
{
    int final[MAX_VERTEX_NUM];  // ��Ƕ����Ƿ����ҵ����·����1��ʾ���ҵ���0��ʾδ�ҵ�
    int v, w, i, min;

    // ��ʼ��
    for (v = 0; v < G.vexnum; v++) {
        final[v] = FALSE;  // ��ʼ���ж��㶼δȷ�����·��
        D[v] = G.arcs[v0][v];  // v0��������ĳ�ʼ����
        P[v] = (D[v] < INF)? v0 : -1;  // ��¼ǰ�����㣬����ʼ���벻���������ǰ��Ϊv0������Ϊ -1
    }
    D[v0] = 0;  // v0���������Ϊ0
    final[v0] = TRUE;  // v0�����·����ȷ��

    // ѭ��Ѱ��ÿ����������·��
    for (i = 1; i < G.vexnum; i++) {
        min = INF;
        // Ѱ��δȷ�����·���Ķ����о���v0����Ķ���
        for (w = 0; w < G.vexnum; w++) {
            if (!final[w] && D[w] < min) {
                v = w;
                min = D[w];
            }
        }
        final[v] = TRUE;  // ��Ǹö������ҵ����·��

        // �������ȷ�����·���������ڵĶ���ľ�����Ϣ���ɳڲ�����
        for (w = 0; w < G.vexnum; w++) {
            if (!final[w] && G.arcs[v][w] < INF && D[v] + G.arcs[v][w] < D[w]) {
                D[w] = D[v] + G.arcs[v][w];
                P[w] = v;
            }
        }
    }
}

// ������·�������·�����ȵĺ���
void Dispath(MGraph g, Patharc* P, ShortPathTable* D)
{
    int i;
    printf("����        : ");/* ���� */
    for (i = 0; i < g.vexnum; ++i)
        printf("V%-5d", g.vexs[i]);
    printf("\n���·������: ");/* Ȩֵ */
    for (i = 0; i < g.vexnum; i++)
        printf("%-6d", D[i]);
    printf("\n���·��    : ");/* ·�� */
    for (i = 0; i < g.vexnum; i++)
        printf("%-6d", P[i]);
}

int main() {
    int i, j;
    MGraph G;
    Patharc P[MAX_VERTEX_NUM];
    ShortPathTable D[MAX_VERTEX_NUM];
    G.vexnum = 6;  /*����*/
    G.arcnum = 8;  /*��*/

    // ����������ʼ�����򵥸�ֵΪ0��5
    for (i = 0; i < G.vexnum; i++)
        G.vexs[i] = i;

    // �ڽӾ����ʼ������ȫ����ΪINF
    for (i = 0; i < MAX_VERTEX_NUM; i++) {
        for (j = 0; j < MAX_VERTEX_NUM; j++)
            G.arcs[i][j] = INF;
    }
    // ����ʾ�����þ���ıߵ�Ȩֵ
    G.arcs[0][2] = 10;
    G.arcs[0][4] = 30;
    G.arcs[2][3] = 50;
    G.arcs[3][5] = 60;
    G.arcs[4][3] = 20;
    G.arcs[4][5] = 40;
    G.arcs[5][1] = 10;
    G.arcs[5][2] = 5;
    // �������������Ϊ0
    for (i = 0; i < G.vexnum; i++)
        G.arcs[i][i] = 0;

    // ����Dijkstra�㷨����
    ShortestPath_DIJ(G, 0, P, D);

    // ������·�������·������
    Dispath(G, P, D);

    return 0;
}
