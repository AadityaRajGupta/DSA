#include <stdio.h>
#include <math.h>

// Sieve Of Eratosthnes: pichele prime numbers ke multiple false karna hai
int DAT[101]={0};
int prime(int n)
{
    if (DAT[n]==1)
    {
        return 0;
    }
    if (n<2)
    {
        DAT[n]=1;
    }
    for(int i=2;i<=(sqrt(n));i++)
    {
        if (DAT[i]==0)
        {
            for(int j=i+i;j<=n;j+=i)
            {
                DAT[j]=1;
            }
        }
    }
    if (DAT[n]==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int start=0,end=100,i;
    for(i=start;i<=end;i++)
    {
        if (prime(i))
        {
            printf("%d ",i);
        }
    }
    return 0;
}