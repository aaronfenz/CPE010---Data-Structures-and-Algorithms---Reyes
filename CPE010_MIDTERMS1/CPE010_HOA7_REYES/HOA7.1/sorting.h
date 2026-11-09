#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <utility>


// DISPLAYING ALL ARRAY ELEMENTS
void displayArray(const int values[], int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << values[i] << " ";
        // Move to the next line after every 10 elements
        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
}


// BUBBLE SORTING
template <typename T>
void bubbleSort(T arr[], size_t maxSize) {
    for (int i = 0; i < maxSize - 1; i++) {
        for (int j = i + 1; j < maxSize; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}


// FIND THE POSITION OF THE SMALLEST ELEMENT
template <typename T>
int routine_smallest(T arr[], int k, const int maxSize) {
    int position;
    position = k;
    // Find the smallest element
    for (int j = k + 1; j < maxSize; j++) {
        if (arr[j] < arr[position]) {
            position = j;
        }
    }
    // Return the position of the smallest element
    return position;
}


// SELECTION SORTING
template <typename T>
void selectionSort(T arr[], int maxSize) {
    int minVal;
    for (int i = 0; i < maxSize - 1; i++) {
        minVal = routine_smallest(arr, i, maxSize);
        std::swap(arr[i], arr[minVal]);
    }
}


// INSERTION SORTING
template <typename T>
void insertionSort(T arr[], int maxSize) {
    int k, j;
    T temp;
    // Swapping, cannot use std::swap
    k = 1;
    while (k < maxSize) {
        temp = arr[k];
        j = k - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--; // Backtracking part
        }
        // Reassigning values and moving to next element
        arr[j + 1] = temp;
        k++;
    }
}

#endif