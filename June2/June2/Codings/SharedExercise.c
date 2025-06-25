parent process read input n and r  to calculate ncr and npr using fork and shared memory and child process calculate the factorial of it as output

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct {
    int n, r;
    unsigned long long fact_n;
    unsigned long long fact_r;
    unsigned long long fact_n_r;
} shared_data_t;

unsigned long long factorial(int x) {
    unsigned long long f = 1;
    for (int i = 2; i <= x; i++) {
        f *= i;
    }
    return f;
}

int main() {
    int n, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%d", &r);

    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, sizeof(shared_data_t), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    shared_data_t *data = (shared_data_t *) shmat(shmid, NULL, 0);
    if (data == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    data->n = n;
    data->r = r;

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process: calculate factorials
        data->fact_n = factorial(data->n);
        data->fact_r = factorial(data->r);
        data->fact_n_r = factorial(data->n - data->r);
        shmdt(data);
        exit(0);
    }
    else {
        // Parent process: wait for child to finish
        wait(NULL);

        unsigned long long nCr = data->fact_n / (data->fact_r * data->fact_n_r);
        unsigned long long nPr = data->fact_n / data->fact_n_r;

        printf("nCr = %llu\n", nCr);
        printf("nPr = %llu\n", nPr);

        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
