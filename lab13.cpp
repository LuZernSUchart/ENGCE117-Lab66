#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int *KnapsackDP(int *w, int *v, int n, int wx) {
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((wx + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i - 1] <= j)
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int *x = (int *)malloc(n * sizeof(int));
    for (int i = n, j = wx; i > 0 && j > 0; i--) {
        if (dp[i][j] != dp[i - 1][j]) {
            x[i - 1] = 1;
            j -= w[i - 1];
        } else {
            x[i - 1] = 0;
        }
    }

    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x = KnapsackDP(w, v, n, wx);
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);
    free(x);
    return 0;
}

