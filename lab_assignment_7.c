#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// this entry type will allow us to track all swaps properly
typedef struct Entry {
    int data;
    int swaps;
} entry;

// prototypes for both sort functions.
void BubbleSort(int array[]);
void SelectionSort(int array[]);

// prototype for the function we'll use for the output
void PrintSwapCounts(int array[], int swaps[], int total);

int main() {

    // arrays
    int array1[] = {97,16,45,63,13,22,7,58,72};
    int array2[] = {90,80,70,60,50,40,30,20,10};

    printf("array1 Bubble Sort:\n");
    BubbleSort(array1);
    printf("array2 Bubble Sort:\n");
    BubbleSort(array2);

    printf("array1 Selection Sort:\n");
    SelectionSort(array1);
    printf("array2 Selection Sort:\n");
    SelectionSort(array2);
    

}

//
void BubbleSort(int array[]) {

    int totalSwaps = 0;
    int swaps[9] = {0,0,0,0,0,0,0,0,0};

    int x, y, temp;
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8-x; y++) {
            // check if current entry is greater than next entry, if so, begin swapping procedure
            if (array[y] > array[y+1]) {
                // swap array itself
                temp = array[y];
                array[y] = array[y+1];
                array[y+1] = temp;
                
                // swap swap counter array, and add one for the incrementation
                temp = swaps[y];
                swaps[y] = swaps[y+1];
                swaps[y+1] = temp;
                swaps[y]++;
                swaps[y+1]++;
                
                // finally, increment total swap count
                totalSwaps++;
            }
        }
    }
    PrintSwapCounts(array, swaps, totalSwaps);
}

void SelectionSort(int array[]) {

    int totalSwaps = 0;
    int swaps[] = {0,0,0,0,0,0,0,0,0};

    int x, y, min, temp;
    for (x = 0; x < 8; x++) {
        // find the minimum unsorted value in the current array
        min = x;
        for (y = x+1; y < 9; y++) {
            if (array[y] < array[min]) {
                min = y;
            }
        }
        // swap the array elements themselves
        temp = array[x];
        array[x] = array[min];
        array[min] = temp;

        // swap the swap counter array and also increment them
        temp = swaps[x];
        swaps[x] = swaps[min];
        swaps[min] = temp;

        swaps[x]++;
        swaps[min]++;

        //finally, increment total size
        totalSwaps++;
    }


    PrintSwapCounts(array, swaps, totalSwaps);
}

// this simply prints the array after being sorted
void PrintSwapCounts(int array[], int swaps[], int total) {

    for (int i = 0; i < 9; i++) {
        printf("%d: %d\n", array[i], swaps[i]);
    }
    printf("%d\n\n", total);
}
