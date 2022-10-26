#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 10

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

int dat[10];
int DAT[101] = {0};
int prime(int n)
{
    if (DAT[n] == 1)
    {
        return 0;
    }
    if (n < 2)
    {
        DAT[n] = 1;
    }
    for (int i = 2; i <= (sqrt(n)); i++)
    {
        if (DAT[i] == 0)
        {
            for (int j = i + i; j <= n; j += i)
            {
                DAT[j] = 1;
            }
        }
    }
    if (DAT[n] == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int h(int key, int m)
{
    return (key % m);
}

void insert(int data, int m)
{
    struct node *add_node = (struct node *)malloc(sizeof(struct node));
    add_node->data = data;
    add_node->next = NULL;
    int index = h(data, m);

    if (chain[index] == NULL)
    {
        chain[index] = add_node;
    }
    else
    {
        struct node *temp = chain[index];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = add_node;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, data, i, tem, m;
    //printf("\n\nENTER NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &n);
    for (i = 0; i < size; i++)
    {
        chain[i] = NULL;
    }

    //printf("\n\nENTER YOUR DATA:\n");

    tem = n;
    while (!prime(tem))
    {
        tem++;
    }
    m = tem--;
    while (n)
    {
        scanf("%d", &data);
        insert(data, m);
        n--;
    }
    
    for (i = 0; i < m; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->", i);
        while (temp)
        {
            printf("%d -->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    return 0;
}
