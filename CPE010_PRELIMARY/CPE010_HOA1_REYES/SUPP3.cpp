#include <iostream>
#include <cmath>

// Calculate the distance between two points

double distance(double x1, double y1, double x2, double y2);

int main(){

    double x1, y1, x2, y2;
    
	std::cout << "===================" << std::endl;
	std::cout << "DISTANCE CALCULATOR" << std::endl;
	std::cout << "===================" << std::endl;
		
    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << "Enter y1: ";
    std::cin >> y1;

    std::cout << "Enter x2: ";
    std::cin >> x2;

    std::cout << "Enter y2: ";
    std::cin >> y2;

	std::cout << "===================" << std::endl;
    std::cout << "Distance: "
              << distance(x1,y1,x2,y2) << std::endl;

    return 0;
}

double distance(double x1, double y1, double x2, double y2){

    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));

}
