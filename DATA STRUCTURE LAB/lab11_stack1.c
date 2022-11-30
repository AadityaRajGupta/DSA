#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*example:
ENTER ANY POSTFIX EXPRESSION:7 4 -3 * 1 5 + / *
FINAL: -14

ENTER ANY POSTFIX EXPRESSION:1 2 3 * 4 / + 6 - 1 5 ^ +
FINAL: 5

// for subtract in above case 6-2 or 2 - 6
    int item=subtract();
    push(item*(-1));
}
*/
#define size 100
struct stack
{
    int original[size];
    int top;
} *s;

#define create() s->top = -1
#define push(item) s->original[++s->top] = item
#define pop() s->original[s->top--]
#define a pop()
#define b pop()
#define add() (a)+(b)
#define subtract() (a)-(b)
#define multiply() (a)*(b)
// #define divide() (a)/(b)    // larger should be divided by smaller
#define power() (int)pow(a,b)
#define number(ch) (int)(ch-'0')

int divide()
{
    int num1,num2,temp,flag=0;
    num1=pop();
    num2=pop();
    if (num1<0||num2<0) flag=1;
    if (num1<0) num1=-1*num1;
    if (num2<0) num2=-1*num2;
    if(num1<num2)
    {
        temp=num1;
        num1=num2;
        num2=temp;
    }
    int ans=num1/num2;
    if(flag==1) ans=-1*ans;
    return ans;
}
int number_my(char ch)
{
    switch (ch)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
}
//DISPLAY STACK
void display()
{
    printf("\nSTACK:");
    for(int i=0;i<=s->top;i++)
        printf("%d ",s->original[i]);
}
int main()
{
    char str[size];
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    printf("ENTER ANY POSTFIX EXPRESSION:");
    gets(str);

    int flag=0,temp=0;

    int i=-1;
    while(str[++i]!='\0')
    {
        flag=0;
        temp=0;
        if (str[i]==' ')
            continue;
        else if (str[i]=='+')
            push(add());
        else if (str[i]=='-' && str[i+1]==' ')
            push(subtract());
        else if (str[i]=='*')
            push(multiply());
        else if (str[i]=='/')
        {
            int item=divide();
            push(item);
        }
        else if (str[i]=='^')
            push(power());
        else
        {
            while(str[i]!=' ')
            {
                if (str[i]=='-')
                    flag=1;
                else
                    temp=temp*10+number(str[i]);
                i++;
            }
            if (flag==1)
                temp=temp*(-1);
            push(temp);
        }
        // display();
    }
    printf("\nFINAL: %d",pop());    
    return 0;
}
