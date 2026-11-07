#include <iostream>
#include "searchingAlgo(1).h"

int main() {

    // ==================================================
    // Problem 1 - Sequential Search
    // ==================================================

    int list[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    int size = 10;
    int key = 18;

    std::cout << "============================================\n";
    std::cout << "Problem 1 - Sequential Search\n";
    std::cout << "============================================\n";

    std::cout << "List: ";

    // display the given list
    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }

    std::cout << "\nKey: " << key << "\n\n";


    // search for the key using an array
    int arrayComparisons =
        sequentialSearchArray(list, size, key);

    // create a linked list using the same values
    Node<int>* head = new Node<int>(list[0]);
    Node<int>* current = head;

    // connect each node to the next one
    for (int i = 1; i < size; i++) {
        current->next = new Node<int>(list[i]);
        current = current->next;
    }

    // search for the key using the linked list
    int linkedListComparisons =
        sequentialSearchLinkedList(head, key);

    std::cout << "Array comparisons: "
              << arrayComparisons << std::endl;

    std::cout << "Linked List comparisons: "
              << linkedListComparisons << std::endl;

    // ==================================================
    // Problem 2 - Count Repeating Instances
    // ==================================================
    std::cout << "\n============================================\n";
    std::cout << "Problem 2 - Count Repeating Instances\n";
    std::cout << "============================================\n";
    std::cout << "List: ";

    // display the list
    for (int i = 0; i < size; i++) {
        std::cout << list[i] << " ";
    }

    std::cout << "\nSearch element: " << key << std::endl;

    // count every time the key appears
    int occurrences =
        countOccurrences(list, size, key);

    std::cout << "Number of occurrences of "
              << key << ": "
              << occurrences << std::endl;

    // ==================================================
    // Problem 3 - Iterative Binary Search
    // ==================================================
    std::cout << "\n============================================\n";
    std::cout << "Problem 3 - Iterative Binary Search\n";
    std::cout << "============================================\n";

    // binary search needs a sorted list
    int sortedList[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int sortedSize = 10;
    int binaryKey = 8;

    std::cout << "List: ";

    for (int i = 0; i < sortedSize; i++) {
        std::cout << sortedList[i] << " ";
    }

    std::cout << "\nSearching for: "
              << binaryKey << "\n\n";

    // perform the iterative binary search
    int result =
        binarySearch(sortedList, sortedSize,binaryKey);


    if (result != -1) {
        std::cout << "\nSearching is Successful\n";
        std::cout << "Element found at index "
                  << result << std::endl;
    }else {
        std::cout << "\nSearching is Unsuccessful\n";
    }

    // ==================================================
    // Problem 4 - Recursive Binary Search
    // ==================================================
    std::cout << "\n============================================\n";
    std::cout << "Problem 4 - Recursive Binary Search\n";
    std::cout << "============================================\n";

    std::cout << "List: ";

    for (int i = 0; i < sortedSize; i++) {
        std::cout << sortedList[i] << " ";
    }

    std::cout << "\nSearching for: "
              << binaryKey << "\n\n";

    // start the recursive search at the first and last index
    int iteration = 1;

    int recursiveResult =
        recursiveBinarySearch(sortedList, 0, sortedSize - 1, binaryKey, iteration);

    if (recursiveResult != -1) {
        std::cout << "\nSearching is Successful\n";
        std::cout << "Element found at index "
                  << recursiveResult << std::endl;
    }else {
        std::cout << "\nSearching is Unsuccessful\n";
    }

    return 0;
}