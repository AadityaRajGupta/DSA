// Program to arrange the consonats ad vowel nodes of the linked list it in such a way that all the vowels nodes come before the consonats while maintaining the order of their arrival

#include <stdio.h>
#include <stdlib.h>

#define getnode() (struct node *)malloc(sizeof(struct node))

struct node
{
    char data;
    struct node *next;
};
int count(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    while (temp)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}
int display(struct node *head)
{
    struct node *temp = head;
    printf("\nLINKED LIST--> ");
    while (temp)
    {
        printf(" %c -->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}
void inserbeg(struct node **start, char x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
void inserend(struct node **start, char x)
{
    if (*start == NULL)
    {
        inserbeg(&(*start), x);
    }
    else
    {
        // p -> vowel ; q-> consonent
        struct node *newnode, *ptr;
        ptr = *start;
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        {
            while (ptr->next != NULL && (ptr->next->data =='a' || ptr->next->data =='e' || ptr->next->data =='i' || ptr->next->data =='o'|| ptr->next->data =='u'))
            {
                ptr = ptr->next;
            }
            newnode = getnode();
            newnode->data = x;
            if (ptr->next == NULL)
                newnode->next = NULL;
            else
                newnode->next = ptr->next;
            ptr->next = newnode;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            newnode = getnode();
            newnode->data = x;
            newnode->next = NULL;

            ptr->next = newnode;
        }
    }
}
int input()
{
    char item;
    printf("\nENTER ANY ALPHABET:");
    fflush(stdin);
    scanf("%c", &item);
    return item;
}
void initialise_ll(struct node **start)
{
    int choose = 0;
    do
    {
        inserend(&(*start), input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d", &choose);
    } while (choose != -1);

    display(*start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n", count(*start));
}

void free_all_node(struct node **start)
{
    struct node *temp;
    while ((*start) != NULL)
    {
        temp = *start;
        *start = (*start)->next;
        free(temp);
    }
}
int main()
{
    struct node *start1;
    start1 = NULL;

    printf("\nLINKED LIST:\n============\n\n");

    // for taking input one by one
    // initialise_ll(&start1);

    char str[100];
    printf("ENTER ANY STRING: ");
    gets(str);
    int i=0;
    while(str[i]!='\0')
    {
        inserend(&start1, str[i]);
        i++;
    }

    display(start1);

    free_all_node(&start1);
    return 0;
}
