------------------------------------------------------------------------------------

vi pipe1.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16

char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], i;
	
	if(pipe(p) < 0)
		exit(1);
	
	/* continued */
	/* write pipe */
	
	write(p[1], msg1, MSGSIZE);    // write(fildes, message, message_size)
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);
	
	for (i=0; i<3; i++){
		// read pipe
		read(p[0], inbuf, MSGSIZE);    // read(fildes, message, message_size)
		printf("%s\n", inbuf);
	}
	
	return 0;
}

gcc pipe1.c -o pipe1

./pipe1


Output:-

hello, world #1
hello, world #2
hello, world #3



--------------------------------------------------------------------------------


