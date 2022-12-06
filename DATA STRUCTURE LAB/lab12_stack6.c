// use of Malloc function, implementing array using malloc, Input output using pointer and Function
#include <stdio.h>
#include <stdlib.h>
int input(int *a,int size)
{
    printf("\nENTER DATA FOR ARRAY:");
    for (int i=0;i<size;i++)
    {
        scanf("%d",a+i);    // a or (a+i)
        // a++;           // if a than a++
    }
    return 0;
}
int output(int *a,int size)
{
    printf("\nOUTPUT OF ARRAY:");
    for (int i=0;i<size;i++)
    {
        printf(" %d ",*(a+i));    // *a or *(a+i)
        // a++;                   // if *a than a++
    }
    printf("\n");
    return 0;
}
int main()
{
    int *a,size;
    printf("ENTER SIZE OF ARRAY:");
    scanf("%d",&size);
    a=(int *)malloc(sizeof(int)*size);
    input(a,size);
    output(a,size);
    return 0;
}