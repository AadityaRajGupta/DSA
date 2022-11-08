/*
13. Let us work on the menu of a library. Create a structure containing book information like accession number, name of author, book title and flag to know whether book is issued or not. Create a menu in which the following can be done.
 1 - Display book information
 2 - Add a new book
 3 - Display all the books in the library of a particular author
 4 - Display the number of books of a particular title
 5 - Display the total number of books in the library
 6 - Issue a book
 (If we issue a book, then its number gets decreased by 1 and if we add a book, its number gets increased by 1)

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct library
{
    int accession_number;
    char author_name[30];
    char title[30];
    int flag;
} l[100];

int input = 0;

void initial_add()
{
    int i, n;
    char ch[30];
    printf("NUMBER OF DATA WANT TO ENTER:");
    scanf("%d", &n);
    input = n;

    for (i = 0; i < n; i++)
    {
        printf("\n\nENTER ACCESSION NUMBER:");
        scanf("%d", &l[i].accession_number);
        printf("ENTER BOOK AUTHOR NAME:");
        fflush(stdin);
        gets(l[i].author_name);
        printf("ENTER BOOK TITLE:");
        fflush(stdin);
        gets(l[i].title);
        l[i].flag = 0;

        printf("\nSUCCESSFULLY ADDED RECORD\n");
    }
}
void displayall()
{
    if (input != 0)
    {
        int i;
        char lib[4][35];
        strcpy(lib[0], " ACCESSION NUMBER ");
        strcpy(lib[1], "        NAME OF AUTHOR        ");
        strcpy(lib[2], "          BOOK TITLE          ");
        strcpy(lib[3], " ISSUED(YES/NO) ");
        printf("\n\nALL BOOK INFORMATION:\n");
        printf("=======================================================================================================\n| ");
        for (i = 0; i < 4; i++)
        {
            printf("%s| ", lib[i]);
        }
        printf("\n=======================================================================================================\n");
        for (i = 0; i < input; i++)
        {
            printf("|%10d         |", l[i].accession_number);
            printf("%31s|", l[i].author_name);
            printf("%31s|", l[i].title);
            (l[i].flag == 1) ? printf("       YES       |") : printf("        NO       |");
            printf("\n=======================================================================================================\n");
        }
    }
    else
    {
        printf("\nNO DATA AVAILABLE TO DISPLAY!!!\nPLEASE ADD ANY DATA FIRST\n\n");
    }
}
void add()
{
    int i = input;
    printf("\n\nENTER ACCESSION NUMBER:");
    scanf("%d", &l[i].accession_number);
    printf("ENTER BOOK AUTHOR NAME:");
    fflush(stdin);
    gets(l[i].author_name);
    printf("ENTER BOOK TITLE:");
    fflush(stdin);
    gets(l[i].title);
    l[i].flag = 0;

    printf("\nSUCCESSFULLY ADDED RECORD\n");
    input++;
}
void display_author()
{
    int i = 0, count = 0;
    char ch[30];
    char lib[4][35];
    strcpy(lib[0], " ACCESSION NUMBER ");
    strcpy(lib[1], "        NAME OF AUTHOR        ");
    strcpy(lib[2], "          BOOK TITLE          ");
    strcpy(lib[3], " ISSUED(YES/NO) ");

    printf("\nENTER AUTHOR NAME TO FIND ALL THE BOOK:");
    gets(ch);

    while (i != input)
    {
        if (!strcmp(l[i].author_name, ch))
        {
            count += 1;
        }
        i++;
    }
    if (count)
    {
        printf("\n\nALL BOOK INFORMATION WITH AUTHOR NAME %s:\n", ch);
        printf("=======================================================================================================\n| ");
        for (i = 0; i < 4; i++)
        {
            printf("%s| ", lib[i]);
        }
        printf("\n=======================================================================================================\n");
        for (i = 0; i < input; i++)
        {
            if (!strcmp(l[i].author_name, ch))
            {
                printf("|%10d         |", l[i].accession_number);
                printf("%31s|", l[i].author_name);
                printf("%31s|", l[i].title);
                (l[i].flag == 1) ? printf("       YES       |") : printf("        NO       |");
                printf("\n=======================================================================================================\n");
            }
        }
    }
    else
    {
        printf("NO BOOK AVAILABLE WITH AUTHOR NAME %s !!!\n", ch);
    }
}
void bookcount_title()
{
    char ch[30];
    int i, count = 0;
    printf("\nENTER THE TITLE OF BOOK:");
    gets(ch);
    for (i = 0; i < input; i++)
    {
        if (!strcmp(l[i].title, ch))
        {
            count++;
        }
    }
    if (count)
    {
        printf("\nNUMBER OF BOOKS OF TITLE [%s]: %d\n", ch, count);
    }
    else
    {
        printf("NO BOOK AVAILABLE WITH TITLE [%s] !!!\n", ch);
    }
}
void bookcount()
{
    printf("\nTOTAL NUMBER OF BOOK IN THE LIBRARY:%d\n", input);
}
void issue()
{
    int a, i, j, count = 0;
    printf("ENTER THE ACCESSION NUMBER OF BOOK:");
    scanf("%d", &a);
    for (i = 0; i < input; i++)
    {
        if (l[i].accession_number == a)
        {
            l[i].flag = 1;
            count = 1;
            printf("\nBOOK ISSUED\n");
            for (j = i; j < input - 1; j++)
            {
                l[i] = l[i + 1];
            }
        }
    }
    if (count)
    {
        input--;
    }
    else
    {
        printf("\nINVALID ACCESSION NUMBER!!!\nPLEASE ENTER CORRECT ACCESSION NUMBER\n");
    }
}


#include <windows.h>
#include <stdlib.h>
#include <conio.h>

void gotoxy(short a, short b) // Custom gotoxy() function for vs code not for turbo c
{
    COORD coordinates; // Data type of co-ordinates
    coordinates.X = a; // Assign value to X- Co-ordinate
    coordinates.Y = b; // Assign value to Y Co-ordinate

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void reset()
{
    printf("\033[0m");
}
void blinker()
{
    printf("\033[1;46m");
}
char rkey()
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();
    return c;
}
void menu(int ch)
{
    char m[7][65] = {"1 - DISPLAY ALL BOOK INFORMATION", "2 - ADD A NEW BOOK", "3 - DISPLAY ALL THE BOOKS IN THE LIBRARY OF A PARTICULAR AUTHOR", "4 - DISPLAY THE NUMBER OF BOOKS OF A PARTICULAR TITLE", "5 - DISPLAY THE TOTAL NUMBER OF BOOKS IN THE LIBRARY", "6 - ISSUE A BOOK", "7 - EXIT"};
    int i = 0;
    // clrscr();
    // system("cls");
    printf("\t\t\tMAIN MENU");
    while (i < 7)
    {
        if (ch == i + 1)
        {
            blinker();
            printf("\n");
            printf("%s", m[i]);
            reset();
        }
        else
        {
            printf("\n %s", m[i]);
        }
        i++;
    }
}
void work(int ch)
{
    switch (ch)
    {
    case 1:
        displayall();
        break;
    case 2:
        add();
        break;
    case 3:
        display_author();
        break;
    case 4:
        bookcount_title();
        break;
    case 5:
        bookcount();
        break;
    case 6:
        issue();
        break;
    case 7:
        exit(0);
    }
}
int main()
{
    int i = 1, ch;
    // clrscr();
    // system("cls");
    // printf("\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    // printf("\n\n\n=======================================================================================================================================================\n");
    while (1)
    {
        system("cls");
        gotoxy(35, 11);
        printf("\t\t\tLIBRARY MANAGEMENT SYSTEM");
        printf("\n\n=======================================================================================================================================================\n\n");
        menu(i);
        printf("\n");
        ch = rkey();
        printf("\n");
        switch (ch)
        {
        case 72:
            if (i != 1)
            {
                i--;
                system("cls");
                gotoxy(35, 11);
                printf("\t\t\tLIBRARY MANAGEMENT SYSTEM");
                printf("\n\n=======================================================================================================================================================\n\n");
                menu(i);
            }
            break;
        case 80:
            if (i != 7)
            {
                i++;
                system("cls");
                gotoxy(35, 11);
                printf("\t\t\tLIBRARY MANAGEMENT SYSTEM");
                printf("\n\n=======================================================================================================================================================\n\n");
                menu(i);
            }
            break;
        case 13: // ENTER
            if (i != 7)
            {
                work(i);
                // printf("\n");
                _getch();
                break;
            }
            exit(1);
        case 27: // ESCAPE
            exit(1);
        default:
            break;
        }
    }
}
