#include <stdio.h>
// lower and upper bound both included it is decided by us to enter it or not,as Q may give as 5 X 5 matrix but their bound will be 0:4 so this value should be entered

int address_calculation_3_row(int a, int i, int j, int k, int n, int lbr, int ubr, int lbc, int ubc, int lbw, int ubw)
{
    // a = base address , i = index , n = No. of bytes , lbr = Lower Bound OF ROW , upr = Upper Bound of Row ,
    // lbc = Lower Bound of column , ubc = Upper bound of Column
    // lbw = Lower Bound of width , ubw = Upper bound of width
    return (a + ( (i-lbr)*(ubc-lbc+1)*(ubw-lbw+1) + (j-lbc)*(ubw-lbw+1) + (k-lbw) ) * n);
}
int address_calculation_3_column(int a, int i, int j, int k, int n, int lbr, int ubr, int lbc, int ubc, int lbw, int ubw)
{
    return (a + ( (j-lbc)*(ubr-lbr+1)*(ubw-lbw+1) + (k-lbw)*(ubw-lbw+1) + (i-lbr) ) * n);
}
int main()
{
    int i,j,k,base,byte,lbr,lbc,ubr,ubc,lbw,ubw;
    printf("ENTER THE ROW LOWER BOUND OF ARRAY:");
    scanf("%d",&lbr);
    printf("ENTER THE ROW UPPER BOUND OF ARRAY:");
    scanf("%d",&ubr);

    printf("ENTER THE COLUMN LOWER BOUND OF ARRAY:");
    scanf("%d",&lbc);
    printf("ENTER THE COLUMN UPPER BOUND OF ARRAY:");
    scanf("%d",&ubc);

    printf("ENTER THE WIDTH LOWER BOUND OF ARRAY:");
    scanf("%d",&lbw);
    printf("ENTER THE WIDTH UPPER BOUND OF ARRAY:");
    scanf("%d",&ubw);

    printf("ENTER THE BASE ADDRESS:");
    scanf("%u",&base);
    printf("ENTER THE POSITION TO CALCULATE ADDRESS [i][j][k]:");
    scanf("%d%d%d",&i,&j,&k);
    printf("ENTER THE NO. OF BYTES OF DATATYPE:");
    scanf("%d",&byte);

    printf("\nCALCULATED ADDRESS IN 3D ARRAY ROW WISE: %u\n",address_calculation_3_row(base,i,j,k,byte,lbr,ubr,lbc,ubc,lbw,ubw));
    printf("\nCALCULATED ADDRESS IN 3D ARRAY COLUMN WISE: %u\n\n",address_calculation_3_column(base,i,j,k,byte,lbr,ubr,lbc,ubc,lbw,ubw));

    /* int a[3][3][3] = {0}, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("[%d][%d][%d]: %7u  ", i+1, j+1, k+1, &a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    } */
    return 0;
}