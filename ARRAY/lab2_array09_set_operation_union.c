
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

int union_program_my_approach(int a[],int b[],int size_a,int size_b,int work[])
{
    int i=0,j=0,index=0,num[100],new=1,value=1,ele;
    while (i<size_a)    work[index++]=a[i++];
    while (j<size_b)    work[index++]=b[j++];
    num[0]=work[0];
    for (i=1;i<size_a+size_b;i++)
    {
        ele=work[i];
        for (j=0;j<new;j++)
        {
            if (ele==num[j])
            {
                break;
            }
        }
        if (j==new)
        {
            num[value++]=ele;
            new++;
        }
    }
    for (i=0;i<new;i++)
    {
        work[i]=num[i];
    }
    return new;
}
int union_program(int a[],int b[],int size_a,int size_b,int work[])
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
            work[index++]=b[j++];
        }
        else 
        {
            work[index++]=a[i++];
            j++;
        }
    }
    while (i<size_a)    work[index++]=a[i++];
    while (j<size_b)    work[index++]=b[j++];

    return index;
}

int main()
{
    int a[100],b[100],size,work[100],size_a,size_b;

    //? SET UNION _my_approach
    /*
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    size=union_program_my_approach(a,b,size_a,size_b,work);
    print(work,size);
    */
    
    //?UNION PROGRAM:
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    size=union_program(a,b,size_a,size_b,work);
    print(work,size);

    return 0;

}