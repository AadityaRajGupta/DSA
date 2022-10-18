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
    /*
20  35 45  55  65  75  85  95 100 105
0   1   2   3   4   5   6   7  8   9

0                   6             ==> ind_table me ye value jaegi
20                  85            ==> ele_table me ye value jaegi 
index = 2 (matlub kitne element store kare)

phir key compare karke range pata chalega ki element kidhar ho sakta hai 
let key=55

tho phele bar i=0 
comparison hoga 20 == 55 false 
tho else me jaenge 55<20  false 

tho next iteration jho ki i=1 hoga
comparison hoga 85 == 55 false 
tho else me jaenge 55<85  true   ==> tho ye hame pata chal gaya ki element iske piche wale index pe hai kahi
tho just piche wale index se le (ind_table[i-1]) ke iss index (ind_table[i]) tak compare karke check karenge original array use karke agar mila tho vo index return nhi tho -1;


// isme maine decide kara hua hai ki mai 5 ke batch me array break karunga jho ki step=size/5 hai...........phir array me 5 ka increment karte karte saare index dusri array me store kar raha hu ind_table[index] me aur ele_table[index] me uss index pe wala element..............ab jho new array bani hai usme treverse karna hai length hamne index ke through store kari hai........phir ele_table[i] hame value dega jisse hum compare karenge apni key kho.............*/
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