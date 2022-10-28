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

void shell_sort(int a[],int size)
{
    int box,i,j,temp;
    for(box=size/2;box>0;box/=2)
    {
        for(i=box;i<size;i++)
        {
            temp=a[i];
            for(j=i;j>=box && a[j-box]>temp;j -= box)
            {
                a[j]=a[j-box];
            }
            a[j]=temp;
        }
    }
}
int main()
{
    int a[10],size,i;
    size=initialize(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    shell_sort(a,size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}