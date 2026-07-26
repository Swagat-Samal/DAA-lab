#include <stdio.h>
#include <limits.h>

int main() {
    int n, a[100], min=INT_MAX, smin=INT_MAX;
    int max=INT_MIN, smax=INT_MIN;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);

        if(a[i] < min) {
            smin = min;
            min = a[i];
        }
        else if(a[i] < smin && a[i] != min)
            smin = a[i];

        if(a[i] > max) {
            smax = max;
            max = a[i];
        }
        else if(a[i] > smax && a[i] != max)
            smax = a[i];
    }

    printf("Second Smallest = %d\n", smin);
    printf("Second Largest = %d\n", smax);

    return 0;
}
