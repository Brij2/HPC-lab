// pii seq
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_POINTS 1000000

int main() {
    // Random number generator
    srand(time(NULL));

    clock_t start_time, end_time;
    double x, y;

    start_time = clock();

    int inside_circle = 0;

    for (int i = 0; i < RANDOM_POINTS; i++) {
        // Generate random coord b/w 1 & -1
        x = ((double) rand() / RAND_MAX) * 2 - 1;
        y = ((double) rand() / RAND_MAX) * 2 - 1;

        // Check if point is inside circle
        if (x*x + y*y <= 1) {
            inside_circle++;
        }
    }

    double pi = ((double) inside_circle / RANDOM_POINTS) * 4;

    end_time = clock();

    printf("Estimated PI value = %lf\n", pi);

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution = %lf seconds\n", execution_time);

    return 0;
}