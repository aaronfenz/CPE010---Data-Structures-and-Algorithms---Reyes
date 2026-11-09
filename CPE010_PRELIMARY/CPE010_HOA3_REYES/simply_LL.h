#ifndef SIMPLY_LL_H
#define SIMPLY_LL_H

#include <iostream>

template <typename T>
class SimplyList{
    public:
        T data;
        SimplyList<T> *next = nullptr;
};

//Traversal
template <typename T>
void listTraversal(SimplyList<T>* head){
    if (head==nullptr){
        std::cout<<"List is empty!"<<std::endl;
        return;
    }
    
    while(head != nullptr){
        std::cout<<head->data;
        if (head->next != nullptr){
            std::cout<<"->";
        }

        head = head->next;
    }
    std::cout<<std::endl;
}

/*
1. Allocate memory for the new code
2. Put our data into the new node
3. Set Next of the new node to point to the previous Head
4. Reset Head to point to the new node
*/

template <typename T>
void sllinsertHead(T newData, SimplyList<T>** currentHead){
    // 1. Allocate memory for the new code
    SimplyList<T>* newNode = new SimplyList<T>;
    // 2. Put our data into the new node
    newNode->data = newData;
    // 3. Set Next of the new node to point to the previous Head
    newNode->next = *currentHead;
    // 4. Reset Head to point to the new node
    *currentHead = newNode;

}
/*
2. If null, print

*/
template <typename T>
void sllGeneralInsert(T newData, SimplyList<T>* prevNode){
    // 2. If null, print "Previous node cannot be null."
    if(prevNode == nullptr){
        std::cout<<"Previous Node cannot be Null" <<std::endl;
        return;
    }
    //3. Allocate a new node
    SimplyList<T>* newNode = new SimplyList<T>;

    //4. Store data in the new node
    newNode->data = newData;

    //5. Point new node to the node previous node pointing to
    newNode->next = prevNode->next;

    //6. Point previous node to the new code
    prevNode->next = newNode;
}

template<typename T>
void sllinsertEnd(T newData, SimplyList<T>** head){
    //1. Allocate new node
    SimplyList<T>* newNode = new SimplyList<T>;
    // 2. Dereference to the head node
    SimplyList<T>* currentNode = *head;
    //3. Store data in new node
    newNode->data = newData;
    // 4. Point next of new node to NULL
    newNode->next = nullptr;
    // 5. Traverse the list until next of the node is null
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    // 6. Point the next of the current node to the new node
    currentNode->next = newNode;

}

template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head){
    // check if there is no list to be deleted.
    if(*head ==nullptr) return;

    SimplyList<T>* currNode =*head;
    SimplyList<T>* prevNode = nullptr;
    
    // searching loop
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    // data was not found:
    if (currNode == nullptr) return;

    // what if the node to be deleted is the head node
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }

    // we have to delete the node?
    delete currNode;


}

template <typename T>
void sllDeleteList(SimplyList<T>** head){
    SimplyList<T>* current = *head;

    while(current != nullptr){
        SimplyList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}


/*
1. Find the previous node of the node to be deleted.
2. Change the next of previous node.
3. Free memory for the to be deleted.
*/
#endif