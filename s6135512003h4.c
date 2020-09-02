#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void sequence(int n);
int main(int argc, char  *argv[])
{
    int i,x,number;
    number = atoi(argv[1]); // argument value index 1
    x = (3%5)+1; // number of child process
    pid_t pid;
    printf("Parent: my pid = %d, my parent pid = %d\n",getpid(),getppid());
    for(i=0;i<x;i++)
    {   pid = fork(); // create child process
        if (pid<0)
        {
          fprintf(stderr,"Fork Failed");
          exit(-1);
        }
        else if (pid==0)
        {
          printf("Child: my  pid = %d : ",getpid());
          sequence(number); // call sequence function
          printf("\n");
          exit(0);
        }
        else
        {
          wait(NULL);
        }

    }
    printf("Good bye.\n");
    exit(0);
}

//sequence function
void sequence (int n)
{
    int i,S[n];
    for (i=0;i<n;i++)
    {
        S[0]=1;
        S[1]=1;
        S[2]=2;
        S[3]=2;
        if (i>3)
        {
            if (i%3==0)
            {
                S[i]=S[i-1];
            }
            else
            {
                S[i]=S[i-2]+S[i-2]-1;
            }
        }
        printf("%d ",S[i]);

    }
}

