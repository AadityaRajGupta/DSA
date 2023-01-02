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

int searching(int a[], int key, int n)
{
    int b[n], s = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            b[s++] = i;
            // printf("FOUND ELEMENT AT [%d] POSITION",i+1);
        }
    }
    if (s)
    {
        for (int j = 0; j < s; j++)
        {
            printf("\nFOUND ELEMENT AT [%d] INDEX", b[j]);
        }
    }
    else
    {
        printf("ELEMENT NOT FOUND");
    }
    return 0;
}

int main()
{
    int a[5], size;
    size = initialization(a);
    print(a, size);

    searching(a, 5, size);

    return 0;
}