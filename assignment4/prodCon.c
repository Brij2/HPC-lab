#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer
int in = 0;    // Index for adding items to the buffer
int out = 0;   // Index for removing items from the buffer

void producer() {
    // Produce 20 items
    for (int i = 0; i < 20; i++) { 
        while (count == BUFFER_SIZE) {
            #pragma omp flush(count)
        }

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;

        #pragma omp atomic
        count++;

        printf("Produced: %d\n", i+1);
    }
}

void consumer() {
    // Consume 20 items
    for (int i = 0; i < 20; i++) {
        while (count == 0) {
            #pragma omp flush(count)
        }

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        #pragma omp atomic
        count--;

        printf("Consumed: %d\n", item+1);
    }
}

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            producer();
        }

        #pragma omp section
        {
            consumer();
        }
    }

    return 0;
}