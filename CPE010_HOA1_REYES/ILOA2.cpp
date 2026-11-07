#include <iostream>

// Create a function that will return whether variable A is greater than variable B.

bool compareNum(int A, int B);

int main(){
	
    if(compareNum(100,50)){
        std::cout << "Variable A is greater than Variable B.";
    }
    else{
        std::cout << "Variable A is NOT greater than Variable B.";
    }

    return 0;
}

bool compareNum(int A, int B){

    return A > B;

}
