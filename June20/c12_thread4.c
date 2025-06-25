Q4). Create two threads where one thread increments a global counter 1 times and the final value of the counter after both threads finish.

-------------------------------------------------------------

vi  Q4.c

#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final value of counter: %d\n", counter);
    pthread_mutex_destroy(&lock);
    return 0;
}

gcc Q4.c -o Q4

./Q4

Outputs:-

[2021ict105@fedora ~]$ vi  Q4.c
[2021ict105@fedora ~]$ gcc Q4.c -o Q4
[2021ict105@fedora ~]$ ./Q4
Final value of counter: 0


----------------------------------------------------------------
