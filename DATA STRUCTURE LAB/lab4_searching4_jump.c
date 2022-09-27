#include <stdio.h>
#include <math.h>
void print(int a[], int size)
{
    printf("\nARRAY ELEMENT:\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}
int initialization(int a[])
{
    int size;
    printf("\nENTER THE SIZE OF ARRAY:");
    scanf("%d", &size);
    printf("ENTER ELEMENTS:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    return size;
}
int min(int a, int b){
	if(b>a)
	return a;
	else
	return b;
}
int jump_searching(int arr[], int x, int n)
{
	int step = sqrt(n);

	int prev = 0;
	while (arr[min(step, n)-1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	while (arr[prev] < x)
	{
		prev++;
		if (prev == min(step, n))
			return -1;
	}

	if (arr[prev] == x)
		return prev;

	return -1;
}
int main()
{
    int a[5], size;
    size = initialization(a);
    print(a, size);

    int index = jump_searching(a, 5, size);
	if(index >= 0)
	printf("Number is at [%d] index",index);
	else
	printf("Number is not exist in the array");

    return 0;
}