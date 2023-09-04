#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void matrix_addition(int** A, int** B, int** C, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int matrix_sizes[] = {250, 500, 750, 1000, 2000};
    int num_sizes = sizeof(matrix_sizes) / sizeof(matrix_sizes[0]);
    double start_time, end_time;

    for (int k = 0; k < num_sizes; k++) {
        int size = matrix_sizes[k];

        int** A = (int**)malloc(size * sizeof(int*));
        int** B = (int**)malloc(size * sizeof(int*));
        int** C = (int**)malloc(size * sizeof(int*));

        for (int i = 0; i < size; i++) {
            A[i] = (int*)malloc(size * sizeof(int));
            B[i] = (int*)malloc(size * sizeof(int));
            C[i] = (int*)malloc(size * sizeof(int));

            for (int j = 0; j < size; j++) {
                A[i][j] = rand() % 100;
                B[i][j] = rand() % 100;
            }
        }

        printf("\nMatrix size: %d\n", size);

        for (int num_threads = 2; num_threads <= 8; num_threads *= 2) {
            omp_set_num_threads(num_threads);

            start_time = omp_get_wtime();

            matrix_addition(A, B, C, size);

            end_time = omp_get_wtime();
            double execution_time = end_time - start_time;

            printf("Threads: %d, Execution Time = %lf seconds\n", num_threads, execution_time);
        }

        for (int i = 0; i < size; i++) {
            free(A[i]);
            free(B[i]);
            free(C[i]);
        }

        free(A);
        free(B);
        free(C);
    }

    return 0;
}