#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main()
{
    int n, start;
    int graph[MAX][MAX];
    int mst[MAX][MAX] = {0};
    Edge edges[MAX * MAX];
    int edgeCount = 0;
    int i, j, k = 0;
    int totalCost = 0;
    FILE *fp;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &start);

    fp = fopen("inUnAdjMat.dat", "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open inUnAdjMat.dat\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }

    fclose(fp);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    for (i = 0; i < edgeCount - 1; i++)
    {
        for (j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < edgeCount && k < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            unionSet(u, v);

            mst[u][v] = edges[i].weight;
            mst[v][u] = edges[i].weight;

            totalCost += edges[i].weight;
            k++;
        }
    }

    printf("\nMinimum Cost Spanning Tree using Kruskal's Algorithm\n");

    printf("\nCost Adjacency Matrix of MST:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%4d", mst[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal Cost of MST = %d\n", totalCost);

    return 0;
}
