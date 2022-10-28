#include <stdio.h>

void print(int a[], int size)
{
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
void printm(int a[], int start, int end)
{
    printf(" {");
    for (int i = start; i <= end; i++)
    {
        printf("%d", a[i]);
        if (i < end)
            printf(",");
    }
    printf("}");
}
void merge(int a[], int start, int mid, int end, int work[])
{
    int i = start, j = mid + 1, index = 0;
    int size = end - start;
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            work[index++] = a[i++];
        else if (a[i] > a[j])
            work[index++] = a[j++];
    }
    while (i <= mid)
        work[index++] = a[i++];
    while (j <= end)
        work[index++] = a[j++];

    /*
    printf("\n");
    printm(a,start,mid);
    printm(a,mid+1,end);
    printf(" => ");
    printm(work,0,size);
    */

    for (i = 0, j = start; i <= size; i++, j++)
    {
        a[j] = work[i];
    }
}
void merge_sort(int a[], int start, int end, int work[])
{
    if (end - start >= 1)
    {
        int mid = (start + end) / 2;
        merge_sort(a, start, mid, work);
        merge_sort(a, mid + 1, end, work);

        merge(a, start, mid, end, work);
    }
}

int main()
{
    int a[100],work[100],size;
    size=initialization(a);

    printf("ARRAY BEFORE SORTING:\n");
    print(a,size);

    merge_sort(a,0,size-1,work);

    printf("\n\nARRAY AFTER SORTING:\n");
    print(a,size);

    return 0;
}
