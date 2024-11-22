#include <stdio.h>

void knapsackDP(int W, int n, int weights[], int values[]) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = (dp[i - 1][w] > dp[i - 1][w - weights[i - 1]] + values[i - 1]) ? dp[i - 1][w] : dp[i - 1][w - weights[i - 1]] + values[i - 1];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Dynamic Programming Approach:\n");
    printf("Maximum value (DP): %d\n", dp[n][W]);

    int w = W;
    printf("Selected items:\n");
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d: Weight = %d, Value = %d\n", i, weights[i - 1], values[i - 1]);
            w -= weights[i - 1];
        }
    }
}

int main() {
    int W = 5;  
    int weights[] = {2, 3, 4, 5}; 
    int values[] = {3, 4, 5, 8};   
    int n = sizeof(weights) / sizeof(weights[0]);

    knapsackDP(W, n, weights, values);

    return 0;
}
