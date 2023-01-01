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

int difference_program(int a[],int b[],int size_a,int size_b,int work[])
{
    int i=0,j=0,index=0;
    while (i<size_a && j<size_b)
    {
        if (a[i]<b[j])
        {
            work[index++]=a[i++];
        }
        else if (a[i]>b[j])
        {
            j++;
        }
        else 
        {
            i++;
            j++;
        }
    }
    while (i<size_a)    work[index++]=a[i++];

    return index;
}


int main()
{
    int a[100],b[100],size,work[100],size_a,size_b;

    //?DIFFERENCE PROGRAM
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    //merge_sort(a,0,size_a,work);
    //merge_sort(b,0,size_b,work);
    size=difference_program(a,b,size_a,size_b,work);
    print(work,size); 

    return 0;

}