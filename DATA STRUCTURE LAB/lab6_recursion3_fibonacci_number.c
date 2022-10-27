#include <stdio.h>
int fib(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }
    return (fib(num - 1) + fib(num - 2));
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