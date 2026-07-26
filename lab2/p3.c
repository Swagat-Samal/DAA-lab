#include <stdio.h>

int largest_unimodal(int arr[], int n) {
    int low = 0, high = n - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return arr[low];
}

int main() {
    int n, i;

    printf("Enter size of unimodal array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Largest element = %d\n", largest_unimodal(arr, n));

    printf("Time Complexity = O(log n)\n");

    return 0;
}
