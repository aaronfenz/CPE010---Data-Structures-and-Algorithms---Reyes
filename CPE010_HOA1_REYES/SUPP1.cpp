#include <iostream>
// Swap two numbers in different variables
void swapNum(int &A, int &B);

int main(){
    int A = 10;
    int B = 20;
	std::cout << "=========================================\n";
    std::cout << "          VARIABLE SWAPPING TEST         \n";
    std::cout << "=========================================\n\n";
    std::cout << "Before Swapping:\n";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;

    swapNum(A,B);

    std::cout << "\nAfter Swapping:\n";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;

    return 0;
}

void swapNum(int &A, int &B){

    int temp;

    temp = A;
    A = B;
    B = temp;

}
