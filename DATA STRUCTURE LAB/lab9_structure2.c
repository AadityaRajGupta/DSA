#include <stdio.h>
#include <string.h>

struct student
{
    int roll_no;
    char name[30];
    int age;
    int marks[100][7];
};
int main()
{
    struct student s[100];
    int i, n, marksindex, j;
    char subject[9][22];
    strcpy(subject[0], " ROLL_NUMBER ");
    strcpy(subject[1], "       NAME       ");
    strcpy(subject[2],"   AGE    ");
    strcpy(subject[3], " PHYSICS ");
    strcpy(subject[4], "CHEMISTRY ");
    strcpy(subject[5], "  MATHMATICS ");
    strcpy(subject[6], " ENGLISH  ");
    strcpy(subject[7], " COMPUTER SCIENCE ");
    strcpy(subject[8], " PHYSICAL EDUCATION ");

    printf("NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &n);

    // n = 1;
    
    for (i = 0; i < n; i++)
    {
        marksindex = 0;
        printf("\n\nENTER YOUR ROLL NO.:");
        scanf("%d", &s[i].roll_no);
        printf("ENTER YOUR NAME:");
        fflush(stdin);
        gets(s[i].name);
        printf("ENTER YOUR AGE:");
        scanf("%d", &s[i].age);
        printf("ENTER YOUR ENGLISH MARKS:");
        scanf("%d", &s[i].marks[i][marksindex++]);
        printf("ENTER YOUR MATHEMATICS MARKS:");
        scanf("%d", &s[i].marks[i][marksindex++]);
        printf("ENTER YOUR PHYSICS MARKS:");
        scanf("%d", &s[i].marks[i][marksindex++]);
        printf("ENTER YOUR CHEMISTRY MARKS:");
        scanf("%d", &s[i].marks[i][marksindex++]);
        printf("ENTER YOUR COMPUTER SCIENCE MARKS:");
        scanf("%d", &s[i].marks[i][marksindex++]);
        printf("ENTER YOUR PHYSICAL EDUCATION MARKS:");
        scanf("%d", &s[i].marks[i][marksindex++]);
    }

    printf("\n\nSTUDENT DATA:\n");
    printf("============================================================================================================================================\n| ");
    for (i = 0; i < 9; i++)
    {
        printf("%s| ", subject[i]);
    }
    printf("\n============================================================================================================================================\n");

    for (i = 0; i < n; i++)
    {
        marksindex = 0;
        printf("|%14d", s[i].roll_no);
        printf("|%19s|", s[i].name);
        printf("%11d|",s[i].age);
        printf("%10d|", s[i].marks[i][marksindex++]);
        printf("%11d|", s[i].marks[i][marksindex++]);
        printf("%14d|", s[i].marks[i][marksindex++]);
        printf("%11d|", s[i].marks[i][marksindex++]);
        printf("%19d|", s[i].marks[i][marksindex++]);
        printf("%21d|", s[i].marks[i][marksindex++]);
        printf("\n============================================================================================================================================\n");
    }
    
    return 0;
}
