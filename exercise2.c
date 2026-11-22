
#include <stdio.h>
#include <pthread.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

typedef struct {
    int start;
    int end;
    int id;
    int sum;
} ThreadData;

void* calculate_sum(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    data->sum = 0;

    for (int i = data->start; i < data->end; i++) {
        data->sum += arr[i];
    }

    printf("Thread %d: Partial sum = %d\n",
           data->id, data->sum);

    return NULL;
}

int main(void) {
    pthread_t threads[2];

    ThreadData data[2] = {
        {0, 4, 1, 0},
        {4, 8, 2, 0}
    };

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, calculate_sum, &data[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total sum = %d\n", data[0].sum + data[1].sum);

    return 0;
}

