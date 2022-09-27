// C++. program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
#define R 4
#define C 4
 
// Function for printing matrix in spiral
// form i, j: Start index of matrix, row
// and column respectively m, n: End index
// of matrix row and column respectively
void print(int arr[R][C], int i, int j, int m, int n)
{
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;
 
    // Print First Row
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";
 
    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";
 
    // Print Last Row, if Last and
    // First Row are not same
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";
 
    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";
 
    print(arr, i + 1, j + 1, m - 1, n - 1);
}
 
// Driver Code
int main()
{
    int a[R][C] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };
 
    // Function Call
    print(a, 0, 0, R, C);
    return 0;
}
// This Code is contributed by Ankur Goel

#include <stdio.h>

int main() {
    int i,j,rl=0,ru=3,cl=0,cu=3;
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for (i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
          printf(" %d ",arr[i][j]);
      }
      printf("\n");
    }
    
    printf("\n\n");
  while(rl!=ru && cl!=cu)
  {
    for(j=cl;j<=cu;j++)
      {
        printf("%d ",arr[rl][j]);
      }
  rl++;
  for(i=rl;i<=ru;i++)
    {
      printf("%d ",arr[i][cu]);
    }
  cu--;
  for(j=cu;j>=cl;j--)
    {
      printf("%d ",arr[ru][j]);
    }
  ru--;
  for(j=ru;j<=rl;i++)
    {
      printf("%d ",arr[rl][j]);
    }
  }
    return 0;
}
  

while (k < m && l < n) {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i) {
            printf("%d ", a[k][i]);
        }
        k++;
 
        /* Print the last column from the remaining columns
         */
        for (i = k; i < m; ++i) {
            printf("%d ", a[i][n - 1]);
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                printf("%d ", a[m - 1][i]);
            }
            m--;
        }
 
        /* Print the first column from the remaining columns
         */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                printf("%d ", a[i][l]);
            }
            l++;
        }
    }

