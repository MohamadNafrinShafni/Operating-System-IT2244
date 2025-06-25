------------------------------------------------

vi multiThreaded.c

#include <stdio.h>
#include <pthread.h>

// function to be executed by the thread
void * print_message(void* arg){
	char* message = (char*)arg;
	printf("%s\n", message);
	return NULL;
}


int main(){
	pthread_t  thread1,  thread2;
	
	// create the first thread 
	pthread_create(&thread1, NULL, print_message, "Hello from thread 1!");
	
	// create the second thread 
	pthread_create(&thread2, NULL, print_message, "Hello from thread 2!");
	
	// wait for both threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("Both threads completed.\n");
	return 0;
	
}


gcc multiThreaded.c -o multiThreaded

./multiThreaded


Output:-

[2021ict105@fedora ~]$ vi multiThreaded.c
[2021ict105@fedora ~]$ gcc multiThreaded.c -o multiThreaded
[2021ict105@fedora ~]$ ./multiThreaded
Hello from thread 1!
Hello from thread 2!
Both threads completed.



-----------------------------------------------------------------