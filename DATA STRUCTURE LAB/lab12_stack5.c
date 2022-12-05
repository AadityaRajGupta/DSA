//Understanding of single pointer and taking array as input and Output using pointer and Function
#include <stdio.h>

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
    int a[10],size;
    printf("ENTER SIZE OF ARRAY:");
    scanf("%d",&size);
    input(a,size);
    output(a,size);
    return 0;
}