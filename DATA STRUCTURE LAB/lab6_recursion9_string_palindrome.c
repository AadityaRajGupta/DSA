#include <stdio.h>
int palindrome(char s[],int left,int right)
{
    if (s==NULL || left<0 || right<0)
    {
        return 0;
    }
    if (left>=right)
    {
        return 1;
    }
    if(s[left]==s[right])
    {
        return palindrome(s,left+1,right-1);
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    char str[50],size=0;
    // printf("ENTER ANY STRING:");
    scanf("%[^\n]%c",str);
    while(str[size++] != '\0');
    if (palindrome(str,0,size-2))
    {
        printf("GIVEN STRING [%s] IS PALINDROME",str);
    }
    else
    {
        printf("GIVEN STRING [%s] IS NOT PALINDROME !!!",str);
    }
    return 0;
}