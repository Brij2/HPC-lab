// sum lower triangular matrices in parallel
#include <stdio.h>
#include <omp.h>

// Size of the matrices
#define N 4  

int main() {
    // Lower triangular matrices
    int A[N][N]; 
    int B[N][N];

    // Resultant matrix
    int C[N][N]; 

    double start_time, end_time;

    // Initialize matrices A and B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = i + j + 1;
            B[i][j] = i - j + 1;
        }
    }

    omp_set_num_threads(8);

    start_time = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    end_time = omp_get_wtime();

    printf("Resultant Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    double exec_time = end_time - start_time;

    printf("Execution time = %lf seconds", exec_time);

    return 0;
}