#include <stdio.h>

struct ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

void merge(struct ITEM a[], int low, int mid, int high, int type) {
    struct ITEM temp[100];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        int condition;

        if (type == 1)
            condition = a[i].item_profit >= a[j].item_profit;
        else if (type == 2)
            condition = a[i].item_weight <= a[j].item_weight;
        else
            condition = a[i].profit_weight_ratio >= a[j].profit_weight_ratio;

        if (condition)
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

void mergeSort(struct ITEM a[], int low, int high, int type) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid, type);
        mergeSort(a, mid + 1, high, type);
        merge(a, low, mid, high, type);
    }
}

void fractionalKnapsack(struct ITEM original[], int n, float capacity, int type) {
    struct ITEM a[100];
    float totalProfit = 0;
    float remaining = capacity;

    for (int i = 0; i < n; i++)
        a[i] = original[i];

    mergeSort(a, 0, n - 1, type);

    printf("\n");

    if (type == 1)
        printf("GREEDY WITH RESPECT TO PROFIT\n");
    else if (type == 2)
        printf("GREEDY WITH RESPECT TO WEIGHT\n");
    else
        printf("GREEDY WITH RESPECT TO PROFIT/WEIGHT\n");

    printf("\n");
    printf("Item No\tProfit\tWeight\tAmount to be taken\n");

    for (int i = 0; i < n; i++) {
        float amount;

        if (remaining <= 0)
            amount = 0;
        else if (a[i].item_weight <= remaining)
            amount = 1;
        else
            amount = remaining / a[i].item_weight;

        totalProfit += amount * a[i].item_profit;
        remaining -= amount * a[i].item_weight;

        printf("%d\t%.3f\t%.3f\t%.6f\n",
               a[i].item_id,
               a[i].item_profit,
               a[i].item_weight,
               amount);
    }

    printf("\nMaximum profit: %.6f\n", totalProfit);
}

int main() {
    struct ITEM items[100];
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        items[i].item_id = i + 1;

        printf("Enter the profit and weight of item no%d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);

        items[i].profit_weight_ratio =
            items[i].item_profit / items[i].item_weight;
    }

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    fractionalKnapsack(items, n, capacity, 1);
    fractionalKnapsack(items, n, capacity, 2);
    fractionalKnapsack(items, n, capacity, 3);

    return 0;
}
