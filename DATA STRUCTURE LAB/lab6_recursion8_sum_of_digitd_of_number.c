#include <stdio.h>
int SOD(int num, int sum)
{
    if (num == 0)
    {
        return sum;
    }
    else
    {
        sum = sum + num % 10;
        SOD(num / 10, sum);
    }
}
int main()
{
    int num;
    printf("ENTER ANY NUMBER:");
    scanf("%d", &num);
    printf("SUM OF DIGITS OF %d : %d", num, SOD(num, 0));
    return 0;
}