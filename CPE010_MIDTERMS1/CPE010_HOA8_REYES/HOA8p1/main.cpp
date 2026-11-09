#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

using namespace std;

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
    }

    cout << endl;
}


int main(){

    srand(time(0));

    const int SIZE = 100;

    int original[SIZE];
    int shellArray[SIZE];
    int mergeArray[SIZE];
    int quickArray[SIZE];


    // To Generate 100 random values
    for (int i = 0; i < SIZE; i++){
        original[i] = rand() % 1000 + 1;
    }


    // Copy the same original array for each sorting algorithm
    for (int i = 0; i < SIZE; i++){
        shellArray[i] = original[i];
        mergeArray[i] = original[i];
        quickArray[i] = original[i];
    }

    cout << "ARRAY OF VALUES FOR SORT ALGORITHM TESTING" << endl;
    cout << "Original 100 Random Values:" << endl;
    displayArray(original, SIZE);

    cout << "\nSHELL SORT TECHNIQUE" << endl;
    shellSort(shellArray, SIZE);
    cout << "Sorted Array using Shell Sort:" << endl;
    displayArray(shellArray, SIZE);

    cout << "\nMERGE SORT ALGORITHM" << endl;
    mergeSort(mergeArray, 0, SIZE - 1);
    cout << "Sorted Array using Merge Sort:" << endl;
    displayArray(mergeArray, SIZE);

    cout << "\nQUICK SORT ALGORITHM" << endl;
    quickSort(quickArray, 0, SIZE - 1);
    cout << "Sorted Array using Quick Sort:" << endl;
    displayArray(quickArray, SIZE);

    return 0;
}