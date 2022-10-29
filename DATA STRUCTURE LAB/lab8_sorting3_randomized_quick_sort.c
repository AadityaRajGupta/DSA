#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int partition(int a[], int start, int end)
{
    int red = start + 1, green;
    for (green = start + 1; green < end; green++)
    {
        if (a[green] < a[start])
        {
            swap(&a[green], &a[red]);
            red++;
        }
    }
    swap(&a[red - 1], &a[start]);
    return red;
}
int random_partition(int a[], int start, int end)
{
    srand(time(NULL));
    int random = start + rand() % (end - start);

    int temp = a[random];
    a[random] = a[start];
    a[start] = temp;

    return partition(a, start, end);
}
void random_quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int red = random_partition(a, start, end);
        random_quickSort(a, start, red - 1);
        random_quickSort(a, red, end);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a[100], size;
    size = initialization(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a, size);

    random_quickSort(a, 0, size);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a, size);

    return 0;
}
