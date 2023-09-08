// fibonachi
#include <stdio.h>
#include <omp.h>

long long fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        long long x, y;
        #pragma omp task shared(x)
        x = fib(n - 1);

        #pragma omp task shared(y)
        y = fib(n - 2);

        #pragma omp taskwait
        return x + y;
    }
}

int main(){
    int n = 10; // Fibonacci number to compute
    long long result;
    double start_time, end_time;

    start_time = omp_get_wtime();

    #pragma omp parallel
    #pragma omp single
    {
        result = fib(n);
    }

    end_time = omp_get_wtime();
    double execution_time = end_time - start_time;

    printf("Fibonacci(%d) = %lld\n", n, result);
    printf("Execution time = %lf seconds", execution_time);

    return 0;
}