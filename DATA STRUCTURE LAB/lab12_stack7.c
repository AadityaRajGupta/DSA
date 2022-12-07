// Use of structure to pointer and array of structure using pointer 
#include <stdio.h>
#include <stdlib.h>

#define size 20
struct name_struct
{
    char name[size];
};

int main()
{
    int i;
    struct name_struct d;
    printf("\nSTRUCTURE TO POINTER:\n");
    printf("=====================\n\n");
    printf("ENTER YOUR NAME:");
    gets(d.name);
    printf("STORED NAME: %s \n\n",d.name);

    printf("\nARRAY OF STRUCTURE USING POINTER:\n");
    printf("=================================\n\n");
    struct name_struct dat[5];
    printf("\nINPUT NAMES:\n");
    printf("============\n");
    for(i=0;i<5;i++)
    {
        printf("ENTER NAME %d:",i+1);
        gets(dat[i].name);
    }
    printf("\nOUTPUT NAMES:\n");
    printf("=============\n");
    for(i=0;i<5;i++)
    {
        printf("\nNAME %d:",i+1);
        printf("%s ",dat[i].name);
    }

    return 0;
}   





