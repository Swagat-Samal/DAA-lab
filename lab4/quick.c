#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500

long long comparisons = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        comparisons++;

        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int readFile(char filename[], int a[])
{
    FILE *fp;
    int n = 0;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Unable to open %s\n", filename);
        return 0;
    }

    while (fscanf(fp, "%d", &a[n]) == 1 && n < MAX)
    {
        n++;
    }

    fclose(fp);

    return n;
}

void writeFile(char filename[], int a[], int n)
{
    FILE *fp;
    int i;

    fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("Unable to create %s\n", filename);
        return;
    }

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d ", a[i]);
    }

    fclose(fp);
}

void displayArray(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);

        if ((i + 1) % 20 == 0)
            printf("\n");
    }

    printf("\n");
}

int main()
{
    int choice;
    int a[MAX];
    int n;
    char inputFile[30];
    char outputFile[30];
    clock_t start, end;
    double executionTime;

    while (1)
    {
     
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            printf("Program terminated.\n");
            break;
        }

        switch (choice)
        {            case 1:
                sprintf(inputFile, "inASCE.dat");
                sprintf(outputFile, "outQuickASC.dat");
                break;

            case 2:
                sprintf(inputFile, "inDESC.dat");
                sprintf(outputFile, "outQuickDESC.dat");
                break;

            case 3:
                sprintf(inputFile, "inRandom.dat");
                sprintf(outputFile, "outQuickRandom.dat");
                break;

            default:
                printf("Invalid choice!\n");
                continue;
        }

        n = readFile(inputFile, a);

        if (n == 0)
            continue;

        comparisons = 0;

        start = clock();

        quickSort(a, 0, n - 1);

        end = clock();

        executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;

        writeFile(outputFile, a, n);

        printf("\nElements = %d\n", n);
        printf("Number of comparisons: %lld\n", comparisons);
        printf("Execution time for sorting: %.6f seconds\n", executionTime);
        printf("Sorted data stored in : %s\n", outputFile);
    }

    return 0;
}
