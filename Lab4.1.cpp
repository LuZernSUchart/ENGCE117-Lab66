#include <stdio.h>
#include <stdlib.h>

void go(int **p, int *z);

int main() {
    int *a, b = 10, c = 20;

    // Allocate memory for the pointer a
    a = (int *)malloc(sizeof(int));

    go(&a, &b);
    printf("%d %p %p\n", *a, (void *)a, (void *)&a);

    go(&a, &c);
    printf("%d %p %p\n", *a, (void *)a, (void *)&a);

    // Don't forget to free the allocated memory
    free(a);

    return 0;
}

void go(int **p, int *z) {
    // Allocate memory for the pointer *p
    *p = (int *)malloc(sizeof(int));

    // Assign the value of z to the memory pointed by *p
    **p = *z;
}
