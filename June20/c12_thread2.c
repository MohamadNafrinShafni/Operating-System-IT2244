Q2). Write a program to create 5 threads. Each thread should print its thread ID and then exit. The main thread should join all threads and print a completion message.

--------------------------------------------------------------

vi Q2.c

#include <stdio.h>
#include <pthread.h>

void* printThreadID(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, printThreadID, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Main thread: All threads have completed.\n");
    return 0;
}

gcc Q2.c -o Q2

./Q2

Output:-

[2021ict105@fedora ~]$ vi Q2.c
[2021ict105@fedora ~]$ gcc Q2.c -o Q2
[2021ict105@fedora ~]$ ./Q2
Thread ID: 140538280306240
Thread ID: 140538255128128
Thread ID: 140538175026752
Thread ID: 140538271913536
Thread ID: 140538263520832
Main thread: All threads have completed.


---------------------------------------------------------

