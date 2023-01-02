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
int interpolation_search(int a[],int l,int h,int key)
{
    int pos;

    if (key>=a[l] && key<=a[h] && l<=h)
    {
        pos = l + ( ((double)(h - l)*(key - a[l]) / (a[h] - a[l]))  );

        if (a[pos]==key)
        {
            return pos;
        }
        else if (key<a[pos])
        {
            return interpolation_search(a,l,pos-1,key);
        }
        else
        {
            return interpolation_search(a,pos+1,h,key);
        }
    }
    return -1;
}
int main()
{
    int a[5], size,key=5;
    size = initialization(a);
    print(a, size);

    int index = interpolation_search(a,0,size-1,key);
    if (index >= 0)
        printf("Number is at [%d] index", index);
    else
        printf("Number is not exist in the array");

    return 0;
}