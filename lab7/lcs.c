#include <stdio.h>
#include <string.h>

int main() {
    char X[100], Y[100];
    int dp[101][101];
    int i, j, m, n;

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1])
                           ? dp[i - 1][j]
                           : dp[i][j - 1];
        }
    }

    char lcs[101];
    int index = dp[m][n];

    lcs[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    printf("\nLCS length = %d\n", dp[m][n]);
    printf("LCS = ");

    for (i = 0; lcs[i] != '\0'; i++)
        printf("%c ", lcs[i]);

    printf("\n");

    return 0;
}
