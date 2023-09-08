// static_dynamic_nowait.c
#include <stdio.h>
#include <omp.h>

#define VECTOR_SIZE 200

int main() {
    int vector[VECTOR_SIZE];
    int scalar = 2;
    int result[VECTOR_SIZE];

    // Initialize the vector
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector[i] = i + 1;
    }

    printf("Vector Scalar Addition\n");

    // Experiment with different chunk sizes and scheduling strategies
    for (int chunk_size = 1; chunk_size <= VECTOR_SIZE; chunk_size *= 2) {
        printf("Chunk Size: %d\n", chunk_size);

        // STATIC Schedule
        double static_start_time = omp_get_wtime();
        #pragma omp parallel for schedule(static, chunk_size)
        for (int i = 0; i < VECTOR_SIZE; i++) {
            result[i] = vector[i] + scalar;
        }
        double static_end_time = omp_get_wtime();
        double static_execution_time = static_end_time - static_start_time;

        // DYNAMIC Schedule
        double dynamic_start_time = omp_get_wtime();
        #pragma omp parallel for schedule(dynamic, chunk_size)
        for (int i = 0; i < VECTOR_SIZE; i++) {
            result[i] = vector[i] + scalar;
        }
        double dynamic_end_time = omp_get_wtime();
        double dynamic_execution_time = dynamic_end_time - dynamic_start_time;

        printf("Static Execution Time: %lf seconds\n", static_execution_time);
        printf("Dynamic Execution Time: %lf seconds\n", dynamic_execution_time);

        // Demonstrate the use of nowait clause outside the parallel region
        double nowait_start_time = omp_get_wtime();
        #pragma omp parallel for schedule(static, chunk_size)
        for (int i = 0; i < VECTOR_SIZE; i++) {
            result[i] = vector[i] + scalar;
        }
        #pragma omp for schedule(static, chunk_size) nowait
        for (int i = 0; i < VECTOR_SIZE; i++) {
            result[i] = result[i] * 2; // Example additional computation
        }
        double nowait_end_time = omp_get_wtime();
        double nowait_execution_time = nowait_end_time - nowait_start_time;

        printf("Nowait Execution Time: %lf seconds\n", nowait_execution_time);

        printf("\n");
    }

    return 0;
}
