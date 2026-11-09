#include <iostream>
#include "simply_LL.h"

int main(){
    
    // Creating an empty list
    SimplyList<char>* head = new SimplyList<char>;
    SimplyList<char>* second = new SimplyList<char>;
    SimplyList<char>* third = new SimplyList<char>;
    SimplyList<char>* fourth = new SimplyList<char>;
    SimplyList<char>* fifth = new SimplyList<char>;

    // Assign the data:
    head->data = 'F';
    head->next = second;

    second->data = 'E';
    second->next = third;

    third->data = 'N';
    third->next = fourth;

    fourth->data = 'Z';
    fourth->next = nullptr;


    std::cout<<"original list:"<<std::endl;
    listTraversal(head);

    std::cout<<"inserting a new node at the head: \n";
    sllinsertHead('Q',&head);
    listTraversal(head);

    std::cout<<"inserting a new node at the third: \n";
    sllGeneralInsert('X', head->next->next);
    listTraversal(head);

    std::cout<<"inserting a new node at the END: \n";
    sllinsertEnd('U', &head);
    listTraversal(head);

    std::cout<<"Deleting a node: \n";
    sllDeleteNode('X', &head);
    listTraversal(head);
    
    std::cout<<"Deleting the head node: \n";
    sllDeleteNode('Q', &head);
    listTraversal(head);
    
    std::cout<<"Deleting all the nodes: \n";
    sllDeleteList(&head);
    listTraversal(head);



    return 0;
}                  