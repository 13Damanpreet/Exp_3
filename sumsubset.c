#include <stdio.h>

void findSubset(int arr[], int n, int sum, int current[], int currentSize, int idx) {
    if (sum == 0) {
        printf("Subset: ");
        for (int i = 0; i < currentSize; i++) {
            printf("%d ", current[i]);
        }
        printf("\n");
        return;
    }

    if (idx == n) {
        return; 
    }

    current[currentSize] = arr[idx];
    findSubset(arr, n, sum - arr[idx], current, currentSize + 1, idx + 1);

    findSubset(arr, n, sum, current, currentSize, idx + 1);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2}; 
    int sum = 9;  
    int n = sizeof(arr) / sizeof(arr[0]);
    int current[n];

    printf("Subsets with sum %d are:\n", sum);
    findSubset(arr, n, sum, current, 0, 0);

    return 0;
}
