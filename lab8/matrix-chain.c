#include <stdio.h>
#include <limits.h>

#define MAX 20

int M[MAX][MAX];
int S[MAX][MAX];
int p[MAX];

void printParenthesis(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");

    printParenthesis(i, S[i][j]);
    printParenthesis(S[i][j] + 1, j);

    printf(")");
}

int main()
{
    int n;
    int i, j, k, L;
    int rows, cols;
    int q;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter row and column size of A%d: ", i);
        scanf("%d %d", &rows, &cols);

        if (i > 1 && p[i - 1] != rows)
        {
            printf("Invalid matrix dimensions!\n");
            return 0;
        }

        if (i == 1)
        {
            p[0] = rows;
        }

        p[i] = cols;
    }
    for (i = 1; i <= n; i++)
    {
        M[i][i] = 0;
    }
    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;

            M[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                q = M[i][k]
                    + M[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

                if (q < M[i][j])
                {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    printf("\nM TABLE\n");

    printf("\t");

    for (i = 1; i <= n; i++)
    {
        printf("A%d\t", i);
    }

    printf("\n");

    for (i = 1; i <= n; i++)
    {
        printf("A%d\t", i);

        for (j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                printf("%d\t", M[i][j]);
            }
            else
            {
                printf("0\t");
            }
        }

        printf("\n");
    }

    printf("\n\nS TABLE\n");

    printf("\t");

    for (i = 1; i <= n; i++)
    {
        printf("A%d\t", i);
    }

    printf("\n");

    for (i = 1; i <= n; i++)
    {
        printf("A%d\t", i);

        for (j = 1; j <= n; j++)
        {
            if (i < j)
            {
                printf("%d\t", S[i][j]);
            }
            else
            {
                printf("0\t");
            }
        }

        printf("\n");
    }

    printf("\nOptimal Parenthesization: ");
    printParenthesis(1, n);

    printf("\nMinimum Scalar Multiplications: %d\n", M[1][n]);

    return 0;
}
