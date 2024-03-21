#include <stdio.h>

void TowerHanoi(int m, int i, int j);

int main() {
    TowerHanoi(3, 1, 3);
    return 0;
}

void TowerHanoi(int m, int i, int j) {
    if (m == 1) {
        printf("Disc 1 from %d to %d\n", i, j);
    } else {
        int temp = 6 - i - j; // 1 + 2 + 3 = 6, 6 - i - j gives the remaining peg
        TowerHanoi(m - 1, i, temp);
        printf("Disc %d from %d to %d\n", m, i, j);
        TowerHanoi(m - 1, temp, j);
    }
}

