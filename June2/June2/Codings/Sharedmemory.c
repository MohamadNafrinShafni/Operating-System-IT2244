#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    char *shmaddr = (char *) shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    const char *message = "Hello from writer!";
    strncpy(shmaddr, message, SHM_SIZE);

    printf("Data written to memory: %s\n", message);

    shmdt(shmaddr);

    return 0;
}



//reader(p2)
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *name = "/my_shared_mem";
    const int SIZE = 4096;

    int shm_fd = shm_open(name, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    void *ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    printf("Reader read: %s\n", (char *)ptr);

    munmap(ptr, SIZE);
    close(shm_fd);

    return 0;
}


//Run and Compile
gcc writer.c -o writer -lrt
gcc reader.c -o reader -lrt


