#include <stdio.h>
#define size 5
void reset()
{
    printf("\033[0m");
}
void red()
{
    printf("\033[1;31m");
}
void green()
{
    printf("\033[1;32m");
}
void initialisation(int a[][size],int m,int n)
{
    
    printf("\n\n");
    printf("ENTER ELEMENTS OF ARRAY:\n");
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
}

void print(int a[][size],int m,int n)
{
    int l;
    printf("ENTERED ELEMENTS:\n");
    red();
    printf("\n\n------");
    for (l = 1; l < n; l++)
    {
        printf("-----");
    }
    for (int i=0;i<m;i++)
    {
        printf("\n|");
        for(int j=0;j<n;j++)
        {
            printf("%-2d  |", a[i][j]);
        }
        printf("\n------");
        for (l = 1; l < n; l++)
        {
            printf("-----");
        }
    }
    reset();
    printf("\n");
}
int main ()
{
    int a[size][size],b[size][size],c[size][size],a_r,a_c,b_r,b_c,i,j,l;
    printf("ENTER NUMBER OF ROWS:");
    scanf("%d",&a_r);
    printf("ENTER NUMBER OF COLUMNS:");
    scanf("%d",&a_c);
    initialisation(a,a_r,a_c);
    print(a,a_r,a_c);
    printf("ENTER NUMBER OF ROWS:");
    scanf("%d",&b_r);
    printf("ENTER NUMBER OF COLUMNS:");
    scanf("%d",&b_c);
    if  ((a_r==b_r) && (a_c==b_c))
    {
        initialisation(b,b_r,b_c);
        print(b,a_r,a_c);
    }
    else
    {
        printf("MATRIX ADDITION NOT POSSIBLE!!");
        return 0;
    }
    for (i=0;i<a_r;i++)
        for(j=0;j<a_c;j++)
            c[i][j]=a[i][j]-b[i][j];

    printf("ADDITION OF TWO ARRAYS ARE:\n");
    green();
    printf("\n\n------");
    for (l = 1; l < a_c; l++)
    {
        printf("-----");
    }
    for (int i=0;i<a_r;i++)
    {
        printf("\n|");
        for(int j=0;j<a_c;j++)
        {
            printf("%-2d  |", c[i][j]);
        }
        printf("\n------");
        for (l = 1; l < a_c; l++)
        {
            printf("-----");
        }
    }
    reset();
    printf("\n");
    
    return 0;
}