#include <stdio.h>
#include <stdlib.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    if (i == n || wx == 0)
        return 0;

    if (w[i] > wx)
        return KnapsackBT(w, v, n, wx, i + 1, x);

    int include = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, x);
    int exclude = KnapsackBT(w, v, n, wx, i + 1, x);

    if (include > exclude) {
        x[i] = 1;
        return include;
    } else {
        x[i] = 0;
        return exclude;
    }
}

int main() {
    int n = 5, wx = 11;
    int w[5] = {1, 2, 5, 6, 7};
    int v[5] = {1, 6, 18, 22, 28};
    int *x = new int[n];
    int vx = KnapsackBT(w, v, n, wx, 0, x);
    printf("Value = %d \n", vx);
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]);
    delete[] x;
    return 0;
}

