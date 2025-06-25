Q1). Write a C program that creates two threads. Each thread should print a message indicating it is running. The main threat should wait for both threads to finish before exiting.

------------------------------------------------------------------------

vi Q1.c

#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg) {
	int threadName = *(int*)arg;
    printf("Thread %d is running.\n", threadName);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_create(&t1, NULL, threadFunc, &id1);
    pthread_create(&t2, NULL, threadFunc, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread: Both threads have finished.\n");
    return 0;
}

gcc Q1.c -o Q1

./Q1


Output:-

[2021ict105@fedora ~]$ vi Q1.c
[2021ict105@fedora ~]$ gcc Q1.c -o Q1
[2021ict105@fedora ~]$ ./Q1
Thread 1 is running.
Thread 2 is running.
Main thread: Both threads have finished.



-----------------------------------------------------------------

