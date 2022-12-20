#include <stdio.h>

int print(int *p)
{
    for(int i=0;i<5;i++)
    {
        printf("%d  ",*(p+i));
    }
}
int initialize(int *p)
{
    for(int i=0;i<5;i++)
    {
        scanf("%d",p+i);
    }
}
int main()
{
    int a[5];
    initialize(a);
    printf("\n");
    print(a);
    return 0;
}