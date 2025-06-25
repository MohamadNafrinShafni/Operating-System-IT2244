Q5). Implement a thread function that takes an integer argument, squares it, and returns the result to the main thread using pthread_exit and pthread_join

---------------------------------------------------------------

vi Q5.c

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    return result;
}

int main() {
    pthread_t t;
    int num = 6;

    pthread_create(&t, NULL, square, &num);

    void* res;
    pthread_join(t, &res);

    int* squareResult = (int*)res;
    printf("Square of %d is %d\n", num, *squareResult);
    free(res);

    return 0;
}

gcc Q5.c -o Q5

./Q5

Outputs:-

[2021ict105@fedora ~]$ vi Q5.c
[2021ict105@fedora ~]$ gcc Q5.c -o Q5
[2021ict105@fedora ~]$ ./Q5
Square of 6 is 36

-------------------------------------------------------------