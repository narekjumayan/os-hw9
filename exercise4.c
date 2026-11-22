
#include <stdio.h>
#include <pthread.h>

void* calculate_square(void* arg) {
    int number = *(int*)arg;

    printf("Square of %d is %d\n", number, number * number);

    return NULL;
}

int main(void) {
    pthread_t threads[5];
    int numbers[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL,
                       calculate_square, &numbers[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

