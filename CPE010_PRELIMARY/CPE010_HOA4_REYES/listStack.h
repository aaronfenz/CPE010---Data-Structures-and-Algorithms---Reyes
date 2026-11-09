#ifndef LISTSTACK_H
#define LISTSTACK_H

#include <iostream>

// creeate a node for the linked list
template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
};

// create the top pointer of the stack
template <typename T>
Node<T>* top = nullptr;

// check if the stack is empty
template <typename T>
bool isEmpty(){
    return top<T> == nullptr;
}

// push a new element onto the stack
template <typename T>
void push(T value){

    // create a new node
    Node<T>* newNode = new Node<T>;

    // store the data
    newNode->data = value;
    // link the new node to the current top
    newNode->next = top<T>;

    // make the new node the top
    top<T> = newNode;
}

// pop the top element from the stack
template <typename T>
T pop(){

    // check if the stack is empty
    if(isEmpty<T>())
        return '\0';


    // store the current top node
    Node<T>* temp = top<T>;

    // save the data before deleting
    T value = temp->data;

    // move the the top to the next node
    top<T> = top<T>->next;

    // delete the old top node
    delete temp;

    // return the removed value
    return value;
}

#endif