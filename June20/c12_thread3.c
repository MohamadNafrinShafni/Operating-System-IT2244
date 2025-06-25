Q3). Write a program that creates a thread which prints numbers from 1 to 10 with  1-SECOND delay between each number.The main thread should wait for this thread to finish.

---------------------------------------------------------------

vi Q3.c

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* printNumbers(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);  // 1-second delay
    }
    return NULL;
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, printNumbers, NULL);
    pthread_join(t, NULL);

    printf("Main thread: Counting thread finished.\n");
    return 0;
}

gcc Q3.c -o Q3

./Q3


Outputs:-

[2021ict105@fedora ~]$ vi Q3.c
[2021ict105@fedora ~]$ gcc Q3.c -o Q3
[2021ict105@fedora ~]$ ./Q3
1
2
3
4
5
6
7
8
9
10
Main thread: Counting thread finished.


----------------------------------------------------------------
