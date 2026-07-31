#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long comparisons = 0;

void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[1000];

    while (i <= mid && j <= high)
    {
        comparisons++;

        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int readFile(char filename[], int a[])
{
    FILE *fp;
    int n = 0;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    while (fscanf(fp, "%d", &a[n]) != EOF)
        n++;

    fclose(fp);

    return n;
}

void writeFile(char filename[], int a[], int n)
{
    FILE *fp;
    int i;

    fp = fopen(filename, "w");

    for (i = 0; i < n; i++)
        fprintf(fp, "%d ", a[i]);

    fclose(fp);
}

int main()
{
    int a[1000];
    int n;
    int choice;

    char inputFile[50];
    char outputFile[50];

    clock_t start, end;
    double time_taken;

    while (1)
    {
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sprintf(inputFile, "inASCE.dat");
            sprintf(outputFile, "OutMergeASCE.dat");
            break;

        case 2:
            sprintf(inputFile, "inDESC.dat");
            sprintf(outputFile, "OutMergeDESC.dat");
            break;

        case 3:
            sprintf(inputFile, "inRandom.dat");
            sprintf(outputFile, "OutMergeRandom.dat");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice\n");
            continue;
        }

        n = readFile(inputFile, a);

        comparisons = 0;

        start = clock();

        mergeSort(a, 0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        writeFile(outputFile, a, n);

        printf("\nElements = %d\n", n);
        printf("Comparisons = %lld\n", comparisons);
        printf("Execution Time = %lf seconds\n", time_taken);
        printf("Sorted data stored in %s\n", outputFile);
    }

    return 0;
}
