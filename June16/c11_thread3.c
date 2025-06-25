------------------------------------------------------------------

vi thread3.c

#include <stdio.h>
#include <pthread.h>

#define SIZE 6

int arr[SIZE] = {1, 2, 3, 4, 5, 6};
int sum1 = 0, sum2 = 0;

void* sum_first_half(void* arg) {
    for (int i = 0; i < SIZE / 2; i++) {
        sum1 += arr[i];
    }
    pthread_exit(NULL);
}

void* sum_second_half(void* arg) {
    for (int i = SIZE / 2; i < SIZE; i++) {
        sum2 += arr[i];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create threads
    pthread_create(&thread1, NULL, sum_first_half, NULL);
    pthread_create(&thread2, NULL, sum_second_half, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    int total_sum = sum1 + sum2;

    printf("Sum of first half: %d\n", sum1);
    printf("Sum of second half: %d\n", sum2);
    printf("Total sum: %d\n", total_sum);

    return 0;
}

gcc thread3.c -o thread3

./thread3


Output:-

[2021ict105@fedora ~]$ vi thread3.c
[2021ict105@fedora ~]$ gcc thread3.c -o thread3
[2021ict105@fedora ~]$ ./thread3
Sum of first half: 6
Sum of second half: 15
Total sum: 21



-----------------------------------------------------------------
