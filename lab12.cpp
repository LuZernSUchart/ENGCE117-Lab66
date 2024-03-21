#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    int *x = (int *)calloc(n, sizeof(int));

    double *ratio = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)v[i] / w[i];
    }

    while (wx > 0) {
        double max_ratio = 0;
        int max_index = -1;
        for (int i = 0; i < n; i++) {
            if (ratio[i] > max_ratio && w[i] <= wx && x[i] != 1) {
                max_ratio = ratio[i];
                max_index = i;
            }
        }

        if (max_index == -1)
            break;

        x[max_index] = 1;
        wx -= w[max_index];
    }

    return x;
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x = KnapsackGreedy(w, v, n, wx);
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);
    free(x);
    return 0;
}

