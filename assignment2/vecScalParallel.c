// vec scal parallel
#include <omp.h>
#include <stdio.h>

int main(){
    int N = 99999;
    int A[N];
    double start_time, end_time, exec_time;

    for(int i=0;i<N;i++){
        A[i] = i + 1;
    }

    int scalar = 2;

    // Set threads
    // omp_set_num_threads();

    start_time = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++){
        A[i] += scalar;
    }

    end_time = omp_get_wtime();
    exec_time = end_time - start_time;
   
    printf("\nExecution time = %f seconds\n", exec_time);

    return 0;
}