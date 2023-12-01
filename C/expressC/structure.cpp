#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, num_sol, t0, t1;
    double sol0, sol1;
    
    // Assign values to a, b, and c
    a = 2;
    b = 4;
    c = 1;

    int disc = b * b - 4 * a * c;

    if (disc < 0) {
        num_sol = 0;
    } else {
        t0 = -b / (2 * a);
        if (disc == 0) {
            num_sol = 1;
            sol0 = t0;
        } else {
            num_sol = 2;
            t1 = sqrt(disc) / (2 * a);
            sol0 = (t0 + t1);
            sol1 = (t0 - t1);
        }
    }

    // The rest of your code (if needed)
    printf("# solns: %d", num_sol);
    printf("solns: %f, %f", sol0, sol1);

    return 0;
}
