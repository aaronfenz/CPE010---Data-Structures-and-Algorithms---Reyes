
#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <utility>
#include <cstddef>

// DISPLAYING ALL ARRAY ELEMENTS
void displayArray(const int values[], int maxSize) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << values[i] << " ";

        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
}

// BUBBLE SORTING
template <typename T>
void bubbleSort(T arr[], size_t maxSize) {
    for (size_t i = 0; i < maxSize - 1; i++) {
        bool swapped = false;

        for (size_t j = 0; j < maxSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

// FIND THE POSITION OF THE SMALLEST ELEMENT
template <typename T>
int routine_smallest(T arr[], int k, const int maxSize) {
    int position = k;

    for (int j = k + 1; j < maxSize; j++) {
        if (arr[j] < arr[position]) {
            position = j;
        }
    }

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
    int k = 1, j;
    T temp;

    while (k < maxSize) {
        temp = arr[k];
        j = k - 1;

        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
        k++;
    }
}

#endif
