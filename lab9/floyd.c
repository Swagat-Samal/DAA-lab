#include <stdio.h>

#define MAX 100
#define INF 99999

int dist[MAX][MAX];
int next[MAX][MAX];
int n;

void printPath(int u, int v)
{
    if (next[u][v] == -1)
    {
        printf("No path");
        return;
    }

    printf("%d", u + 1);

    while (u != v)
    {
        u = next[u][v];
        printf(" -> %d", u + 1);
    }
}

int main()
{
    FILE *fp;
    int i, j, k;
    int u, v;

    fp = fopen("inDiAdjMat2.dat", "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open inDiAdjMat2.dat\n");
        return 1;
    }

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int x;
            fscanf(fp, "%d", &x);

            if (i == j)
            {
                dist[i][j] = 0;
                next[i][j] = j;
            }
            else if (x == 0)
            {
                dist[i][j] = INF;
                next[i][j] = -1;
            }
            else
            {
                dist[i][j] = x;
                next[i][j] = j;
            }
        }
    }

    fclose(fp);

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    printf("\nShortest Path Weight Matrix:\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter source vertex (u): ");
    scanf("%d", &u);

    printf("Enter destination vertex (v): ");
    scanf("%d", &v);

    u--;
    v--;

    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        printf("Invalid vertices.\n");
        return 1;
    }

    if (dist[u][v] == INF)
    {
        printf("\nNo path exists from %d to %d.\n", u + 1, v + 1);
    }
    else
    {
        printf("\nShortest path from %d to %d: ", u + 1, v + 1);
        printPath(u, v);

        printf("\nShortest path length: %d\n", dist[u][v]);
    }

    return 0;
}
