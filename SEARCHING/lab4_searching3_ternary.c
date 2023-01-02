#include <stdio.h>
/*
Time Complexity: O(log3n)
Auxiliary Space: O(log3n)
*/
void print(int a[], int size)
{
    int l;
    printf("\nARRAY ELEMENT:\n");
    printf("------");
    for (l = 1; l < size; l++)
    {
        printf("-----");
    }
    printf("\n|");
    for (int i = 0; i < size; i++)
    {
        printf("%-2d  |", a[i]);
        // printf(" %d ", a[i]);
    }
    printf("\n------");
    for (l = 1; l < size; l++)
    {
        printf("-----");
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

int ternary_searching(int a[], int key, int start, int end)
{
    int mid1 = start + ((end-start) / 3);
    int mid2 = end - ((end-start) / 3);
    printf("\nstart: %d ,mid1:%d ,mid2: %d ,end: %d \n", start, mid1, mid2, end);
    if (end - start >= 0 )
    //if (start<=end)
    {
        if (a[mid1] == key)
        {
            return mid1;
        }
        else if (a[mid2] == key)
        {
            return mid2;
        }
        else if (a[mid1] > key)
        {
            ternary_searching(a, key, start, mid1-1);
        }
        else if (a[mid1] < key && a[mid2] > key)
        {
            ternary_searching(a, key, mid1+1,mid2-1);
        }
        else if (a[mid2] < key)
        {
            ternary_searching(a, key,mid2+1,end);
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    int a[5], size, c;
    size = initialization(a);
    print(a, size);

    c = ternary_searching(a, 5, 0, size-1);
    printf("%d", c);
    return 0;
}