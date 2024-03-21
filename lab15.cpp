#include <stdio.h>
#include <math.h>

double f(double x) {
    return 2 * x - 5;
}

double RootOfFunction(double xl, double xr, double epsilon) {
    double fl = f(xl);
    double fr = f(xr);

    if (fl * fr > 0) {
        printf("No root found in the given interval.\n");
        return NAN;
    }

    while (fabs(xr - xl) > epsilon) {
        double xm = (xl + xr) / 2;
        double fm = f(xm);

        if (fl * fm < 0) {
            xr = xm;
            fr = fm;
        } else {
            xl = xm;
            fl = fm;
        }
    }

    return (xl + xr) / 2;
}

int main() {
    double root;
    root = RootOfFunction(-1, 10, 0.1);
    printf("Root = %.1f\n", root);
    return 0;
}

