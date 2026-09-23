#include <stdio.h>
#include <string.h>

#define MAX 100

int LCS[MAX][MAX];

int main() {
    char S1[MAX], S2[MAX], LCSString[MAX];
    int n, i, j, k = 0;
    int count = 0;

    printf("Enter length of sequences: ");
    scanf("%d", &n);

    printf("Enter first sequence: ");
    scanf("%s", S1);

    printf("Enter second sequence: ");
    scanf("%s", S2);

    for (i = 0; i <= n; i++) {
        LCS[i][0] = 0;
        LCS[0][i] = 0;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {

            if (S1[i - 1] == S2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] =
                    (LCS[i - 1][j] > LCS[i][j - 1])
                    ? LCS[i - 1][j]
                    : LCS[i][j - 1];
            }
        }
    }

    i = n;
    j = n;

    while (i > 0 && j > 0) {

        if (S1[i - 1] == S2[j - 1]) {
            LCSString[k++] = S1[i - 1];
            i--;
            j--;
        } else if (LCS[i - 1][j] >= LCS[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    LCSString[k] = '\0';

    for (i = 0; i < k; i++) {
        if (LCSString[i] == 'T') {
            count++;
        }
    }

    printf("\nLength of LCS: %d", LCS[n][n]);
    printf("\nFrequency of T: %d\n", count);

    return 0;
}
