#include <stdio.h>
int dat[100];
int initialization(int a[])
{
    int size;
    printf("\nENTER THE SIZE OF ARRAY:");
    scanf("%d", &size);
    printf("ENTER ELEMENTS:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    return size;
}
void print(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

int max(int a[],int size)
{
    int i,max=0;
    for(i=0;i<size;i++)
    {
        if (a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
void counting_sort(int a[],int size)
{
    int i,work[100];
    int m=max(a,size);
    for(i=0;i<size;i++)
    {
        dat[a[i]]++;
    }
    for(i=1;i<=m;i++)
    {
        dat[i]+=dat[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        work[dat[a[i]]-1]=a[i];
        dat[a[i]]--;
    }
    for(i=0;i<size;i++)
    {
        a[i]=work[i];
    }
}
#include <stdio.h>
int main()
{
    int a[100],size;
    size=initialization(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    counting_sort(a,size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}