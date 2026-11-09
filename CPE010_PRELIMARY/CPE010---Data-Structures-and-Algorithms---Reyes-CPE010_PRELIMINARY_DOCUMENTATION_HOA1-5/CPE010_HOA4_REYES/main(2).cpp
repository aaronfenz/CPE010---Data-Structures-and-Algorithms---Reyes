// main file
#include <iostream>
#include "listStack.h"

int main(){
    std::cout<<"===== Pushing 'I' 'E' 'E' 'E' =====\n" <<std::endl;

    // pushing
    push('I');
    push('E');
    push('E');
    push('E');

    // display top
    Top<char>();

    // display all the values within these
    std::cout<<"Display All Values: ";
    displayAll<char>();


    // pop and print each element
    std::cout<<"\n===== Pushing 'E' 'E' 'E' 'I' =====\n";
    while(!isEmpty<char>()){
        std::cout<<"Popping: " <<pop<char>()<<std::endl;
    }

    // test stack underflow
    std::cout<< " " << std::endl;
    pop<char>();

}