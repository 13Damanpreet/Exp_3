#include <stdio.h>
#include <limits.h>

void matrixChainMultiplication(int p[], int n) {
    int m[n][n]; 

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int chainLength = 2; chainLength < n; chainLength++) {
        for (int i = 1; i < n - chainLength + 1; i++) {
            int j = i + chainLength - 1;
            m[i][j] = INT_MAX; // Initialize to a large value

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
}

int main() {
    int p[] = {10, 20, 30, 40, 30};
    int n = sizeof(p) / sizeof(p[0]);

    matrixChainMultiplication(p, n);

    return 0;
}
