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
int jump_searching(int a[], int key, int size)
{
    int step = sqrt(size);
    int index = 0, i, j;
    for (i = 0; i < size; i = i + step)
    {
        if (a[i] == key)
        {
            return i;
        }
        if (a[i] > key)
        {
            index = i - step + 1;
            for (j = index; j < i; j++)
            {
                if (a[j] == key)
                {
                    return j;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int a[5], size,key=5;
    size = initialization(a);
    print(a, size);

    int index = jump_searching(a,key,size);
    if (index >= 0)
        printf("Number is at [%d] index", index);
    else
        printf("Number is not exist in the array");

    return 0;
}