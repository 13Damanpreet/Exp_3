#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio;  
} Item;

int compare(const void *a, const void *b) {
    return ((Item *)b)->ratio - ((Item *)a)->ratio;
}

void greedyKnapsack(Item items[], int n, int W) {
    qsort(items, n, sizeof(Item), compare);

    int totalValue = 0;
    int currentWeight = 0;

    printf("Greedy Approach:\n");

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Weight = %d, Value = %d\n", i + 1, items[i].weight, items[i].value);
        }
    }

    printf("Maximum value (Greedy): %d\n", totalValue);
}

int main() {
    int W = 5;
    Item items[] = {
        {2, 3, 3.0/2},  
        {3, 4, 4.0/3},  
        {4, 5, 5.0/4},  
        {5, 8, 8.0/5}   
    };
    
    int n = sizeof(items) / sizeof(items[0]);

    greedyKnapsack(items, n, W);

    return 0;
}
