#include <stdio.h>
#include <string.h>

struct marks
{
    int roll_no;
    char name[30];
    int phy_marks;
    int chem_marks;
    int maths_marks;
    float percentage;
};

int main()
{
    struct marks s[100];
    int i, n;
    float sum=0;
    char subject[6][20];
    strcpy(subject[0], "ROLL_NUMBER");
    strcpy(subject[1], "       NAME       ");
    strcpy(subject[2], " PHYSICS ");
    strcpy(subject[3], "CHEMISTRY ");
    strcpy(subject[4], "  MATHMATICS");
    strcpy(subject[5], "PERCENTAGE");

    
    printf("NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        sum=0;
        printf("\n\nENTER YOUR ROLL NO.:");
        scanf("%d", &s[i].roll_no);
        printf("ENTER YOUR NAME:");
        fflush(stdin);
        gets(s[i].name);
        printf("ENTER YOUR PHYSICS MARKS:");
        scanf("%d", &s[i].phy_marks);
        printf("ENTER YOUR CHEMISTRY MARKS:");
        scanf("%d", &s[i].chem_marks);
        printf("ENTER YOUR MATHEMATICS MARKS:");
        scanf("%d", &s[i].maths_marks);
        sum=s[i].chem_marks+s[i].phy_marks+s[i].maths_marks;
        s[i].percentage = sum / 3.0;

    }

    printf("\n\nSTUDENT DATA:\n");

    printf("===================================================================================\n| ");
    for (i = 0; i < 6; i++)
    {
        printf("%s| ", subject[i]);
    }
    printf("\n===================================================================================\n");

    for (i = 0; i < n; i++)
    {
        printf("|%12d", s[i].roll_no);
        printf("|%19s|", s[i].name);
        printf("%10d|", s[i].phy_marks);
        printf("%11d|", s[i].chem_marks);
        printf("%13d|", s[i].maths_marks);
        printf("%11.2f|", s[i].percentage);
        printf("\n===================================================================================\n");
    }
    return 0;
}
