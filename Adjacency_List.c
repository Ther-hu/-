#include <stdio.h>
#define MAXSIZE 100

typedef struct EdgeNode
{
    int adjvex; //该边所指向的顶点位置
    int weight; //边的权值（无权图可省略此项）
    struct EdgeNode *next; //指向下一条边的指针
} EdgeNode; //边结点类型定义

typedef struct VertexType
{
    char data; //顶点信息
    EdgeNode *firstedge; //指向第一条边的指针
} VertexType, AdjList[MAXSIZE]; //顶点类型定义

typedef struct
{
    AdjList vertices; //邻接表
    int vertex_num, edge_num; //图的当前顶点数和边数
} Adjacency_List; //邻接表类型定义

void CreateUndirectedGraph(Adjacency_List *G) //创建无向图的邻接表
{
    int i, j, k, weight;
    char v1, v2;
    EdgeNode *e;
    printf("请输入顶点数和边数：");
    scanf("%d %d", &G->vertex_num, &G->edge_num);
    printf("请输入各顶点信息：\n");
    for(i = 0; i < G->vertex_num; i++)
    {
        scanf(" %c", &G->vertices[i].data);
        G->vertices[i].firstedge = NULL; //初始化表头指针
    }

    printf("请输入各边的信息(格式: 起点 终点 权值)：\n");
    for(k = 0; k < G->edge_num; k++)
    {
        scanf(" %c %c %d", &v1, &v2, &weight);
        //找到顶点对应的下标
        for(i = 0; i < G->vertex_num; i++)
            if(G->vertices[i].data == v1)
                break;
        for(j = 0; j < G->vertex_num; j++)
            if(G->vertices[j].data == v2)
                break;
        //创建边结点1
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->weight = weight;
        e->next = G->vertices[i].firstedge;
        G->vertices[i].firstedge = e; //将e插入顶点i的边表头部

        //创建边结点2（无向图对称插入）
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->weight = weight;
        e->next = G->vertices[j].firstedge;
        G->vertices[j].firstedge = e; //将e插入顶点j的边表头部
    }
}

void DisplayAdjacencyList(Adjacency_List G) //输出邻接表
{
    int i;
    EdgeNode *p;
    printf("邻接表为：\n");
    for(i = 0; i < G.vertex_num; i++)
    {
        printf("%c:", G.vertices[i].data);
        p = G.vertices[i].firstedge;
        while(p)
        {
            printf("->%c[%d]", G.vertices[p->adjvex].data, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    Adjacency_List G;
    CreateUndirectedGraph(&G);
    DisplayAdjacencyList(G);
    return 0;
}