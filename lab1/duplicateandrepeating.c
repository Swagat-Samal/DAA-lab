#include <stdio.h>

int main() {
    int n, a[100];
    int duplicate = 0;
    int maxCount = 0, repeat = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++) {

        int already = 0;
        for(int k = 0; k < i; k++) {
            if(a[i] == a[k]) {
                already = 1;
                break;
            }
        }

        if(already)
            continue;

        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j])
                count++;
        }

        if(count > 1)
            duplicate++;

        if(count > maxCount) {
            maxCount = count;
            repeat = a[i];
        }
    }

    printf("Duplicate elements = %d\n", duplicate);
    printf("Most repeating element = %d\n", repeat);

    return 0;
}       
