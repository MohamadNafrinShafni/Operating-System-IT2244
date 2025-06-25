------------------------------------------------

vi thread2.c

#include <stdio.h>
#include <pthread.h>

// function to be executed by the thread
void* print_message(void* arg){
	char* messages = (char*)arg;
	printf("%s\n", message);
	return NULL;
}


int main(){
	pthread_t  threads[3];
	
	char* messages[] = {
		"Thread 1 says hi!",
		"Thread 2 says hello!",
		"Thread 3 says hey!"
	};
	
	for (int i=0; i<3; i++){
		pthread_create(&threads[i], NULL, print_message, messages[i]);
	}
	
	for (int i=0; i<3; i++){
		pthread_join(threads[i], NULL);
	}
	
	printf("All threads done.\n");
	return 0;
	
}


gcc thread2.c -o thread2

./thread2


Output:-




-----------------------------------------------------------------