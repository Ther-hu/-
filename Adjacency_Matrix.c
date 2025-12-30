#include <stdio.h>
#define MAXSIZE 100
#define MAX 32767

typedef char VertexTypet;
typedef int EdgeType;

typedef struct 
{
    VertexTypet vertex[MAXSIZE]; //顶点表
    EdgeType arc[MAXSIZE][MAXSIZE]; //邻接矩阵
    int vertex_num, edge_num; //图的当前顶点数和边数
}Adjacency_Matrix; //邻接矩阵类型定义

void CreateUndirectedNet(Adjacency_Matrix *G) //创建无向网(无权值)的邻接矩阵
{
    int i, j, k, w;
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->vertex_num, &G->edge_num);
    printf("请输入各顶点信息：\n");
    for(i = 0; i < G->vertex_num; i++)
        scanf(" %c", &G->vertex[i]);

    //初始化邻接矩阵
    for(i = 0; i < G->vertex_num; i++)
        for(j = 0; j < G->vertex_num; j++)
            G->arc[i][j] = MAX;
            if (i == j)
                G->arc[i][j] = 0;

    printf("请输入各边的信息(格式: 起点 终点 权值)：\n");
    for(k = 0; k < G->edge_num; k++)
    {
        scanf(" %c %c %d", &i, &j, &w);
        int m, n;
        //找到顶点对应的下标
        for(m = 0; m < G->vertex_num; m++)
            if(G->vertex[m] == i)
                break;
        for(n = 0; n < G->vertex_num; n++)
            if(G->vertex[n] == j)
                break;
        G->arc[m][n] = w;
        G->arc[n][m] = w; //无向网对称赋值
    }
}

void DisplayAdjacencyMatrix(Adjacency_Matrix G) //输出邻接矩阵
{
    int i, j;
    printf("邻接矩阵为：\n");
    for(i = 0; i < G.vertex_num; i++)
    {
        for(j = 0; j < G.vertex_num; j++)
        {
            if(G.arc[i][j] == MAX)
                printf("∞ ");
            else
                printf("%d ", G.arc[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Adjacency_Matrix G;
    CreateUndirectedNet(&G);
    DisplayAdjacencyMatrix(G);
    return 0;
}