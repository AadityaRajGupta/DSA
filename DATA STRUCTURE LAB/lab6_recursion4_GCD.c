#include <stdio.h>
int GCD(int dividend,int divisor)
{
    if (dividend%divisor==0)
    {
        return divisor;
    }
    return GCD(divisor,dividend%divisor);
}
int swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int a,b;
    printf("ENTER ANY TWO NUMBERS TO CALCULATE GCD:");
    scanf("%d%d",&a,&b);
    if (a<b)
    {
        swap(&a,&b);
    }
    printf("GCD OF %d and %d: %d",a,b,GCD(a,b));
    return 0;
}