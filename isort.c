#include <stdio.h>

#define ARR_LEN 50

void shift_element(int* arr, int i);
void insertion_sort(int* arr , int len);

// Note - this function asume that there is enough free memory for i+1 cells after the pointer parameter
void shift_element(int* arr, int i)
{
    // we want to shift to the right by one, amount of i elements from the address that the pointer holds.

    for (int j = i + 1; j >= 2; j--)
    {
        *(arr + j) = *(arr + (j - 1)); // With this implementation there is no need to use temporary variants.
    }

}

void insertion_sort(int* arr , int len)
{
    int i, j, current_element, counter = 0;

    for (i = 1; i < len; i++) // Iterate from arr[1] to arr[len] over the array
    {
        current_element = *(arr + i);  // At every iteration there is a new element to compare with it predeccesors

        j = i - 1; // Start comparing with i-1, and going down till arr[0]

        while (j >= 0 && *(arr + j) > current_element)
        {
            counter++; // Count how many elements we need to shift 
            
            j--;
        }

        /* 
            By using "shift_element", we're shifting (by one) all elements of arr[0..i-1] that are
            greater than current_element.
        */

        shift_element(arr + j, counter); // 'arr + j' give us the address that we start to move the next element.

        *(arr + (j + 1)) = current_element; // After comparing and finding "current_element" correct place, we put it there.

        counter = 0; // reset counter for next iteration
    }
}

int main() 
{
    // Create array:
    int arr[ARR_LEN];

    // get 50 numbers from user:
    for (int i = 0; i < ARR_LEN; i++)
    {
        scanf("%d,", &arr[i]);
    }

    // Sort the array with insertion sort:
    insertion_sort(arr, sizeof(arr)/sizeof(*arr));

    // Print the sorted array:
    for (int i = 0; i < ARR_LEN - 1; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("%d\n", arr[ARR_LEN - 1]); // In order to unprint ',' after the last number
    
    return 0;
}
