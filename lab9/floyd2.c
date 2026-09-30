#include <stdio.h>

#define INF 99999
#define MAX 10

int main()
{
    int n, i, j, k;
    int dist[MAX][MAX];
    int next[MAX][MAX];

    FILE *fp = fopen("inDiAdjMat1.dat", "r");

    if (fp == NULL)
    {
        printf("Error opening input file.\n");
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

    printf("\nAll-Pairs Shortest Path Matrix:\n\n");

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

    printf("\nShortest paths:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && dist[i][j] != INF)
            {
                int current = i;

                printf("%d -> %d : ", i + 1, j + 1);
                printf("%d", current + 1);

                while (current != j)
                {
                    current = next[current][j];
                    printf(" -> %d", current + 1);
                }

                printf("  (Cost = %d)\n", dist[i][j]);
            }
        }
    }

    return 0;
}
