// lower triangular matrix addition in sequential
#include <stdio.h>
#include <time.h>

// Size of the matrices
#define N 4  

int main() {
    // Lower triangular matrices
    int A[N][N]; 
    int B[N][N];

    // Resultant matrix
    int C[N][N]; 

    struct timespec start_time, end_time;

    // Initialize matrices A and B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = i + j + 1;
            B[i][j] = i - j + 1;
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);

    printf("Resultant Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    double exec_time = (end_time.tv_sec - start_time.tv_sec) +
                     (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    
    printf("\nExecution time = %.9f seconds\n", exec_time);

    return 0;
}