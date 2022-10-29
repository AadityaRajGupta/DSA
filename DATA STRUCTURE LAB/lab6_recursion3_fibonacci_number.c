#include <stdio.h>
int dat[100];
int fibonacci(int num)
{
    int value;
    if (dat[num]!=0)
    {
        return dat[num];
    }
    if (num == 0 || num == 1)
    {
        value=num;
    }
    else
    {
        value=(fibonacci(num - 1) + fibonacci(num - 2));
    }
    dat[num] = value;
    return (value);
}
int main()
{
    int end, i;
    printf("ENTER NUMBER OF FIBONACCI NUMBER WANT TO PRINT:");
    scanf("%d", &end);
    printf("FIBONACCI SERIES:\n");
    for (i = 0; i < end; i++)
    {
        printf("%d\t", fib(i));
    }
    return 0;
}