------------------------------------------------------------------------

vi thread1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// A normal C function that is execured as a thread// when its name is specified in pthread_create()

void *helloWorld(void *vargp)
{
	sleep(1);
	printf("Hello World\n");
	return NULL;
}

int main(){
	pthread_t  thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, helloWorld, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}


gcc thread1.c -o thread1

./thread1


Output:-

[2021ict105@fedora ~]$ gcc thread1.c -o thread1
[2021ict105@fedora ~]$ ./thread1
Before Thread
Hello World
After Thread


-----------------------------------------------------------------