#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Program for Infix to Postfix Coversion (Infix Expression with Parenthesis)

/*example:

ENTER ANY INFIX EXPRESSION:K + L - M * N + ( O ^ P ) * W / U / V * T + Q 
POSTFIX EXPRESSION: K L + M N * - O P ^ W * U / V / T * + Q + 

ENTER ANY INFIX EXPRESSION:1 + 2 * ( 3 / 4 ) - ( 6 + 1 ) ^ 5  
POSTFIX EXPRESSION: 1 2 3 4 / * + 6 1 + 5 ^ -

*/
#define size 100

#define create() s->top = -1
#define push_A(item) s->symbols[++s->top] = item
#define pop() s->symbols[s->top--]
#define top_E() s->symbols[s->top]
#define number(ch) (int)(ch-'0')
struct stack
{
    char symbols[size];
    int top;
}*s;

int empty()
{
    while(s->top!=-1 && top_E()!='(')
        printf("%c ",pop());
    --s->top;
}
int display()
{
    printf("\n\nSTACK:");
    for(int i=0;i<=s->top;i++)
        printf("%c ",s->symbols[i]);
    printf("\n\n");
}
int main()
{
    // !Space separated values and one space at end compulsory
    char str[size];
    s=(struct stack *)malloc(sizeof(struct stack));
    create();
    printf("\n\nENTER ANY INFIX EXPRESSION:");
    gets(str);

    int flag=0,temp=0;

    int i=-1;
    printf("\nPOSTFIX EXPRESSION: ");
    while(str[++i]!='\0')
    {
        flag=0;
        temp=0;
        if (str[i]==' ')
            continue;
        else if (str[i]=='(')
            push_A(str[i]);
        else if (str[i]==')')
            empty();
        else if (str[i]=='+')
        {
            while (top_E()=='+' || top_E()=='-' || top_E()=='*' || top_E()=='/' || top_E()=='^')
                printf("%c ",pop());
            push_A(str[i]);
        }
        else if (str[i]=='-')
        {
            while (top_E()=='+' || top_E()=='-' || top_E()=='*' || top_E()=='/' || top_E()=='^')
                printf("%c ",pop());
            push_A(str[i]);
        }
        else if (str[i]=='*')
        {
            while (top_E()=='*' || top_E()=='/' || top_E()=='^')
                printf("%c ",pop());
            push_A(str[i]);
        }
        else if (str[i]=='/')
        {
            while (top_E()=='*' || top_E()=='/'|| top_E()=='^')
                printf("%c ",pop());
            push_A(str[i]);
        }
        else if (str[i]=='^')
        {
            push_A(str[i]);
        }
        else if (str[i]>='0' && str[i]<='9')
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
            // push(temp);
            printf("%d ",temp);
        }
        else
        {
            printf("%c ",str[i]);
        }
        // display();
    }
    empty(); 
    return 0;
}
