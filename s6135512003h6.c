#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//6135512003;
void * sequence (void * argv);
int main(int argc, char const *argv[])
{
    int i,x;
    pthread_t tid;
    pthread_attr_t attr;

    if (argc != 2)
    {
        fprintf(stderr,"Usage: file <number>\n");
        return -1;
    }

    x = (3%5)+1; // number of thread
    printf("Hi this is the main thread.\n");

    pthread_attr_init(&attr);
    for (i=0;i<x;i++)
    {
        pthread_create(&tid,&attr,sequence,argv[1]); //create x thread
        pthread_join(tid,NULL);
    }
    printf("good bye.\n");
    return 0;
}

void * sequence (void * argv)
{
    int y = atoi(argv); // convert argument value index 1 is  integer value
    int i,S[y];
    S[0]=1;
    S[1]=1;
    S[2]=2;
    S[3]=2;
    printf("Hi : ");
    for (i=0;i<y;i++)
    {
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
        printf("%d ",S[i]); // print out the first y numbers

    }
    printf("\n");
    pthread_exit(0);
}
