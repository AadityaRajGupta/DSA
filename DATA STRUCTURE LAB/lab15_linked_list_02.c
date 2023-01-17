// Program for creation of Linked List header file and test of basic functions through that
#include "lab15_linked_list_02.h"

int main()
{
    struct node *start;
    start=NULL;

    printf("\nLINKED LIST:\n============\n\n");
    inserend(&start,input());
    inserend(&start,input());
    inserend(&start,input());
    inserend(&start,input());

    printf("\n\n\nAFTER INSERTION:\n================\n");
    display(start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n",count(start));
    

    printf("\n\n\nAFTER DELETING 2nd INDEX ELEMENT:\n==================================\n");
    deletion(&start,2);
    display(start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n\n\n",count(start));
    

    int num;
    printf("\n\nENTER NUMBER WANT TO SEARCH IN LINKED LIST: ");
    scanf("%d",&num);
    printf("\nFOUND %d AT INDEX: %d\n\n",num,search(start,num));

    sort(start);
    printf("\n\nAFTER SORTING:\n===============\n");
    display(start);
    printf("\n\n");

    free_all_node(&start);
    return 0;
}



