#include <stdio.h>
int fact(int num)
{
    if (num == 1)
    {
        return num;
    }
    return (num * fact(num - 1));
}
int main()
{
    int num;
    printf("ENTER ANY NUMBER:");
    scanf("%d", &num);
    printf("FACTORIAL OF %d[%d!]:%d", num, num, fact(num));
    return 0;
}