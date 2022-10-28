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
void selection_sort(int a[],int size)
{
    int i,j,min_index;
    for(i=0;i<size;i++)
    {
        min_index=i;
        for(j=i+1;j<size;j++)
        {
            if (a[j]<a[min_index])
            {
                min_index=j;
            }
        }
        swap(&a[i],&a[min_index]);
    }
}
int main()
{
    int a[10],size;
    size=initialize(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    selection_sort(a,size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}