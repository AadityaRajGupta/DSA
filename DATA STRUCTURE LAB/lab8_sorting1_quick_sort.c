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
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int quick_sort(int a[], int start, int end)
{
    int red = start + 1, green;
    if (start<end)
    {
        for (green = start + 1; green < end; green++)
        {
            if (a[green] < a[start])
            {
                swap(&a[green], &a[red]);
                red++;
            }
        }
        swap(&a[red - 1], &a[start]);

        quick_sort(a, start, red - 1);
        quick_sort(a, red, end);
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a[100],size;
    size=initialization(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    quick_sort(a,0,size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}
