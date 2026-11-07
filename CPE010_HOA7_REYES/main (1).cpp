#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int max_size = 100;

int main() {
    int testArray[max_size];

    // Separate arrays for each sorting algorithm
    int bubbleArray[max_size];
    int selectionArray[max_size];
    int insertionArray[max_size];
    srand(time(0));

    // Fill the array with 100 random numbers
    for (int i = 0; i < max_size; i++) {

        testArray[i] = rand() % 100 + 1;
        // Copy original values to each sorting array
        bubbleArray[i] = testArray[i];
        selectionArray[i] = testArray[i];
        insertionArray[i] = testArray[i];
    }

    // Display original array
    std::cout << "Array elements:\n";
    displayArray(testArray, max_size);


    // Bubble Sort
    std::cout << "\nSorting the array using Bubble Sort\n";
    bubbleSort(bubbleArray, max_size);
    displayArray(bubbleArray, max_size);


    // Selection Sort
    std::cout << "\nSorting the array using Selection Sort\n";
    selectionSort(selectionArray, max_size);
    displayArray(selectionArray, max_size);


    // Insertion Sort
    std::cout << "\nSorting the array using Insertion Sort\n";
    insertionSort(insertionArray, max_size);
    displayArray(insertionArray, max_size);

    return 0;
}