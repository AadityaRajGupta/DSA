#include <stdio.h>

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

int jump_searching(int a[], int key, int n)
{
    
    return 0;
}

int main()
{
    int a[5], size;
    size = initialization(a);
    print(a, size);

    jump_searching(a, 5, size);

    return 0;
}