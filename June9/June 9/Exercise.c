get user input in c using pipe as child
Area calculationprogram
Circle -c
Triangle - Triangle
Square - S
Rectangle - R

output like this
Enter your choice:C

Circle area Calculation
Enter the radius:20.9
Area is :1371.58
*******************************Answer***********************************

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child: get user input and write to pipe
        close(pipefd[0]); // Close read end

        char choice;
        float dim1, dim2;

        printf("Area calculation program\n");
        printf("Circle - C\nTriangle - T\nSquare - S\nRectangle - R\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        write(pipefd[1], &choice, sizeof(choice));

        switch(choice) {
            case 'C':
                printf("\nCircle area Calculation\nEnter the radius:");
                scanf("%f", &dim1);
                write(pipefd[1], &dim1, sizeof(dim1));
                break;
            case 'T':
                printf("\nTriangle area Calculation\nEnter the base:");
                scanf("%f", &dim1);
                printf("Enter the height:");
                scanf("%f", &dim2);
                write(pipefd[1], &dim1, sizeof(dim1));
                write(pipefd[1], &dim2, sizeof(dim2));
                break;
            case 'S':
                printf("\nSquare area Calculation\nEnter the side length:");
                scanf("%f", &dim1);
                write(pipefd[1], &dim1, sizeof(dim1));
                break;
            case 'R':
                printf("\nRectangle area Calculation\nEnter the length:");
                scanf("%f", &dim1);
                printf("Enter the width:");
                scanf("%f", &dim2);
                write(pipefd[1], &dim1, sizeof(dim1));
                write(pipefd[1], &dim2, sizeof(dim2));
                break;
            default:
                // Send invalid choice
                choice = 'X';
                write(pipefd[1], &choice, sizeof(choice));
                break;
        }

        close(pipefd[1]);
        exit(EXIT_SUCCESS);

    } else {
        // Parent: read data from pipe, calculate and print area
        close(pipefd[1]); // Close write end

        char choice;
        read(pipefd[0], &choice, sizeof(choice));

        if (choice == 'X') {
            printf("Invalid choice!\n");
            close(pipefd[0]);
            wait(NULL);
            exit(EXIT_FAILURE);
        }

        float dim1, dim2, area = 0.0;

        switch(choice) {
            case 'C':
                read(pipefd[0], &dim1, sizeof(dim1));
                area = 3.1416 * dim1 * dim1;
                break;
            case 'T':
                read(pipefd[0], &dim1, sizeof(dim1));
                read(pipefd[0], &dim2, sizeof(dim2));
                area = 0.5 * dim1 * dim2;
                break;
            case 'S':
                read(pipefd[0], &dim1, sizeof(dim1));
                area = dim1 * dim1;
                break;
            case 'R':
                read(pipefd[0], &dim1, sizeof(dim1));
                read(pipefd[0], &dim2, sizeof(dim2));
                area = dim1 * dim2;
                break;
        }

        if (area > 0)
            printf("Area is :%.2f\n", area);

        close(pipefd[0]);
        wait(NULL);
    }

    return 0;
}
