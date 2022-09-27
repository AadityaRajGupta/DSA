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

int intersection_program_my_approach(int a[],int b[],int size_a,int size_b,int work[])
{
    int i=0,j=0,index=0,num[100],ele,new=1,value=0;

    num[0]=a[0];
    for (i=1;i<size_a;i++)
    {
        ele=a[i];
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
        a[i]=num[i];
    }
    size_a=new;
    for (i=0;i<size_a;i++)
    {
        for(j=0;j<size_b;j++)
        {
            if (a[i]==b[j])
            {
                work[index++]=a[i];
            }
        }
    }
    return index;
}
int intersection_program(int a[],int b[],int size_a,int size_b,int work[])
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
            i++;
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

    //? SET INTERSECTION _my_approach
    /*
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    size=intersection_program_my_approach(a,b,size_a,size_b,work);
    print(work,size);
    */
   
    //?INTERSECTION PROGRAM
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    size=intersection_program(a,b,size_a,size_b,work);
    print(work,size);

    return 0;

}