#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define RANDOM_POINTS 1000000

int main() {
    srand(time(NULL));

    double x, y, start_time, end_time;

    int inside_circle = 0;

    // Set threads
    omp_set_num_threads(8);

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:inside_circle)
    for (int i = 0; i < RANDOM_POINTS; i++) {
        double x = ((double) rand() / RAND_MAX) * 2 - 1;
        double y = ((double) rand() / RAND_MAX) * 2 - 1;

        if (x*x + y*y <= 1) {
            inside_circle++;
        }
    }

    double pi = ((double) inside_circle / RANDOM_POINTS) * 4;

    end_time = omp_get_wtime();

    printf("Estimated PI value = %lf\n", pi);

    double execution_time = end_time - start_time;
    printf("Execution time = %lf seconds\n", execution_time);

    return 0;
}