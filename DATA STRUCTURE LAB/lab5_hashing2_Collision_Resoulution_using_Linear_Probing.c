#include <stdio.h>

int dat[10];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int size = 10, t, data, location, i,temp;
    //printf("\n\nENTER NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &t);
    //printf("\n\nENTER YOUR DATA AND LOCATION:\n");
    while (t)
    {
        scanf("%d%d", &data, &location);
        if (dat[location] == 0)
        {
            dat[location] = data;
        }
        else if (dat[location]!=0)
        {
            temp=location;
            while (dat[temp] != 0)
            {
                temp=temp%9;
                temp++;
                if (temp==location)
                {
                    return -1;
                }
            }
            dat[temp] = data;
        }
        t--;
    }
    for (i=0;i<size;i++)
    {
        printf("%d  %d\n",i, dat[i]);

    }

        return 0;
}