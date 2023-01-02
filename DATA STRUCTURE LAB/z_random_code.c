//https://docs.google.com/spreadsheets/d/1NFa8r6Oi6gkmkQKmtVlRONwc-sbLvi5wjHQrQQ8b1Jo/edit?usp=sharing
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// random forest
// xgpoost

/**
 * *hello world
 * !alert
 * ?something missing
 * TODO: execute
 * @param Aaditya hello
 * //hello
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


/* upper bhi define kara hai line 43 quick sort ke liye
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}*/
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

//ROMAN TO INT : LEETCODE(1 october)
int romanToInt(char * s){
    int table[100]={
        ['I']=1,['V']=5,['X']=10,['L']=50,['C']=100,['D']=500,['M']=1000,
    };
    int sum=0;
    for(int i=0;s[i];i++)
    {
        if(table[s[i]] < table[s[i+1]])
            sum=sum- table[s[i]];
        else
            sum=sum+table[s[i]];
    }
    return sum;
}

int main_for_romantoint()
{

    int num=romanToInt("XII");
    printf("%d ",num);
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}

//any key ASCII VALUE
char key()
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();
    return c;
}
int main_for_key_ASCII_value()
{
    printf("%d",key());
    return 0;
}

void reset()
{
    printf("\033[0m");
}
void blinker()
{
    printf("\033[1;46m");
}
void red()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[1;32m");
}
void yellow()
{
    printf("\033[1;33m");
}
int colour_and_keynumber()
{
    // reset colour: printf("\033[0m");
    int x = key();
    printf("%d", x);
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            printf("\033[1;%d%dm", i, j);
            printf("\nhello  %d%d\n", i, j);
        }
    }
    return 0;
}
/*
In short:
72   up
75 left arrow
77  right arrow
80   down
27   esc
13 enter
48-57 0-9
*/

