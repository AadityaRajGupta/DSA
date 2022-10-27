#include <stdio.h>
/*
Time Complexity: O(2^n)
Auxiliary Space: O(n)
TOTAL MOVES: (2^n - 1) */
int TOH(int n, char a, char b, char c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        printf("MOVE DISK %d from %c to %c\n", n, a, c);
        TOH(n - 1, b, a, c);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    // printf("ENTER NUMBER OF DISKS:");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
    return 0;
}