01.
#include <stdio.h>
#include <unistd.h>
int main(){
    printf("\nHello world!");

    int f = fork(); // copy everything
    int p = getpid();

    /*printf("\nthe pid is %d", p);
    printf("\nthe fork is %d\n", f);*/

    if(f == 0){
        printf("I'm child process");
        printf("\nthe pid is %d", p);
        printf("\nthe fork is %d\n", f);

    }else{
        printf("I'm parent process");
        printf("\nthe pid is %d", p);
        printf("\nthe fork is %d\n", f);
    }

    return 0;
}

.....................................
02.
#include <stdio.h>
#include <unistd.h>
int main(){
    
    int f = fork();
   

    if(f == 0){
        printf("\nI'm B\n");
        printf("\nMy parent id:%d", getppid());
    }else{
        int f1 = fork();
        if(f1 == 0){
            printf("\nI'm C\n");
            printf("\nMy parent id:%d", getppid());
        }else{
            printf("\nI'm A");
            printf("\nMy id:%d\n", getpid());
        }
    }


    return 0;
}

......................................

