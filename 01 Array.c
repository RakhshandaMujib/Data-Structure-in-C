#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int read_array(int *arr); //Reads an array of <= MAX elements. Returns the size of the array.
void print_array(int *arr, int size); //Prints the content of the array.
void swap(int *left, int *right); //Swaps the contents of left and right.
void reverse_array(int *arr, int size); //Reverses the content of the array.

int main()
{
    int arr[MAX], size;

    size = read_array(arr);
    printf("Contents of the array:\n");
    print_array(arr, size);

    reverse_array(arr, size);
    printf("Reversed array:\n");
    print_array(arr, size);

    return 0;
}

int read_array(int *arr)
{
    int i, n;

    printf("Enter the number of elements you want:\n");
      scanf("%d", &n);
    printf("\nEnter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    return n;
}

void print_array(int *arr, int size)
{
    int i;

    for(i = 0; i < size; i++)
        printf("\t%d ", arr[i]);
    printf("\n");
}

void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

void reverse_array(int *arr, int size)
{
    int left, middle, right;
    middle = size / 2;
    right = size - 1;

    for(left = 0; left <= middle-1; left++)
    {
        swap(&arr[left], &arr[right]);
        right--;
    }
}
