// header file for listStack.h file
#ifndef LIST_STACK_H
#define LIST_STACK_H
#include <iostream>

// create the class node
template <typename T>
class Node{
    public:
        T data; 
        Node<T> *next = nullptr;
};

// create a pointer/reference top that always points to the current top node of the stack

// global 
template <typename T>
Node<T>* head = nullptr;

// pushing operation:
template <typename T>
void push(T newData){
    // create a new node
    Node<T>* newNode = new Node<T>;
    // assign the data to the new node
    newNode->data = newData;
    // point the newNode next to the current top
    newNode->next = head<T>;
    // assign the new Top to the newNode
    head<T> = newNode;
}

// isEmpty() operation
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;

}

template <typename T>
T pop(){
    // if the stack is empty error catch:
    if(isEmpty<T>()){
        std::cout<<"Stack underflow" << std::endl;
    }

    // saving a current top node to a temporary variable
    Node<T>* temp = head<T>; 
    // store the data to a temp variable
    T tempVal = temp->data;
    // move the head to the next node
    head<T> = head<T>->next; 
    // free up the memory
    delete temp; 
    // return the temporary variable data
    return tempVal;
}

template <typename T>
void Top(){
    // what if the stack is empty??
    if(isEmpty<T>()) return;
    std::cout<<"The top is: " << head<T>->data<<std::endl;
}

// Display all
template <typename T>
void displayAll(){
    // checks immediately if the valued return is empty
    if(isEmpty<T>()) return;
    // store the head with temp
    Node<T> *temp = head<T>;

    while(head<T> != nullptr){
        std::cout<< head<T>->data<<" ";
        head<T> = head<T>->next;
    }
    // to check if the head doesn't change its value
    head<T> = temp;
    std::cout<<std::endl;
}
    
        
#endif