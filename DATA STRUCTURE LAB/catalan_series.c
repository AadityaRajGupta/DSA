#include <stdio.h>

int dat[100];

int cat(int num)
{
    if (num==0 || num==1)
        return 1;
    else if (dat[num]!=0)
        return dat[num];
    else
    {
        int sum=0;
        for(int i=0;i<num;i++)
            sum=sum+(cat(num-1-i)*cat(i));
        dat[num]=sum;
    }
    return dat[num];
}
int main()
{
    printf("%d",cat(5));
    return 0;
}