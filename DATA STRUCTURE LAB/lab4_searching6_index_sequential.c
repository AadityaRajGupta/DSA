#include <stdio.h>
#include <math.h>
void print(int a[], int size)
{
    printf("\nARRAY ELEMENT:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}
int initialization(int a[])
{
    int size;
    printf("\nENTER THE SIZE OF ARRAY:");
    scanf("%d", &size);
    printf("ENTER ELEMENTS:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    return size;
}

int index_sequential_searching(int a[], int key, int size)
{
    int step=size/5,start,end;
    int i,j,ele_table[5],index=0,ind_table[5];
    for(i=0;i<size;i=i+step)
    {
        ele_table[index]=a[i];
        ind_table[index]=i;
        index++;
    }
    for(i=0;i<index;i++)
    {
        if (key == ele_table[i])
        {
            return ind_table[i];
        }
        else
        {
            if (key < ele_table[i] )
            {
                start=ind_table[i-1];
                end=ind_table[i];
                for(j=start;j<end;j++)
                {
                    if (key == a[j])
                    {
                        return j;
                    }
                }
                return -1;
            }
        }
    }
}
int main()
{
    int a[10], size,key=5;
    size = initialization(a);
    print(a, size);
    int index = index_sequential_searching(a,key,size);
    if (index >= 0)
        printf("Number is at [%d] index", index);
    else
        printf("Number is not exist in the array");

    return 0;
}