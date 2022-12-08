// Use of malloc to implement array of structure using pointer and Input/Output using pointer and function
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
    struct name_struct *d;
    d=(struct name_struct *)malloc(sizeof(struct name_struct));
    printf("\nSTRUCTURE TO POINTER:\n");
    printf("=====================\n\n");
    printf("ENTER YOUR NAME:");
    gets(d->name);
    printf("STORED NAME: %s \n\n",d->name);
    return 0;
}   





