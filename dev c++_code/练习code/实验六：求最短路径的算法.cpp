#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define INF 999 // 最大值∞
#define MAX_VERTEX_NUM 20 // 最大顶点数

typedef struct {
    int vexs[MAX_VERTEX_NUM]; // 顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vexnum, arcnum; // 图的当前顶点数和弧数
} MGraph;

typedef int Patharc;   /*用于存储最短路径下标的数组*/
typedef int ShortPathTable;  /*用于存储到各个最短路径的权值和*/

// Dijkstra算法实现函数
void ShortestPath_DIJ(MGraph G, int v0, Patharc* P, ShortPathTable* D)
{
    int final[MAX_VERTEX_NUM];  // 标记顶点是否已找到最短路径，1表示已找到，0表示未找到
    int v, w, i, min;

    // 初始化
    for (v = 0; v < G.vexnum; v++) {
        final[v] = FALSE;  // 初始所有顶点都未确定最短路径
        D[v] = G.arcs[v0][v];  // v0到各顶点的初始距离
        P[v] = (D[v] < INF)? v0 : -1;  // 记录前驱顶点，若初始距离不是无穷大则前驱为v0，否则为 -1
    }
    D[v0] = 0;  // v0到自身距离为0
    final[v0] = TRUE;  // v0的最短路径已确定

    // 循环寻找每个顶点的最短路径
    for (i = 1; i < G.vexnum; i++) {
        min = INF;
        // 寻找未确定最短路径的顶点中距离v0最近的顶点
        for (w = 0; w < G.vexnum; w++) {
            if (!final[w] && D[w] < min) {
                v = w;
                min = D[w];
            }
        }
        final[v] = TRUE;  // 标记该顶点已找到最短路径

        // 更新与刚确定最短路径顶点相邻的顶点的距离信息（松弛操作）
        for (w = 0; w < G.vexnum; w++) {
            if (!final[w] && G.arcs[v][w] < INF && D[v] + G.arcs[v][w] < D[w]) {
                D[w] = D[v] + G.arcs[v][w];
                P[w] = v;
            }
        }
    }
}

// 输出最短路径和最短路径长度的函数
void Dispath(MGraph g, Patharc* P, ShortPathTable* D)
{
    int i;
    printf("顶点        : ");/* 顶点 */
    for (i = 0; i < g.vexnum; ++i)
        printf("V%-5d", g.vexs[i]);
    printf("\n最短路径长度: ");/* 权值 */
    for (i = 0; i < g.vexnum; i++)
        printf("%-6d", D[i]);
    printf("\n最短路径    : ");/* 路径 */
    for (i = 0; i < g.vexnum; i++)
        printf("%-6d", P[i]);
}

int main() {
    int i, j;
    MGraph G;
    Patharc P[MAX_VERTEX_NUM];
    ShortPathTable D[MAX_VERTEX_NUM];
    G.vexnum = 6;  /*顶点*/
    G.arcnum = 8;  /*弧*/

    // 顶点向量初始化，简单赋值为0到5
    for (i = 0; i < G.vexnum; i++)
        G.vexs[i] = i;

    // 邻接矩阵初始化，先全部设为INF
    for (i = 0; i < MAX_VERTEX_NUM; i++) {
        for (j = 0; j < MAX_VERTEX_NUM; j++)
            G.arcs[i][j] = INF;
    }
    // 根据示例设置具体的边的权值
    G.arcs[0][2] = 10;
    G.arcs[0][4] = 30;
    G.arcs[2][3] = 50;
    G.arcs[3][5] = 60;
    G.arcs[4][3] = 20;
    G.arcs[4][5] = 40;
    G.arcs[5][1] = 10;
    G.arcs[5][2] = 5;
    // 自身到自身距离设为0
    for (i = 0; i < G.vexnum; i++)
        G.arcs[i][i] = 0;

    // 调用Dijkstra算法函数
    ShortestPath_DIJ(G, 0, P, D);

    // 输出最短路径和最短路径长度
    Dispath(G, P, D);

    return 0;
}
