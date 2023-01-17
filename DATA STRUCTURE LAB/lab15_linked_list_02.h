//  HEADER FILE: for premitive opertations of linked list

// Traversal
// Insertion
// Deletion 
// Search - 
// Sort 

#include <stdio.h>
#include <stdlib.h>

// macro for the address allocation using malloc 
#define getnode() (struct node *)malloc(sizeof(struct node))

// structure of single node of linked list
struct node 
{
    int data;
    struct node *next;
};

// display the linked list formed
void display(struct node *head)
{
    struct node *temp = head;
    printf("\nLINKED LIST-->");
    while (temp)
    {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// insertion at beginning of linked list
void inserbeg(struct node **start, int x)
{
    struct node *newnode;
    newnode = getnode();
    newnode->data = x;
    newnode->next = *start;
    *start = newnode;
}
// insertion in linked list
void inserend(struct node **start, int x)
{
    if (*start == NULL)
    {
        inserbeg(&(*start), x);
    }
    else
    {
        struct node *newnode, *ptr;
        ptr = *start;
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

// count the number of element present in linked list
int count(struct node *head)
{
    struct node *temp = head;
    int count=0;
    while (temp)
    {
        count+=1;
        temp = temp->next;
    }
    return count;
}

// delete any node from linked list
void deletion(struct node **start,int index)
{
    struct node *temp = *start;
    int count=-1;
    while (temp)
    {
        count+=1;
        if ((count+1)==index)
        {
            temp->next=temp->next->next;
            break;
        }
        temp = temp->next;
    }   
}

// search the data in linked list i.e linear search
int search(struct node *head,int num)
{
    struct node *temp = head;
    int count=-1;
    while (temp)
    {
        count+=1;
        if(temp->data==num)
            return count;
        temp = temp->next;
    }
    return -1;
}

// sort the linked list 
void sort(struct node *head)
{
    struct node *i,*j;
    i=head;
    while(i!=NULL)
    {
        j=head;
        while(j!=NULL)
        {
            if (i->data<=j->data)
            {
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
            j=j->next;
        }
        i=i->next;
    }
}

// simple input number and return number
int input()
{
    int item;
    printf("\nENTER ANY NUMBER:");
    scanf("%d", &item);
    return item;
}

// Funtion to free all node space from memory 
void free_all_node(struct node **start)
{
    struct node *temp;
    while((*start)!=NULL)
    {
        temp=*start;
        *start=(*start)->next;
        free(temp);
    }
}

// Initialise the linked list by taking its address
void initialise_ll(struct node **start,char name)
{
    printf("\nFOR %c:\n========\n",name);
    int choose=0;
    do{
        inserend(&(*start),input());
        printf("ENTER -1 TO STOP INSERTION: ");
        scanf("%d",&choose);
    }while(choose!=-1);

    display(*start);
    printf("\nNUMBER OF ELEMENT PRESENT IN LINKED LIST: %d\n",count(*start));
}

// concatenation of two linked list by taking three linked list as input parameters by address
void concatenate_ll(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *temp;
    temp=*start1;
    while(temp!=NULL)
    {
        inserend(&(*start3),temp->data);
        temp=temp->next;
    }
    temp=*start2;
    while(temp!=NULL)
    {
        inserend(&(*start3),temp->data);
        temp=temp->next;
    }
}

// insertion between the linked list by taking index
void insertion_between(struct node **start,int index)
{
    struct node *temp = *start,*newnode;
    int count=-1;
    while (temp)
    {
        count+=1;
        if ((count + 1) == index)
        {
            newnode = getnode();
            newnode->data = input();
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }   
}

// make a copy linked list by recursive function call
struct node *copy_ll(struct node *first)
{
    if (first==NULL)
        return NULL;
    else
    {
        struct node *newnode;
        newnode=getnode();
        newnode->data=first->data;
        newnode->next=copy_ll(first->next);

        return newnode;
    }
}

// split one linked list in two parts
void split(struct node **start1,struct node **start2,struct node **start3)
{
    int num=count(*start1);
    struct node *temp;
    temp=*start1;
    for (int i=1;i<=(num/2);i++)
    {
        inserend(&(*start2), temp->data);
        temp = temp->next;
    }
    for(int i=(num/2)+1;i<=num;i++)
    {
        inserend(&(*start3),temp->data);
        temp=temp->next;
    }
} 

// reserve karke: starting me bhi add kar sakte hai phir insertion O(1) and overall O(N) then reverse O(N). final => O(N) else this method take O(N^2)
void reverse_ll(struct node **start);
void merge_ll__O_N(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;
    p=*start1;
    q=*start2;

    while (p!=NULL && q!=NULL)
    {
        if (p->data<=q->data)
        {
            inserbeg(&(*start3),p->data);
            p=p->next;
        }
        else
        {
            inserbeg(&(*start3),q->data);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        inserbeg(&(*start3),p->data);
        p=p->next;
    }
    while(q!=NULL)
    {
        inserbeg(&(*start3),q->data);
        q=q->next;
    }
    reverse_ll(&(*start3));
}   

// merge two sorted linked list 
void merge_ll__O_N_2(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;
    p=*start1;
    q=*start2;

    while (p!=NULL && q!=NULL)
    {
        if (p->data<=q->data)
        {
            inserend(&(*start3),p->data);
            p=p->next;
        }
        else
        {
            inserend(&(*start3),q->data);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        inserend(&(*start3),p->data);
        p=p->next;
    }
    while(q!=NULL)
    {
        inserend(&(*start3),q->data);
        q=q->next;
    }
}   

// finding middle node data using two pointer(manipulated)
void middle_element_ll(struct node *start)
{
    struct node *mid,*temp;
    temp=start;
    mid=start;

    while(temp)
    {
        mid=mid->next;
        temp=temp->next->next;
        if( temp->next == NULL)
            temp=temp->next;
        else if( temp->next->next == NULL)
            temp=temp->next->next;
    }
    if(mid!=NULL)
        printf("\nMIDDLE ELEMENT: %d\n",mid->data);
}

// Binary Search on the Linked List
struct node *middle_element_ll_for_binary_search(struct node *start,struct node *last)
{
    struct node *mid,*temp;
    mid=start;
    temp=start->next;

    while(temp)
    {
        temp=temp->next;
        if(temp!=NULL)
        {
            temp=temp->next;
            mid=mid->next;
        }
    }
    return mid;
}
int binary_search_ll(struct node *root,int num)
{
    struct node *start,*last,*mid;

    start=root;
    last=NULL;

    do{
        mid=middle_element_ll_for_binary_search(start,last);

        if (num==mid->data)
            return 1;
        
        else if (num>mid->data)
            start=mid->next;

        else
            last=mid;
    }while(last!=NULL || last!=start);

    return 0;   
}


// Reversing the Linear Linked List
void reverse_ll(struct node **start)
{
    struct node *previous,*current,*forward;
    previous=NULL;
    current=*start;
    forward=(*start)->next;

    while (current!=NULL)
    {
        current->next=previous;

        previous=current;
        current=forward;
        if(forward!=NULL)
            forward=forward->next;
    }
    *start=previous;
}

// print reverse linked list 
int print_reverse_ll(struct node *start)
{
    struct node *temp;
    temp=start;
    if(temp->next!=NULL)
    {
        print_reverse_ll(temp->next);
        printf(" %d -->",temp->data);
    }
    else
        printf(" %d -->",temp->data);
    return 0;
}

// Pair wise swapping 
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void pair_wise_swap_ll(struct node *start)
{
    struct node *previous;
    previous=start;

    while (previous!=NULL && previous->next!=NULL)
    {
        swap(&previous->data,&previous->next->data);

        previous=previous->next->next;
    }
}

// print_Kth_element_from_end
int print_Kth_element_from_end(struct node *start,int k)
{
    // reverse karke bhi kar sakte hai
    struct node *temp;
    temp=start;

    if (temp->next != NULL)
    {
        int count = print_Kth_element_from_end(temp->next, k) + 1;
        if (count == k)
            printf(" %d ", temp->data);
        return count;
    }
    else
        return 1;
    return 0;
}

// Creation of Ascending Order Linear Linked List i.e just replace inserend with this function
void arranged_insertion(struct node **start, int x)
{
    if (*start == NULL)
    {
        inserbeg(&(*start), x);
    }
    else
    {
        struct node *newnode, *ptr;
        ptr = *start;
        if(ptr->data>x)
            inserbeg(&(*start),x);
        else
        {
            while (ptr->next != NULL && ptr->next->data < x)
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
    }
}

// delete all duplicate nodes in the linked list
void delete_duplicate(struct node *start)
{
    struct node *i,*j,*temp;

    i=start;
    while(i!=NULL)
    {
        j=i;
        while(j->next!=NULL)
        {
            if(i->data==j->next->data)
                j->next=j->next->next;
            else
                j=j->next;
        }
        i=i->next;
    }
}

// function to detect the merging point of two linked list
void detect_merging_point(struct node *start1,struct node *start2)
{
    struct node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    
    while(ptr1!=ptr2)
    {
        if (ptr1==NULL)
            ptr1=start2;
        if (ptr2==NULL)
            ptr2=start1;
        
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    if(ptr1==ptr2)
        printf("MERGING POINT IN THE LINKED LIST: %d",ptr1->data);
    else 
        printf("NO MERGING POINT EXIST !!!");    
}

// delete the head node and return the data
void delete_beg(struct node **start)
{
    struct node *temp;
    int num;
    num=(*start)->data;

    temp=(*start);
    (*start)=(*start)->next;
    free(temp);

    // printf("\n\nELEMENTED DELETED: %d",num);
    // return num;
}

// arrange the consonants and vowel nodes such that all the vowels nodes come before the consonants (replace it with inserend)
void arrange_consonants_and_vowel_nodes(struct node **start, char x)
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

// Deletion of all occuraces of x 
void delete_all_occurrence(struct node **start,int x)
{
    struct node *temp,*pre;
    while((*start)->data == x && (*start)!=NULL)
    {
        temp = (*start);
        (*start) = (*start)->next;
        free(temp);
    }
    temp = (*start);
    pre=NULL;
    while (temp != NULL)
    {
        if(temp->data==x)
            pre->next=temp->next;
        else 
            pre=temp;

        temp=temp->next;
    }

    display(*start);
}

// Delete kth node from end
int delete_Kth_element_from_end_FailsForOneNode(struct node *start,int k)
{
    // reverse karke bhi ho sakta hai
    // two pointer se bhi ake k times chal chuka hoga dusre pointer ke saath end tak jayega isse dusra pointer kth node pe hoga end se
    struct node *temp;
    temp=start;

    if (temp->next != NULL)
    {
        int count = delete_Kth_element_from_end(temp->next, k) + 1;
        if (count == k)
            printf(" %d ", temp->data);
        if (count == k+1)
            temp->next=temp->next->next;
        return count;
    }
    else
        return 1;
    return 0;
}

// remove kth node from end recursive approach
int delete_Kth_element_from_end(struct node *start,int k)
{
    if (!start)
        return k;
    k=delete_Kth_element_from_end(start->next, k);
    k -= 1;
    if (k == -1)
    {
        struct node *temp = start->next;
        printf(" %d ",temp->data);
        start->next = start->next->next;
        free(temp);
    }
    return k;
}
struct node *remove_Nth_Node_From_End(struct node *start, int n)
{
    if (!start || !start->next)
    {
        printf(" %d ",start->data);
        printf("\n\nLINKED LIST HAD ONLY ONE NODE NOW DELETED!!!\n");
        return NULL;
    }

    struct node *newnode;
    newnode = getnode();
    newnode->next = start;

    delete_Kth_element_from_end(newnode, n);

    return newnode->next;
}

// addition of two given link list
// for very large number => input numbers in group of 4 to reduce the cycles 
void addition_of_LL(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;
    reverse_ll(&(*start1));
    reverse_ll(&(*start2));

    p=*start1;
    q=*start2;

    int carry=0;
    int total=0,sum=0;
    while(p!=NULL && q!=NULL)
    {   
        total=p->data+q->data+carry;
        sum = total % 10; // 10000;
        carry = total / 10; // 10000;
        inserbeg(&(*start3),sum);
        p=p->next;
        q=q->next;
    }
    while(p!=NULL)
    {
        total = p->data + carry;
        sum = total % 10 ; // 10000;
        carry = total / 10 ; // 10000;
        inserbeg(&(*start3),sum);
        p=p->next;
    }
    while (q!=NULL)
    {
        total = q->data + carry;
        sum = total % 10 ; // 10000;
        carry = total / 10; // 10000;
        inserbeg(&(*start3),sum);
        q=q->next;
    }
    if(carry == 1)
    // if(carry!=0)
        inserbeg(&(*start3),carry);
}

/* substraction of two given linked list
if(count(start1) < count(start2))
    {
        subtraction_of_LL(&start2,&start1,&start3);
        start3->data=(start3->data)*-1;
    }
    else 
        subtraction_of_LL(&start1,&start2,&start3);
*/
void subtraction_of_LL(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;
    reverse_ll(&(*start1));
    reverse_ll(&(*start2));

    p=*start1;
    q=*start2;

    int diff=0,carry=0;
    while(p!=NULL && q!=NULL)
    {   
        diff=p->data-q->data-carry;
        if(diff<0)
        {
            diff=q->data;
            carry=1;
        }
        else
            carry=0;
        inserbeg(&(*start3),diff);
        p=p->next;
        q=q->next;
    }
    while(p!=NULL)
    {
        diff = p->data-carry;
        if (diff < 0)  carry=1; 
        else carry=0;

        inserbeg(&(*start3),diff);
        p=p->next;
    }
    while (q!=NULL)
    {
        diff = q->data-carry;
        if (diff < 0)  carry=1; 
        else carry=0;

        inserbeg(&(*start3),diff);
        q=q->next;
    }
}


/* structure should be change
recursive approach: in which we directly print the information (for subtraction just change sign and mutiply q->coff with -1 )
void polynomial_addition_LL_recursive(struct node *start1,struct node *start2)
{
    if(start1==NULL && start2==NULL)
    {
        return ;
    }
    if(start1->exp==start2->exp )
    {
        printf(" %dX^%d-->", start1->coff+start2->coff,start1 ->exp);
        polynomial_addition_LL_recursive(start1->next,start2->next);
    }
    if(start1->exp > start2->exp )
    {
        printf(" %dX^%d-->", start1->coff,start1->exp);
        polynomial_addition_LL_recursive(start1->next,start2);
    }
    if(start1->exp < start2->exp )
    {
        printf(" %dX^%d-->", start2->coff,start2->exp);
        polynomial_addition_LL_recursive(start1,start2->next);
    }
}
*/
void polynomial_addition_LL_recursive()
{
    printf("see the code in comment");
}

/* approach similar to merging of ll (for subtraction just change sign and mutiply q->coff with -1 )
void polynomial_addition_LL(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;

    p=*start1;
    q=*start2;

    int c,e;
    while(p!=NULL && q!=NULL)
    {
        if(p->exp>q->exp)
        {
            inserbeg(&(*start3),p->coff,p->exp);
            p=p->next;
        }
        else if (p->exp<q->exp)
        {
            inserbeg(&(*start3),q->coff,q->exp);
            q=q->next;
        }
        else
        {
            c=p->coff+q->coff;
            inserbeg(&(*start3),c,p->exp);
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        inserbeg(&(*start3),p->coff,p->exp);
        p=p->next;
    }
    while(q!=NULL)
    {
        inserbeg(&(*start3),q->coff,q->exp);
        q=q->next;
    }
    reverse_ll(&(*start3));
}
*/
void polynomial_addition_LL(struct node **start1,struct node **start2,struct node **start3)
{
    printf("see the code in comment");
}

/* Polynomial Multiplication used dat table 
int dat[101];
void polynomial_multiplication_LL(struct node **start1,struct node **start2,struct node **start3)
{
    struct node *p,*q;

    p=*start1;
    q=*start2;

    int c,e;
    while (p!=NULL)
    {
        q=*start2;
        while(q!=NULL)
        {
            c=p->coff*q->coff;
            e=p->exp+q->exp;
            inserbeg(&(*start3),c,e);
            q=q->next;
        }
        p=p->next;
    }

    struct node *temp;
    temp=*start3;
    e=0;
    while(temp)
    {
        if(temp->exp>e)
            e=temp->exp;

        if(dat[temp->exp]==0)
            dat[temp->exp]=temp->coff;
        else
            dat[temp->exp]=dat[temp->exp] + temp->coff;
        temp=temp->next;
    }

    free_all_node(&(*start3));

    for(int i=0;i<=e;i++)
    {
        if(dat[i]!=0)
            inserbeg(&(*start3),dat[i],i);
    }
    
}*/
void polynomial_multiplication_LL(struct node **start1,struct node **start2,struct node **start3)
{
    printf("see the code in comment");
}

