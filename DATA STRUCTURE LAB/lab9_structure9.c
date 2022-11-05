#include <stdio.h>
#include <string.h>

struct student
{
    int roll_no;
    char name[30];
    int age;
    char address[100];
} s[100];

void print_equal_to_14_age(int n)
{
    char subject[4][30];
    strcpy(subject[0], " ROLL_NUMBER ");
    strcpy(subject[1], "       NAME       ");
    strcpy(subject[2], " AGE ");
    strcpy(subject[3], "         ADDRESS         ");
    int i=0,count=0;
    while(i!=n)
    {
        if(s[i].age==14)
            count++;
        i++;
    }
    if (count)
    {
        printf("\n\nSTUDENT DATA OF STUDENT AGE EQUAL TO 14:\n");
        printf("======================================================================\n| ");
        for (i = 0; i < 4; i++)
        {
            printf("%s| ", subject[i]);
        }
        printf("\n======================================================================\n");

        for (i = 0; i < n; i++)
        {
            if (s[i].age == 14)
            {
                printf("|%14d", s[i].roll_no);
                printf("|%19s|", s[i].name);
                printf("%5d |", s[i].age);
                printf("%26s|", s[i].address);
                printf("\n======================================================================\n");
            }
        }
    }
    else
    {
        printf("\nNO STUDENT EXIST HAVING AGE EQUAL TO 14!!!\n\n");
    }
}

void print_even_rollno(int n)
{
    char subject[4][30];
    strcpy(subject[0], " ROLL_NUMBER ");
    strcpy(subject[1], "       NAME       ");
    strcpy(subject[2], " AGE ");
    strcpy(subject[3], "         ADDRESS         ");
    int i=0,count=0;
    while(i!=n)
    {
        if(s[i].roll_no%2==0)
            count++;
        i++;
    }
    if (count)
    {
        printf("\n\nSTUDENT DATA OF STUDENT HAVING EVEN ROLL NUMBER:\n");
        printf("======================================================================\n| ");
        for (i = 0; i < 4; i++)
        {
            printf("%s| ", subject[i]);
        }
        printf("\n======================================================================\n");

        for (i = 0; i < n; i++)
        {
            if (s[i].roll_no % 2 == 0)
            {
                printf("|%14d", s[i].roll_no);
                printf("|%19s|", s[i].name);
                printf("%5d |", s[i].age);
                printf("%26s|", s[i].address);
                printf("\n======================================================================\n");
            }
        }
    }
    else
    {
        printf("\nNO STUDENT HAVE EVEN ROLL NUMBER!!!\n\n");
    }
}

void print_rollno(int n,int roll)
{
    char subject[4][30];
    strcpy(subject[0], " ROLL_NUMBER ");
    strcpy(subject[1], "       NAME       ");
    strcpy(subject[2], " AGE ");
    strcpy(subject[3], "         ADDRESS         ");
    int i=0,count=0,roll_no_index;
    for (i = 0; i < n; i++)
    {
        if(s[i].roll_no==roll)
        {
            roll_no_index=i;
            count++;
            break;
        }
    }
    if (count!=0)
    {
        printf("\nSTUDENT DATA:\n");
        printf("======================================================================\n| ");
        for (i = 0; i < 4; i++)
        {
            printf("%s| ", subject[i]);
        }
        printf("\n======================================================================\n");

        i=roll_no_index;
        printf("|%14d", s[i].roll_no);
        printf("|%19s|", s[i].name);
        printf("%5d |", s[i].age);
        printf("%26s|", s[i].address);
        printf("\n======================================================================\n");
    }
    else
    {
        printf("\nNO STUDENT HAVE ROLL NUMBER %d!!!\n\n",roll);
    }
}

int main()
{
    int i, n,roll;

    printf("NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &n);

    // n = 10;   rakhna hai is question ke liye

    for (i = 0; i < n; i++)
    {
        printf("\n\nENTER YOUR ROLL NO.:");
        scanf("%d", &s[i].roll_no);
        printf("ENTER YOUR NAME:");
        fflush(stdin);
        gets(s[i].name);
        do
        {
            printf("ENTER YOUR AGE(between 11 and 14):");
            scanf("%d", &s[i].age);
        } while (s[i].age < 11 || s[i].age > 14);

        printf("ENTER YOUR ADDRESS:");
        fflush(stdin);
        gets(s[i].address);

        printf("\nSUCCESSFULLY ADDED RECORD");
    }
    print_equal_to_14_age(n);
    print_even_rollno(n);
    printf("\n\nENTER ROLL NUMBER WANT TO SEARCH:");
    scanf("%d",&roll);
    print_rollno(n,roll);

    return 0;
}
