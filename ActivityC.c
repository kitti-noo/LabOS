#include<stdio.h>
void Bubble(void);
int main()
{
    int selection;

    printf("Please select one of these options\n\n");
    printf("1) bubble sort\n");
    printf("2) Quit\n");
    scanf("%d",&selection);

    switch (selection)
    {
    case 1 : Bubble(); break;
    case 2 : break;
    default: printf("Unknow option\n"); break;
    }
    printf("\n...Bye...\n");
    return(0);
}

void Bubble(void)
{
    int input[5];
    int temp,i,j;

    for(i=0;i<5;i++)
    {
        printf("Please enter #%d: ",i+1);
        scanf("%d",&input[i]);
    }
    for ( i = 0; i < 4; i++)
    {
        for ( j = i; j < 5; j++)
        {
            if(input[j]<input[i])
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp; 
            }
            
        }
        
    }
    printf("The sorted list is: ");
    for ( i = 0; i < 5; i++)
    {
        printf("%d ",input[i]);
    }
    printf("\n");
    
}