#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define VECTOR_SIZE 100000

int main() {
    srand(time(NULL));

    int vector1[VECTOR_SIZE];
    int vector2[VECTOR_SIZE];

    long long scalar_product = 0;

    double start_time, end_time;

    // Initialize the vectors with random values
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector1[i] = rand()%100;
        vector2[i] = rand()%100;
    }


    // Set threads
    omp_set_num_threads(2);

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:scalar_product)
    for (int i = 0; i < VECTOR_SIZE; i++) {
        scalar_product += vector1[i] * vector2[i];
    }

    end_time = omp_get_wtime();
    double execution_time = end_time - start_time;

    printf("Scalar Product = %lld\n", scalar_product);
    printf("Execution Time = %lf seconds", execution_time);

    return 0;
}