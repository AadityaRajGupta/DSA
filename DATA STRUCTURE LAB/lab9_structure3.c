#include <stdio.h>
#include <string.h>

struct student
{
    int roll_no;
    char name[30];
    int age;
    char address[100];
};
int main()
{
    struct student s[100];
    int i, n;
    char subject[4][30];
    strcpy(subject[0], " ROLL_NUMBER ");
    strcpy(subject[1], "       NAME       ");
    strcpy(subject[2], " AGE ");
    strcpy(subject[3], "         ADDRESS         ");

    printf("NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &n);

    // n = 1;
    
    for (i = 0; i < n; i++)
    {
        printf("\n\nENTER YOUR ROLL NO.:");
        scanf("%d", &s[i].roll_no);
        printf("ENTER YOUR NAME:");
        fflush(stdin);
        gets(s[i].name);
        printf("ENTER YOUR AGE:");
        scanf("%d", &s[i].age);
        printf("ENTER YOUR ADDRESS:");
        fflush(stdin);
        gets(s[i].address);
    
    }

    printf("\n\nSTUDENT DATA:\n");
    printf("======================================================================\n| ");
    for (i = 0; i < 4; i++)
    {
        printf("%s| ", subject[i]);
    }
    printf("\n======================================================================\n");

    for (i = 0; i < n; i++)
    {
        printf("|%14d", s[i].roll_no);
        printf("|%19s|", s[i].name);
        printf("%5d |",s[i].age);
        printf("%26s|", s[i].address);
        printf("\n======================================================================\n");
    }
    
    return 0;
}
