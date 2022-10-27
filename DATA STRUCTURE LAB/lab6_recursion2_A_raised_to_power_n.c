#include <stdio.h>
int fun(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    return a * fun(a, b - 1);
}
int main()
{
    int a, b;
    printf("ENTER VALUE OF BASE(A) AND POWER(B) i.e [A^B]: ");
    scanf("%d%d", &a, &b);
    printf("%d raised to the power %d [%d^%d] :%d",a,b,a,b,fun(a,b));
    return 0;
}