#include <stdio.h>

void EXCHANGE(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int p1[], int p2)
{
    for(int i = p2 - 1; i > 0; i--)
    {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main()
{
    int n, a[100], p2;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter number of elements to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    ROTATE_RIGHT(a, p2);

    printf("\nAfter ROTATE: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
