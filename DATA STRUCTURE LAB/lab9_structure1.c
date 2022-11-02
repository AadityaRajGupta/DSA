#include <stdio.h>
#include <string.h>

struct student
{
    int roll_no;
    char name[30];
    int marks[100][7];
    float percentage;
    char eligible[3];
};
struct student1
{
    int roll_no;
    char name[30];
    int marks[7];
    float percentage;
    char eligible[3];
};
int main_for_one_input()
{
    struct student s;

    printf("ENTER YOUR ROLL NO.:");
    scanf("%d", &s.roll_no);
    printf("ENTER YOUR NAME:");
    fflush(stdin);
    gets(s.name);
    printf("ENTER YOUR MARKS:");
    scanf("%d", &s.marks);

    printf("STUDENT DATA:\n");
    printf("%d  %s  %d", s.roll_no, s.name, s.marks);
    return 0;
}
int main_for_n_inputs()
{
    struct student s[100];
    int i, n;
    printf("NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("\n\nENTER YOUR ROLL NO.:");
        scanf("%d", &s[i].roll_no);
        printf("ENTER YOUR NAME:");
        fflush(stdin);
        gets(s[i].name);
        printf("ENTER YOUR MARKS:");
        scanf("%d", &s[i].marks);
    }

    printf("STUDENT DATA:\n");
    printf("\nROLL NO                NAME    MARKS\n");
    for (i = 0; i < n; i++)
    {
        printf("\n%5d  %20s    %2d", s[i].roll_no, s[i].name, s[i].marks);
    }
    return 0;
}
int main_with_formatting()
{
    struct student s[100];
    int i, n, marksindex, j, min1, min2;
    float sum = 0;
    char subject[10][20];
    strcpy(subject[0], "ROLL_NUMBER");
    strcpy(subject[1], "       NAME       ");
    strcpy(subject[2], " PHYSICS ");
    strcpy(subject[3], "CHEMISTRY ");
    strcpy(subject[4], "  MATHMATICS");
    strcpy(subject[5], " ENGLISH  ");
    strcpy(subject[6], "COMPUTER SCIENCE");
    strcpy(subject[7], "PHYSICAL EDUCATION");
    strcpy(subject[8], "PERCENTAGE");
    strcpy(subject[9], "ELIGIBLE(YES/NO)");

    // printf("NUMBER OF DATA WANT TO ENTER:");
    // scanf("%d", &n);
    n = 1;
    for (i = 0; i < n; i++)
    {
        marksindex = 0;
        printf("\nENTER YOUR ROLL NO.:");
        scanf("%d", &s[i].roll_no);
        printf("ENTER YOUR NAME:");
        fflush(stdin);
        gets(s[i].name);
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

        min1 = __INT_MAX__;
        min2 = __INT_MAX__; // INT_MAX=+2147483647
        for (j = 0; j < 6; j++)
        {
            if (s[i].marks[i][j] < min1)
            {
                min1 = s[i].marks[i][j];
            }
        }
        for (j = 0; j < 6; j++)
        {
            if (s[i].marks[i][j] < min2 && s[i].marks[i][j] != min1)
            {
                min2 = s[i].marks[i][j];
            }
        }
        for (j = 0; j < 6; j++)
        {
            if (s[i].marks[i][j] != min2 && s[i].marks[i][j] != min1)
            {
                sum += s[i].marks[i][j];
            }
        }
        s[i].percentage = sum / 4.0;
        ((int)s[i].percentage >= 95) ? strcpy(s[i].eligible, "YES") : strcpy(s[i].eligible, "NO");
    }

    printf("\n\nSTUDENT DATA:\n");

    printf("=======================================================================================================================================================\n| ");
    for (i = 0; i < 10; i++)
    {
        printf("%s| ", subject[i]);
    }
    printf("\n=======================================================================================================================================================\n");

    for (i = 0; i < n; i++)
    {
        marksindex = 0;
        printf("|%12d", s[i].roll_no);
        printf("|%19s|", s[i].name);
        printf("%10d|", s[i].marks[i][marksindex++]);
        printf("%11d|", s[i].marks[i][marksindex++]);
        printf("%13d|", s[i].marks[i][marksindex++]);
        printf("%11d|", s[i].marks[i][marksindex++]);
        printf("%17d|", s[i].marks[i][marksindex++]);
        printf("%19d|", s[i].marks[i][marksindex++]);
        printf("%11.2f|", s[i].percentage);
        printf("%17s|", s[i].eligible);
        printf("\n=======================================================================================================================================================\n");
    }
    return 0;
}

int main()
{
    struct student1 s;
    int marksindex, j, min1, min2;
    float sum = 0;

    marksindex = 0;
    printf("\nENTER YOUR ROLL NO.:");
    scanf("%d", &s.roll_no);
    printf("ENTER YOUR NAME:");
    fflush(stdin);
    gets(s.name);
    printf("ENTER YOUR ENGLISH MARKS:");
    scanf("%d", &s.marks[marksindex++]);
    printf("ENTER YOUR MATHEMATICS MARKS:");
    scanf("%d", &s.marks[marksindex++]);
    printf("ENTER YOUR PHYSICS MARKS:");
    scanf("%d", &s.marks[marksindex++]);
    printf("ENTER YOUR CHEMISTRY MARKS:");
    scanf("%d", &s.marks[marksindex++]);
    printf("ENTER YOUR COMPUTER SCIENCE MARKS:");
    scanf("%d", &s.marks[marksindex++]);
    printf("ENTER YOUR PHYSICAL EDUCATION MARKS:");
    scanf("%d", &s.marks[marksindex++]);

    min1 = __INT_MAX__;
    min2 = __INT_MAX__; // INT_MAX=+2147483647
    for (j = 0; j < 6; j++)
    {
        if (s.marks[j] < min1)
        {
            min1 = s.marks[j];
        }
    }
    for (j = 0; j < 6; j++)
    {
        if (s.marks[j] < min2 && s.marks[j] != min1)
        {
            min2 = s.marks[j];
        }
    }
    for (j = 0; j < 6; j++)
    {
        if (s.marks[j] != min2 && s.marks[j] != min1)
        {
            sum += s.marks[j];
        }
    }
    s.percentage = sum / 4.0;
    ((int)s.percentage >= 95) ? strcpy(s.eligible, "YES") : strcpy(s.eligible, "NO");

    printf("\n\nSTUDENT IS ELIGIBLE FOR DU: %s", s.eligible);
    return 0;
}
