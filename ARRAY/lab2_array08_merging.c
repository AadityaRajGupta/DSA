
#include <stdio.h>

void print(int a[],int size)
{
    printf("\nARRAY ELEMENT:\n");
    for(int i=0;i<size;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
}
int initialization(int a[])
{
    int size;
    printf("\nENTER THE SIZE OF ARRAY:");
    scanf("%d",&size);
    printf("ENTER ELEMENTS:\n");
    for (int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    return size;
}

int merging_sorted_array(int a[],int b[],int size_a,int size_b,int work[])
{
    int i=0,j=0,index=0;
    while (i<size_a && j<size_b)
    {
        if (a[i]<=b[j])
        {
            work[index++]=a[i++];
        }
        else if (a[i]>a[j])
        {
            work[index++]=b[j++];
        }
    }
    while (i<size_a)    work[index++]=a[i++];
    while (j<size_b)    work[index++]=b[j++];

    return 0;
}


int main()
{
    int a[100],b[100],size,work[100],size_a,size_b;

    //? merging two sorted arrays
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    merging_sorted_array(a,b,size_a,size_b,work);
    print(work,size_a+size_b);
    

    return 0;

}