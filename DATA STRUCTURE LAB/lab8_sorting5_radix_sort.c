#include <stdio.h>
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
void counting_sort_for_radix(int a[],int size,int exp)
{
    int i,work[100];
    int count[10]={0};  //har baar call hone pe naya khali array chahiye 
    for(i=0;i<size;i++)
    {
        count[(a[i]/exp) % 10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        work[count[(a[i]/exp) % 10]-1]=a[i];
        count[(a[i]/exp) % 10]--;
    }
    for(i=0;i<size;i++)
    {
        a[i]=work[i];
    }

}
void radix_sort(int a[],int size)
{
    int exp;
    int m=max(a,size);
    for(exp=1;m/exp>0;exp*=10)
    {
        counting_sort_for_radix(a,size,exp);
    }
}

int main()
{
    int a[100],size;
    size=initialization(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    radix_sort(a,size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}