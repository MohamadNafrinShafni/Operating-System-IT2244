---------------------------------------------------------------------------------------

vi pipe3.c


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>


#define MSGSIZE 100

int main() {
    int to_child[2], to_parent[2];
    pid_t pid;
    char shape[MSGSIZE], input1[MSGSIZE], input2[MSGSIZE], result[MSGSIZE];

    if (pipe(to_child) < 0 || pipe(to_parent) < 0) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        // Parent Process
        close(to_child[0]); // close read end
        close(to_parent[1]); // close write end

        printf("Enter shape (circle/triangle/rectangle/square): ");
        fgets(shape, MSGSIZE, stdin);
        shape[strcspn(shape, "\n")] = 0;

        // Get relevant inputs based on shape
        if (strcmp(shape, "circle") == 0) {
            printf("Enter radius: ");
            fgets(input1, MSGSIZE, stdin);
            input2[0] = '\0';
        } else if (strcmp(shape, "triangle") == 0 || strcmp(shape, "rectangle") == 0) {
            printf("Enter base/length: ");
            fgets(input1, MSGSIZE, stdin);
            printf("Enter height/width: ");
            fgets(input2, MSGSIZE, stdin);
        } else if (strcmp(shape, "square") == 0) {
            printf("Enter side: ");
            fgets(input1, MSGSIZE, stdin);
            input2[0] = '\0';
        } else {
            printf("Unsupported shape.\n");
            exit(1);
        }

        // Send data to child
        write(to_child[1], shape, MSGSIZE);
        write(to_child[1], input1, MSGSIZE);
        write(to_child[1], input2, MSGSIZE);
        close(to_child[1]);

        // Read result from child
        read(to_parent[0], result, MSGSIZE);
        printf("Calculated Area: %s\n", result);
        close(to_parent[0]);

        wait(NULL); // wait for child
    } else {
        // Child Process
        close(to_child[1]); // close write end
        close(to_parent[0]); // close read end

        char shape[MSGSIZE], in1[MSGSIZE], in2[MSGSIZE];
        float area = 0;

        read(to_child[0], shape, MSGSIZE);
        read(to_child[0], in1, MSGSIZE);
        read(to_child[0], in2, MSGSIZE);

        float val1 = atof(in1);
        float val2 = atof(in2);

        if (strcmp(shape, "circle") == 0) {
            area = 3.1416 * val1 * val1;
        } else if (strcmp(shape, "triangle") == 0) {
            area = 0.5 * val1 * val2;
        } else if (strcmp(shape, "rectangle") == 0) {
            area = val1 * val2;
        } else if (strcmp(shape, "square") == 0) {
            area = val1 * val1;
        }

        snprintf(result, MSGSIZE, "%.2f", area);
        write(to_parent[1], result, MSGSIZE);

        close(to_child[0]);
        close(to_parent[1]);
    }

    return 0;
}


gcc pipe3.c -o pipe3

./pipe3


Output:-

Enter shape (circle/triangle/rectangle/square): circle
Enter radius: 5
Calculated Area: 78.54

or

Enter shape (circle/triangle/rectangle/square): triangle
Enter base/length: 10
Enter height/width: 8
Calculated Area: 40.00

or

Enter shape (circle/triangle/rectangle/square): rectangle
Enter base/length: 6
Enter height/width: 4
Calculated Area: 24.00

or

Enter shape (circle/triangle/rectangle/square): square
Enter side: 7
Calculated Area: 49.00

or

Enter shape (circle/triangle/rectangle/square): hexagon
Unsupported shape.