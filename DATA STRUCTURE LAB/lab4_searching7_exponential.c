#include <stdio.h>
#include <math.h>
void print(int a[], int size)
{
    printf("\nARRAY ELEMENT:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}
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
int binary_search(int a[],int start,int end,int key)
{
    if (start<=end)
    {
        int mid=(start+end)/2;
        if (a[mid]==key)
        {
            return mid;
        }
        else if (a[mid]>key)
        {
            return binary_search(a,start,mid-1,key);
        }
        else 
        {
            return binary_search(a,mid+1,end,key);
        }
    }
    return -1;
}
int exponential_searching(int a[], int size, int key)
{
    if (a[0] == key)
        return 0;

    int i = 1;
    while (i < size && a[i] <= key)
    {
        if (a[i]==key)
        {
            return i;
        }
        i = i*2;
    }
    return binary_search(a,i/2,i,key);    //comment this line to inactivate the binary search
    // binary is used because as range increase drastically for large value and linear search will take more time than binary search since all array is sorted initially
    /* uncomment this to try linear search 
    for(int j=i/2;j<i && j<size;j++)
    {
        if (a[j]==key)
        {
            return j;
        }
    }
    return -1; */
}
int main()
{
    int a[100], size=100,key=75;
    // size = initialization(a);
    for(int i=0,num=0;i<size;i++,num=num+2)
    {
        a[i]=num;
    }
    print(a, size);

    int index = exponential_searching(a,size,key);
    if (index >= 0)
        printf("Number is at [%d] index", index);
    else
        printf("Number does not exist in the array");

    return 0;
}