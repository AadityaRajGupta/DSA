#include <stdio.h>
int address_calculation_1(int a,int index,int lb,int n)
{
    // a = base address , i = index , n = No. of bytes , lb = Lower Bound
    return (a + (index-lb) * n);
}
int main()
{
    int index,base,byte,lb;
    printf("ENTER THE LOWER BOUND OF ARRAY:");
    scanf("%d",&lb);
    printf("ENTER THE BASE ADDRESS:");
    scanf("%d",&base);
    printf("ENTER THE POSITION TO CALCULATE ADDRESS [i]:");
    scanf("%d",&index);
    printf("ENTER THE NO. OF BYTES OF DATATYPE:");
    scanf("%d",&byte);
    printf("\nCALCULATED ADDRESS IN 1D ARRAY: %u\n",address_calculation_1(base,index,lb,byte));
    return 0;
}
/*
ENTER THE SIZE OF ARRAY:5
ENTER THE INDEX TO CALCULATE ADDRESS:1
CALCULATED ADDRESS:6422176
ADDRESS OF ARRAY (index:address):
 0 : 6422172   1 : 6422176   2 : 6422180   3 : 6422184   4 : 6422188 

PS D:\GIT_HUB\DSA\DATA STRUCTURE LAB> cd "d:\GIT_HUB\DSA\DATA STRUCTURE LAB\" ; if ($?) { gcc lab3_array13_address_computation_1D.c -o lab3_array13_address_computation_1D } ; if ($?) { .\lab3_array13_address_computation_1D }
ENTER THE LOWER BOUND OF ARRAY:0
ENTER THE BASE ADDRESS:6422172
ENTER THE INDEX TO CALCULATE ADDRESS:2
ENTER THE NO. OF BYTES OF DATATYPE:4

CALCULATED ADDRESS IN 1D ARRAY: 6422180
*/
