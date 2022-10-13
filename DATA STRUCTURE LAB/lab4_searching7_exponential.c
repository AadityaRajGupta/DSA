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
int min(int a,int b)
{
    if (a<b)
    {
        return a;
    }
    return b;
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
            return binary_searching(a,key,start,mid-1);
        }
        else
        {
            return binary_searching(a,key,mid+1,end);
        }
    }
    return -1;
}
int exponential_searching(int a[], int n, int key)
{
    if (a[0] == key)
        return 0;

    int i = 1;
    while (i < n && a[i] <= key)
        i = i*2;

    return binary_searching(a, i/2,min(i, n-1), key);
}
int main()
{
    int a[5], size,key=5;
    size = initialization(a);
    print(a, size);

    int index = exponential_searching(a,key,size);
    if (index >= 0)
        printf("Number is at [%d] index", index);
    else
        printf("Number is not exist in the array");

    return 0;
}