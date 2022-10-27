#include <stdio.h>
int reverse_fun(int num,int reverse)
{
    if (num==0)
    {
        return reverse;
    }
    else
    {
        reverse=reverse*10+num%10;
        return reverse_fun(num/10,reverse);
    }
}
int main()
{
    int num;
    printf("ENTER ANY NUMBER:");
    scanf("%d",&num);
    printf("REVERSE OF %d : %d",num,reverse_fun(num,0));
    return 0;
}