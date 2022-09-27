//https://docs.google.com/spreadsheets/d/1NFa8r6Oi6gkmkQKmtVlRONwc-sbLvi5wjHQrQQ8b1Jo/edit?usp=sharing
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
/**
 * *hello world
 * !alert
 * ?something missing
 * TODO: execute
 * @param Aaditya hello
 * //hello
 */
/**
 * ?Program for Set Difference
 * ?Program for Set Symmetric Difference
 */

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

//! QUICK SORT
//!==========
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void pivot_set(int a[], int size)
{
    srand(time(NULL));
    int i = rand() % size;
    swap(&a[0], &a[i]);
}
void quick_sort(int a[], int start, int end)
{
    int red = start + 1, green;
    if (end - start >= 1)
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
}

//! MERGING SORT:
//!=============
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

// count repeated number
// not repeated number
// missing
// string frequency
// anagra Eg: actual  tacaul

int repeated_number()
{
    int a[15] = {2, 6, 5, 9, 4, 2, 3, 10, 6, 7, 8, 6, 5, 10, 7}, i, max = 0, dat[20] = {0}, n = 15;

    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    // int dat[max+1];
    // dat[max+1];
    for (i = 0; i < n; i++)
    {
        dat[a[i]]++;
    }

    for (i = 0; i < max + 1; i++)
    {
        if (dat[i] > 1)
            printf("\nELEMENT [%d] repeated [%d] times\n", i, dat[i]);
    }
    return 0;
}
int missing()
{
    int a[10] = {1, 5, 3, 4, 5, 6, 7, 8, 9, 10}, i, max = 0, dat[11] = {0}, n = 10;
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    for (i = 0; i < n; i++)
    {
        dat[a[i]]++;
    }
    for (i = 1; i < max + 1; i++)
    {
        if (dat[i] == 0)
            printf("\nELEMENT [%d] missing\n", i);
    }
    return 0;
}
int string_frequency()
{
    int i, dat[26] = {0};
    char str[20] = "AADITYARAJGUPTA";
    int n = strlen(str);
    // printf("%d",n);

    for (i = 0; i < n; i++)
    {
        dat[str[i] - 'A']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (dat[i] > 1)
            printf("\nCHARACTER [%c] repeated [%d] times\n", i + 'A', dat[i]);
    }
    return 0;
}
int anagram()
{
    int i, dat[26] = {0};
    char str1[20] = "AADITYA";
    char str2[20] = "DAIATYA";
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2)
    {
        printf("GIVEN STRING IS NOT ANAGRAM");
        return 0;
    }
    for (i = 0; i < n1; i++)
    {
        dat[str1[i] - 'A']++;
    }
    for (i = 0; i < n2; i++)
    {
        dat[str2[i] - 'A']--;
    }
    for (i = 0; i < 26; i++)
    {
        if (dat[i] != 0)
        {
            printf("GIVEN STRING IS NOT ANAGRAM");
            return 0;
        }
    }
    printf("GIVEN STRING IS ANAGRAM");
    return 0;
}


int f(int n,int a[])
{
    int value;
    if (a[n]!=0)
    {
        return a[n];
    }
    if (n==1|| n==0)
    {
        value=0;
    }
    else
    {
        value=((n-1)+f(n-2,a));
    }
    a[n] = value;
    return (value);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int selection_sort()
{
    int a[10] = {2, 6, 5, 68, 4, 5, 1, 5, 6, 7}, min_i;
    min_i = 0;
    for (int j = 0; j < 10; j++)
    {
        for (int i = j + 1; i < 10; i++)
        {
            if (a[i] < a[min_i])
            {
                min_i = i;
            }
        }
        /*for(int k=0;k<10;k++)
        {
            printf(" %d ",a[k]);
        }
        printf("\n%d\n",j);*/
        swap(&a[j], &a[min_i]);
    }

    printf("AFTER SORTING SELECTION:\n");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", a[i]);
    }
    return 0;
}
int insertion_sort()
{
    int a[10] = {2, 6, 5, 68, 4, 5, 1, 5, 6, 7}, element, temp, i, j, k;
    for (i = 1; i < 10; i++)
    {
        element = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > element)
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1] = element;
        /*for (int k = 0; k < 10; k++)
        {
            printf(" %d ", a[k]);
        }
        printf("\n\n");*/
    }
    printf("AFTER SORTING INSERTION:\n");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", a[i]);
    }
    return 0;
}
int bubble_sort()
{
    // minimum element pushed up to top in implementation largest number shift in last;
    int a[10] = {2, 6, 5, 68, 4, 5, 1, 5, 6, 7};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j + 1], &a[j]);
            }
        }
    }

    printf("AFTER SORTING BUBBLE:\n");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", a[i]);
    }
    return 0;
}
int main()
{

    insertion_sort();
    return 0;
}
int main__()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a[100], b[100], size, ele, work[100], size_a, size_b;

    // size=initialization(a);
    // print(a,size);

    //?insertion(a,&size);
    // print(a,size);

    //? merging two sorted arrays
    /*
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    merging_sorted_array(a,b,size_a,size_b,work);
    print(work,size_a+size_b);
    */

    //?SYMMETRIC PROGRAM: common nhi aata hai
    /* //A(-)B= (A-B) | (B-A)
    size_a=initialization(a);
    print(a,size_a);
    size_b=initialization(b);
    print(b,size_b);
    //merge_sort(a,0,size_a,work);
    //merge_sort(b,0,size_b,work);
    size=symmetric_program(a,b,size_a,size_b,work);
    print(work,size); */
    return 0;
}