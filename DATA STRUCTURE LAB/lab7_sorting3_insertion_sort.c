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
void insertion_sort(int a[],int size)
{
    int i,j,index=0,element;
    for(i=0;i<size;i++)
    {
        element=a[i];
        for(j=i-1;j>=0;j--)
        {
            if (a[j]>element)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=element;
    }
}
int main()
{
    int a[10],size;
    size=initialize(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    insertion_sort(a,size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}