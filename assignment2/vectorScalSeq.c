// vector scal Seq
#include <stdio.h>
#include <time.h>

int main(){
    int N = 99999;
    int A[N];
    struct timespec start_time, end_time;
    double exec_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);

    for(int i=0;i<N;i++){
        A[i] = i + 1;
    }

    int scalar = 2;

    for (int i = 0; i < N; i++){
        A[i] += scalar;
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time);
    exec_time = (end_time.tv_sec - start_time.tv_sec) +
                     (end_time.tv_nsec - start_time.tv_nsec) / 1e9;
    
    printf("\nExecution time = %.9f seconds\n", exec_time);

    return 0;
}