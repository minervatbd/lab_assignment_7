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

// prototype for entry array creation function
entry* CreateEntryArray(int array[]);

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
    printf("array1 Selection Sort:\n");
    SelectionSort(array2);
    

}

//
void BubbleSort(int array[]) {

    int totalSwaps = 0;
    int swaps[9];

    entry* swapsCounts = CreateEntryArray(array);

    

    PrintSwapCounts(array, swaps, totalSwaps);
}

void SelectionSort(int array[]) {

    int totalSwaps = 0;
    int swaps[9];

    entry* swapsCounts = CreateEntryArray(array);





    PrintSwapCounts(array, swaps, totalSwaps);
}

// this simply prints the array after being sorted
void PrintSwapCounts(int array[], int swaps[], int total) {

    for (int i = 0; 0 < 9; i++) {
        printf("%d: %d\n", array[i], swaps[i]);
    }
    printf("%d\n\n", total);
}

// function for entry array creation
entry* CreateEntryArray(int array[]) {
    entry* newArray = malloc(sizeof(entry)*9);
    for (int i = 0; i < 9; i++) {
        newArray[i].data = array[i];
        newArray[i].swaps = 0;
    }
    return newArray;
}