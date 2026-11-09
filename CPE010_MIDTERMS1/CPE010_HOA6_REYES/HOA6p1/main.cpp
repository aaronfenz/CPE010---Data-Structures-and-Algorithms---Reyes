#include <iostream>
#include <cstdlib> // for generating random integers
#include <time.h> // will be used for our seeding function
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50; 

int main(){

    // Generate a random number between 1 and 50
    int dataset[max_size];
    srand(time(0)); //seed the random number generator
    for(int i = 0; i < max_size; i++){
        dataset[i] = rand(); //random number between 1 and 50
    }
    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    int userInput;
    std::cout << "What number to search?";
    std::cin >> userInput;
    std::cout << "============================================" << std::endl;
    std::cout << "Array result LS: ";
    linearSearchArr(dataset, max_size, userInput); //search for the entered number in the dataset
    std::cout << "Array result BS: ";
    binarySearchArr(dataset, max_size, userInput); //search for the entered number in the dataset
    std::cout << "--------------------------------------------" << std::endl;

    // Create a linked list
    Node<char>* name1 = newNode('F');
    Node<char>* name2 = newNode('E');
    Node<char>* name3 = newNode('N');
    Node<char>* name4 = newNode('Z');
    Node<char>* name5 = newNode('I');
    Node<char>* name6 = newNode('E');

    // Create the Name
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;

    // Demonstration
    std::cout << "============================================" << std::endl;
    std::cout << "Linked List result LS: ";
    linearSearchLL(name1, 'R');
    linearSearchLL(name1, 'r');
    std::cout << "Linked List result LS: ";
    binarySearchLL(name1, 'R');
    binarySearchLL(name1, 'r');
    std::cout << "--------------------------------------------" << std::endl;

    return 0;
}