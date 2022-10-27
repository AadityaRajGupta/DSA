#include <stdio.h>
int binary_search(int a[],int start,int end,int key)
{
    int mid;
    if (start<=end)
    {
        mid = (start+end)/2;
        if (a[mid]==key)
        {
            return mid;
        }
        else if(a[mid]>key)
        {
            return binary_search(a,start,mid-1,key);
        }
        else
        {
            return binary_search(a,mid+1,end,key);
        }
    }
    return -1;
}
int main()
{
    int a[10]={10,20,30,40,50,60,70,80,90,100},key,size=10,index;
    printf("ENTER ELEMENT WANT TO SEARCH:");
    scanf("%d",&key);
    index=binary_search(a,0,size-1,key);
    if(index==-1)
    {
        printf("ELEMENT NOT FOUND !!");
    }
    else
    {
        printf("ELEMENT FOUND AT INDEX: %d",index);
    }
    return 0;
}