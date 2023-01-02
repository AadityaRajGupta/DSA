#include <stdio.h>
/*
Time Complexity: O(log n)
Auxiliary Space: O(log n)
*/
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

int binary_searching(int a[],int key,int start,int end)
{
    int mid=(start+end)/2;
    if (end-start>=1)
    {
        if (a[mid]==key)
        {
            return mid;
        }
        else if (a[mid]>key)
        {
            binary_searching(a,key,start,mid-1);
        }
        else
        {
            binary_searching(a,key,mid+1,end);
        }
    }
    else
    {
        return -1;
    }
}




int main()
{
    int a[5],size,c;
    size=initialization(a);
    print(a,size);

    c=binary_searching(a,5,0,size);
    printf("%d",c);
    return 0;
}