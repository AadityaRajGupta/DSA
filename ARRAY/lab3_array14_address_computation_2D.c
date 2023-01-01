#include <stdio.h>
int address_calculation_2_row(int a,int i,int j,int n,int lbr,int ubr,int lbc,int ubc)
{
    // a = base address , i = index , n = No. of bytes , lbr = Lower Bound OF ROW , upr = Upper Bound of Row ,
    // lbc = Lower Bound of column , ubc = Upper bound of Column
    return (a + ( (i-lbr)*(ubc-lbc+1) + (j-lbc) ) * n);
}
int address_calculation_2_column(int a,int i,int j,int n,int lbr,int ubr,int lbc,int ubc)
{
    return (a + ( (j-lbc)*(ubr-lbr+1) + (i-lbr) ) * n);
}
int main()
{
    int i,j,base,byte,lbr,lbc,ubr,ubc;
    printf("ENTER THE ROW LOWER BOUND OF ARRAY:");
    scanf("%d",&lbr);
    printf("ENTER THE ROW UPPER BOUND OF ARRAY:");
    scanf("%d",&ubr);

    printf("ENTER THE COLUMN LOWER BOUND OF ARRAY:");
    scanf("%d",&lbc);
    printf("ENTER THE COLUMN UPPER BOUND OF ARRAY:");
    scanf("%d",&ubc);

    printf("ENTER THE BASE ADDRESS:");
    scanf("%u",&base);
    printf("ENTER THE POSITION TO CALCULATE ADDRESS [i][j]:");
    scanf("%d%d",&i,&j);
    printf("ENTER THE NO. OF BYTES OF DATATYPE:");
    scanf("%d",&byte);

    printf("\nCALCULATED ADDRESS IN 2D ARRAY ROW WISE: %u\n",address_calculation_2_row(base,i,j,byte,lbr,ubr,lbc,ubc));
    printf("\nCALCULATED ADDRESS IN 2D ARRAY COLUMN WISE: %u\n\n",address_calculation_2_column(base,i,j,byte,lbr,ubr,lbc,ubc));
/* 
    int a[3][3]={0},i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("[%d][%d]: %7u  ",i,j,&a[i][j]);
        }
        printf("\n");        
    } */
    return 0;
}