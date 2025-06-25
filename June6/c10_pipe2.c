------------------------------------------------------------------------------

/*

Exercise 

1.read three input from user(//parent process)
name:
reg no:
age:

2.print the output from the child(// child process)
name:abc
regno: 2022/ict/01
age: 25

*/


vi pipe2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MSGSIZE 100

int main() {
    char name[MSGSIZE], regno[MSGSIZE], age[MSGSIZE];
    int p[2];
    pid_t pid;

    if (pipe(p) < 0) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        // Parent process: get input and write to pipe
        close(p[0]); // Close read end

		
        printf("Enter name: ");
        fgets(name, MSGSIZE, stdin);
        name[strcspn(name, "\n")] = 0; // remove newline

        printf("Enter reg no: ");
        fgets(regno, MSGSIZE, stdin);
        regno[strcspn(regno, "\n")] = 0;

        printf("Enter age: ");
        fgets(age, MSGSIZE, stdin);
        age[strcspn(age, "\n")] = 0;

        write(p[1], name, MSGSIZE);
        write(p[1], regno, MSGSIZE);
        write(p[1], age, MSGSIZE);

        close(p[1]); // Close write end after writing
        wait(NULL); // Wait for child to complete
    } else {
        // Child process: read from pipe and print
		
        char inbuf[MSGSIZE];

        close(p[1]); // Close write end

        read(p[0], inbuf, MSGSIZE);
        printf("name: %s\n", inbuf);

        read(p[0], inbuf, MSGSIZE);
        printf("regno: %s\n", inbuf);

        read(p[0], inbuf, MSGSIZE);
        printf("age: %s\n", inbuf);

        close(p[0]); // Close read end
    }

    return 0;
}

gcc pipe2.c -o pipe2

./pipe2


Output:-

Enter name: Manimegalai
Enter reg no: 2021/ICT/105
Enter age: 24
name: Manimegalai
regno: 2021/ICT/105
age: 24



--------------------------------------------------------------------------------