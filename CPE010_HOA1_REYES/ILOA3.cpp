#include <iostream>

// Create a function that will take two Boolean values and display the result of all 
// logical operations then return true if it was a success.

bool logicalOperation(bool A, bool B);

int main(){

    if(logicalOperation(true,false)){
        std::cout << "Logical operations completed successfully.";
    }

    return 0;
}

bool logicalOperation(bool A, bool B){

    std::cout << "A AND B: " << (A && B) << std::endl;
    std::cout << "A OR B: " << (A || B) << std::endl;
    std::cout << "NOT A: " << (!A) << std::endl;
    std::cout << "NOT B: " << (!B) << std::endl;

    return true;

}
