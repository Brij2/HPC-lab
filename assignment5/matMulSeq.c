// matrix mul sequential
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS_A 8
#define COLS_A 8
#define ROWS_B 8
#define COLS_B 8

int main() {
    srand(time(NULL));

    struct timespec start_time, end_time;

    int A[ROWS_A][COLS_A];
    int B[ROWS_B][COLS_B];
    int C[ROWS_A][COLS_B];

    // Initialize matrices A and B with random values
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            // Random values between 0 and 99
            A[i][j] = rand() % 100; 
        }
    }

    for (int i = 0; i < ROWS_B; i++) {
        for (int j = 0; j < COLS_B; j++) {
            // Random values between 0 and 99
            B[i][j] = rand() % 100; 
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Perform matrix multiplication
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            C[i][j] = 0;
            for (int k = 0; k < COLS_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Print the result matrix C
    printf("Matrix A:\n");
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < ROWS_B; i++) {
        for (int j = 0; j < COLS_B; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nResultant Matrix C:\n");
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    double exec_time = (end_time.tv_sec - start_time.tv_sec) +
                     (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    
    printf("\nExecution time = %.9f seconds\n", exec_time);

    return 0;
}