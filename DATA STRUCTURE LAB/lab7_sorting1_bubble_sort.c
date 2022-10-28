#include <stdio.h>
int initialize(int a[])
{
    int size,i;
    printf("ENTER SIZE OF ARRAY:");
    scanf("%d",&size);
    printf("ENTER ARRAY ELEMENTS:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    return size;
}
void print(int a[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d  ",a[i]);
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int a[],int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
int main()
{
    int a[10],size,i;
    size=initialize(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    bubble_sort(a,size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}