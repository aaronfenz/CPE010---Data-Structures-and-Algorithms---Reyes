#include <iostream>

// Create a function that will take two numbers and display the sum.

int sumOfTwoNum(int fNum, int sNum);
void sumOfThreeNum(int fNum, int sNum, int tNum);

int main(){

    std::cout<<"The sum of the two numbers is: " << sumOfTwoNum(6,7)<<std::endl;
    sumOfThreeNum(6,7,8);        
}
int	sumOfTwoNum(int fNum, int sNum){
	
	int sum = fNum + sNum;
		
		return sum;
}

void sumOfThreeNum(int fNum, int sNum, int tNum){
    
    std::cout<< "Sum: " << fNum+sNum+tNum << std::endl;
}
