#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H


#include <iostream>


template <typename T>
class QueueArr {
private:
    T* q_array;          // pointer to array
    size_t q_capacity;   // max capacity
    size_t q_size;       // current size
    int q_front;         // index of front
    int q_back;          // index of back


public:
    // Constructor
    QueueArr(size_t capacity);
    ~QueueArr();
    
    bool Empty();
    bool Full();


    size_t Size();
   
    void Clear();


    T Front();
    T Back();


    void Enqueue(T newData);
    void Dequeue();


    QueueArr(const QueueArr& other); // Copy Constructor
    QueueArr& operator=(const QueueArr& other); // Copy Assignment Operator
};


// Constructor
template <typename T>
QueueArr<T>::QueueArr(size_t capacity) {
    // Define the capacity of the array
    q_capacity = capacity;
    // Set the size to 0
    q_size = 0;
    // Set the front and back to 0 and -1 respectively
    q_front = 0;
    q_back = -1;
    // Allocate a new space for the array
    q_array = new T[q_capacity];
}


// Destructor
template <typename T>
QueueArr<T>::~QueueArr() {
    delete[] q_array;
    std::cout << "Destructor was Called" << std::endl;
}


// Is Empty
template <typename T>
bool QueueArr<T>::Empty() {
    return q_size == 0;
}


// Is Full
template <typename T>
bool QueueArr<T>::Full() {
    return q_size == q_capacity;
}


// Return size
template <typename T>
size_t QueueArr<T>::Size() {
    return q_size;
}


// Clear Queue
template <typename T>
void QueueArr<T>::Clear() {
    // Queue size set to 0
    q_size = 0;
    // Restores the front and back to their initial values
    q_front = 0;
    q_back = -1;
    return;
}


// Get front element
template <typename T>
T QueueArr<T>::Front() {
    // Check if the queue is empty
    if (Empty()){
        return T(); // Return default value of T if empty
    }
    
    // Return the front element
    return q_array[q_front];
}


// Get back element
template <typename T>
T QueueArr<T>::Back() {
    // Check if the queue is empty
    if (Empty()){
        return T(); // Return default value of T if empty
    }
    return q_array[q_back];
}


// Enqueueing Function
template <typename T>   
void QueueArr<T>::Enqueue(T newData) {
    // Check if the queue is full
    if (Full()) {
        std::cout << "Queue is full!" << std::endl; 
        return;
    }
    // Increment the back index (rear) in a circular manner
    q_back = (q_back + 1) % q_capacity;
    // Add the new value to the back of the queue
    q_array[q_back] = newData;
    // Increment the size of the queue
    q_size++;
}


// Dequeueing Function
template <typename T>   
void QueueArr<T>::Dequeue() {
    // Check if the queue is empty
    if (Empty()) {
        std::cout << "Queue is empty!" << std::endl; 
        return;
    }
    // Increment the front index (front) in a circular manner
    q_front = (q_front + 1) % q_capacity;
    // Decrement the size of the queue
    q_size--;
    // When the queue is empty...
    if (q_size == 0) {
        Clear(); // Reset the queue to its initial state
        return;
    }
}


// Copy Constructor
template <typename T>  
QueueArr<T>::QueueArr(const QueueArr& other) {
    // Copy the capacity and size from the other queue
    q_capacity = other.q_capacity;
    q_size = other.q_size;
    // Copy the front and back indices
    q_front = other.q_front;
    q_back = other.q_back;
    // Allocate new memory for the array and copy the elements
    q_array = new T[q_capacity];
    for (size_t i = 0; i < q_capacity; ++i) {
        q_array[i] = other.q_array[i];
    }
}


// Copy Assignment Operator
template <typename T>   
QueueArr<T>& QueueArr<T>::operator=(const QueueArr& other) {
    // Check for self-assignment
    if (this != &other) {
        // Delete the existing array
        delete[] q_array;
        // Copy the capacity and size from the other queue
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        // Copy the front and back indices
        q_front = other.q_front;
        q_back = other.q_back;
        // Allocate new memory for the array and copy the elements
        q_array = new T[q_capacity];
        for (size_t i = 0; i < q_capacity; ++i) {
            q_array[i] = other.q_array[i];
        }
    }
    return *this; // Return the current object
}


#endif