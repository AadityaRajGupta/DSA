// Program to build the Expression Tree from the given Infix expression

#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node *newnode_add(char data)
{
    struct node *n;
    n = getnode();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    n->next=NULL;
    return n;
}

// ALL TRAVERSAL
void inorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        inorder_traversal(temp->left);
        printf("%c ",temp->data);
        inorder_traversal(temp->right);
    }
}
void preorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        printf("%c ",temp->data);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
    }
}
void postorder_traversal(struct node *temp)
{
    if (temp!=NULL)
    {
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%c ",temp->data);
    }
}
void printCurrentLevel(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf(" %c ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
int max_a(int a,int b)
{
    return (a>b) ? a : b;
}
int height(struct node *hello)
{
    if(hello!=NULL)
        return max_a(height(hello->left),height(hello->right))+1;
    return 0;
}
void levelorder_traversal_using_height(struct node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        printf("----");
    }
}

void print_all_traversal(struct node *root)
{
    printf("\nINORDER TRAVERSAL: ");
    inorder_traversal(root);
    printf("\nPRE-ORDER TRAVERSAL: ");
    preorder_traversal(root);
    printf("\nPOST-ORDER TRAVERSAL: ");
    postorder_traversal(root);
    printf("\nLEVEL-ORDER TRAVERSAL: ");
    levelorder_traversal_using_height(root);
}

int precedence(char a,char b)
{
    if(a=='^' || a=='*' || a=='/' || a=='%' )
    {
        if(b=='^')
            return 0;
        else    
            return 1;
    }
    else
    {
        if(a=='+' || b=='-')
        {
            if(b=='+' || b=='-')
                return 1;
            else
                return 0;
        }
    }
}

struct node *build_expression_tree(char *str)
{
    int i=0;
    char temp;
    struct node *temp_root;
    
    struct node *start=NULL,*new;   // this is for the oparand stack
    char Operator_stack[25];
    int top=-1;   // this is for operator stack


    while(str[i]!='\0')
    {
        temp=str[i];
        
        if(temp>='a' && temp<='z' || temp>='A' && temp<='Z' || temp>='0' && temp<='9')
        {
            temp_root=newnode_add(temp);

            // push(operand_stack,temp_root);
            temp_root->next=start;
            start=temp_root;
        }
        else
        {
            // while(!IsEmpty(Operator_stack) && precedence(stack_top(Operator_stack),temp))
            while(top!=-1 && precedence(Operator_stack[top],temp))
            {
                // temp=pop(Operator_stack);
                temp=Operator_stack[top--];

                temp_root=newnode_add(temp);

                // temp_root->right=pop(operand_stack);
                temp_root->right=start;
                start=start->next;

                // temp_root->left=pop(operand_stack);
                temp_root->left=start;
                start=start->next;

                // push(operand_stack,temp_root);
                temp_root->next=start;
                start=temp_root;
            }
            // push(Operator_stack,temp);
            Operator_stack[++top]=str[i];
        }
        i++;
    }
    // while(!IsEmpty(Operator_stack))
    while(top!=-1)
    {
        // temp=pop(Operator_stack);
        temp=Operator_stack[top--];

        temp_root=newnode_add(temp);
        
        // temp_root->right=pop(operand_stack);
        temp_root->right=start;
        start=start->next;
        
        // temp_root->left=pop(operand_stack);
        temp_root->left=start;
        start=start->next;
        
        // push(operand_stack,temp_root);
        temp_root->next=start;
        start=temp_root;
    }
    
    // return pop(operand_stack);
    return start;
}

int main()
{
    struct node *root;
    root=NULL;

    char expression[50];
    printf("ENTER THE INFIX EXPRESSION: ");
    gets(expression);

    root=build_expression_tree(expression);

    print_all_traversal(root);
    
    return 0;
}

