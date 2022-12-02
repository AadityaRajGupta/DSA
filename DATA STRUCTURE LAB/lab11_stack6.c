// Program for Infix to Prefix Coversion (Infix Expression with Parenthesis)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*example:

ENTER ANY INFIX EXPRESSION:K + L - M * N + ( O ^ P ) * W / U / V * T + Q 
PREFIX EXPRESSION: + Q + * T / V / U * W ^ P O - * N M + L K

ENTER ANY INFIX EXPRESSION:1 + 2 * ( 3 / 4 ) - ( 6 + 1 ) ^ 5 
PREFIX EXPRESSION: - ^ 5 + 1 6 + * / 4 3 2 1
*/

#define size 100

#define create() s->top = -1;s->top_pre=-1
#define push_A(item) s->symbols[++s->top] = item
#define pop() s->symbols[s->top--]
#define top_E() s->symbols[s->top]

#define pop_Pre() s->prefix[s->top_pre--]
#define push_Pre(item) s->prefix[++s->top_pre] = item

struct stack
{
    char symbols[size];
    char prefix[size];
    int top_pre;
    int top;
}*s;

int empty_post()
{
    while(s->top!=-1 && top_E()!='(')
        push_Pre(pop());
    --s->top;
}
int display()
{
    printf("\nPREFIX EXPRESSION: ");
    while(s->top_pre!=-1)
        printf("%c ",pop_Pre());
    printf("\n");
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
    // printf("\nPOSTFIX EXPRESSION: ");
    while(str[++i]!='\0')
    {
        flag=0;
        temp=0;
        if (str[i]==' ')
            continue;
        else if (str[i]=='(')
            push_A(str[i]);
        else if (str[i]==')')
            empty_post();
        else if (str[i]=='+')
        {
            while (top_E()=='+' || top_E()=='-' || top_E()=='*' || top_E()=='/' || top_E()=='^')
                push_Pre(pop());
            push_A(str[i]);
        }
        else if (str[i]=='-')
        {
            while (top_E()=='+' || top_E()=='-' || top_E()=='*' || top_E()=='/' || top_E()=='^')
                push_Pre(pop());
            push_A(str[i]);
        }
        else if (str[i]=='*')
        {
            while (top_E()=='*' || top_E()=='/' || top_E()=='^')
                push_Pre(pop());
            push_A(str[i]);
        }
        else if (str[i]=='/')
        {
            while (top_E()=='*' || top_E()=='/'|| top_E()=='^')
                push_Pre(pop());
            push_A(str[i]);
        }
        else if (str[i]=='^')
            push_A(str[i]);
        else
            push_Pre(str[i]);
    }
    empty_post(); 
    display();
    return 0;
}
