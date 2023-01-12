/*
⁡⁢⁣⁢Operations	         peek	 insert	    delete⁡
⁡⁣⁣⁢Linked List⁡	      O(1)	  O(n)	     O(1)
⁡⁣⁣⁢Binary Heap⁡	      O(1)	  O(log n)	 O(log n)
⁡⁣⁣⁢Binary Search Tree⁡	  O(1)	  O(log n)	 O(log n)

*/

// Program for Heap Implementation of Priority Queue

#include <stdio.h>

int size = 0;   // array size globally access kar sakte hai
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

/*
/ max-heap
void heapify(int array[], int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
        largest = l;
    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
}
*/
// min-heap
void heapify(int array[], int size, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest])
        smallest = l;
    if (r < size && array[r] < array[smallest])
        smallest = r;
    
    if(smallest !=i)
    {
        swap(&array[i], &array[smallest]);
        heapify(array, size, smallest);
    }
}


// Function to insert an element into the tree
void insert(int array[], int newNum)
{
    if (size == 0)
    {
        array[0] = newNum;
        size += 1;
    }
    else
    {
        array[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(array, size, i);
    }
}

// Function to delete an element from the tree
void deleteRoot(int array[], int num)
{
    int i;
    for (i = 0; i < size; i++)
        if (num == array[i])
            break;

    swap(&array[i], &array[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
}

// Print the array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int array[10];        // maximum kitne element insert kar sakte hai

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Max-Heap array: ");
    printArray(array, size);

    deleteRoot(array, array[0]);

    printf("\nAfter deleting an element: ");
    printArray(array, size);
}