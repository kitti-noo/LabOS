#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char  *argv[])
{
    int temp=10;
    pid_t pid;

    pid = fork();
    if (pid<0)
    {
        fprintf(stderr,"Fork Failed");
        exit(-1);
    }
    else if (pid==0)
    {
         printf("This is a child process. pid = %d, parent pid = %d\n",getpid(),getppid());
         sleep(2);
         printf("This is a child process. I woke up! \n");
//       execlp("/bin/ls","ls",NULL);
        while (temp<13)
                temp ++;

         printf("CHILLD: temp = %d\n",temp);
    }
    else
    {
         printf("This is a parent process. pid = %d, child pid = %d\n",getpid(),pid);
         wait(NULL);
         printf("PARENT: Child Complete.\n");
         printf("PARENT: temp = %d\n",temp);
         exit(0);
    }

}

