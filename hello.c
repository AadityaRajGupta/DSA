#include <stdio.h>
// #include<bits/stdc++.h>
#include <string.h>
#include <ctype.h>
// using namespace std;

// this code is submitted to hackerrank
#define MAX_LENGTH 100
int final_code()
{
    char input[MAX_LENGTH];
    scanf("%s", input);

    int length = strlen(input);

    int max = 0;
    char result[MAX_LENGTH];
    int count = 0;
    for (int i = 0; i < length; i++) {
        char c = tolower(input[i]);
        int j = i + 1;
        while (j < length && tolower(input[j]) == c + j - i) {
            j++;
        }
        if (j - i > max) {
            max = j - i;
            count = 0;
            for (int k = i; k < j; k++) {
                result[count++] = input[k];
            }
        }
        i = j - 1;
    }

    for (int i = length - 1; i >= 0; i--) {
        char c = tolower(input[i]);
        int j = i - 1;
        while (j >= 0 && tolower(input[j]) == c + i - j) {
            j--;
        }
        if (i - j > max) {
            max = i - j;
            count = 0;
            for (int k = j + 1; k <= i; k++) {
                result[count++] = input[k];
            }
        }
        i = j + 1;
    }

    printf("%d ", max);
    for (int i = 0; i < count; i++) {
        printf("%c", result[i]);
    }
    printf("\n");
    return 0;
}

int anushka_()
{
    // printf("hello world\n");
    int f = 0, b = 0, j = 0, m = 0;
    char str[100], forw[20], back[20];
    scanf("%s", &str);
    int i = 0;
    while (str[i] != '\0')
    {
        if ((toupper(str[i + 1]) - toupper(str[i + 1]) - 65) == 1)
        {
            f++;
            forw[j] = str[i];
            j++;
        }
        else
        {
            b++;
            back[m] = str[i];
            m++;
        }
        i++;
    }
    if (f >= b)
    {
        printf("%d ", f);
        printf("%s", forw);
    }
    else
    {
        printf("%d ", b);
        printf("%s", back);
    }

    return 0;
}

int main()
{
    char str[50],ans[50];
    gets(str);

    int i=-1,j=0,max=0,index=0;
    while(str[++i]!='\0')
    {
        j=i+1;
        int current=toupper(str[j]);
        while(str[j]!='\0' && (int)(toupper(str[j]))==(int)(toupper(str[j-1])+1))
        {
            j++;
        }
        if(j-i>max)
        {
            max=j-i;
            index=0;
            for(int k=i;k<j;k++)
            {
                ans[index++]=str[k];
            }
        }
        i=j-1;
    }

    printf("%d ", max);
    for (i = 0; i < index; i++) {
        printf("%c", ans[i]);
    }
    return 0;
}


//================================================================================================================
// finding maximum length string from it
/*
INPUT: AEdbGcfpRQs
OUTPUT: 7 AEdbGcf

INPUT: QprSAbdc
OUTPUT: 4 QprS

INPUT: BadEcQtPsr
OUTPUT: 5 BadEc

INPUT: EAfcDbNmoWXtZvySu
OUTPUT: 8 WXtZvySu

*/
int main1()
{
    char str[50];
    int dat[26]={0};
    gets(str);

    int i=0;
    while(str[i]!='\0')
    {
        if(dat[toupper(str[i])-65]==0)
            dat[toupper(str[i])-65]++;
        else
            break;
        i++;
    }
    int max=0,end,start;
    for(i=1;i<26;i++)
    {
        if(dat[i]!=0)
            dat[i]=dat[i]+dat[i-1];
        if(dat[i]>max)
        {
            max=dat[i];
            end=i;
        }
    }
    int check=toupper(str[0])-65;
    for(i=0;i<26;i++)
    {
        if(dat[i]==max)
        {
            end=i;
            start=end-max+1;
            if(check>=start && check<=end)
                break;
        }
    }
    printf("%d ",max);
    i=0;
    while(str[i]!='\0' && max!=0)
    {
        check=toupper(str[i])-65;
        if(check>=start && check<=end)
        {
            printf("%c",str[i]);
            max--;
        }
        i++;
    }
    return 0;
}

//================================================================================================================

// all adjacent character from the starting
int main2()
{
    char str[50];
    int dat[26]={0};
    gets(str);

    // printf("%d",'A'); ==> 65   // printf("%d",'a'); ==> 97
    int i=0;
    while(str[i]!='\0')
    {
        if(dat[toupper(str[i])-65]==0)
            dat[toupper(str[i])-65]++;
        else
            break;
        i++;
    }

    i=toupper(str[0])-65;
    while(dat[i]!=0 && i>=0)
    {
        i--;
    }
    ++i;    // printf("%d",i+1);
    int count=0;
    while(dat[i++]!=0)
        count++;

    printf("%d ",count);

    i=0;
    while(count>0)
    {
        printf("%c",str[i++]);
        count--;
    }
    return 0;
}