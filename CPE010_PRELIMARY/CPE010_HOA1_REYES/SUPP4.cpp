#include <iostream>
#include <cmath>

class Triangle{

private:
    double totalAngle, angleA, angleB, angleC;
    double sideA, sideB, sideC;

public:
    // Constructor
    Triangle(double A, double B, double C,
             double sA, double sB, double sC);

    void setAngles(double A, double B, double C);

    // Triangle validation
    bool validateTriangle();

    // a. Function to compute for the area of a triangle
    double areaTriangle();

    // b. Function to compute for the perimeter of a triangle
    double perimeterTriangle();

    // c. Function that determines whether the triangle is acute-angled, obtuse-angled, or others
    void triangleType();

};

int main(){

    double angleA, angleB, angleC;
    double sideA, sideB, sideC;

    std::cout << "========== TRIANGLE INFORMATION ==========\n";

    std::cout << "Enter Angle A: ";
    std::cin >> angleA;

    std::cout << "Enter Angle B: ";
    std::cin >> angleB;

    std::cout << "Enter Angle C: ";
    std::cin >> angleC;

    std::cout << "\nEnter Side A: ";
    std::cin >> sideA;

    std::cout << "Enter Side B: ";
    std::cin >> sideB;

    std::cout << "Enter Side C: ";
    std::cin >> sideC;

    Triangle set1(angleA, angleB, angleC, sideA, sideB, sideC);

    std::cout << "\n========== RESULT ==========\n";

    if(set1.validateTriangle()){

        std::cout << "Triangle Validation : Valid Triangle\n";

        // a. Compute the area of the triangle
        std::cout << "Area                : "
                  << set1.areaTriangle() << std::endl;

        // b. Compute the perimeter of the triangle
        std::cout << "Perimeter           : "
                  << set1.perimeterTriangle() << std::endl;

        // c. Determine the type of triangle
        std::cout << "Triangle Type       : ";
        set1.triangleType();
        std::cout << std::endl;

    }
    else{

        std::cout << "Triangle Validation : NOT a Valid Triangle\n";
        std::cout << "Area                : Cannot be computed\n";
        std::cout << "Perimeter           : Cannot be computed\n";
        std::cout << "Triangle Type       : Cannot be determined\n";

    }

    return 0;
}

Triangle::Triangle(double A, double B, double C,
                   double sA, double sB, double sC){

    angleA = A;
    angleB = B;
    angleC = C;

    sideA = sA;
    sideB = sB;
    sideC = sC;

    totalAngle = A + B + C;

}

void Triangle::setAngles(double A, double B, double C){

    angleA = A;
    angleB = B;
    angleC = C;

    totalAngle = A + B + C;

}

bool Triangle::validateTriangle(){

    return (totalAngle == 180 &&
            angleA > 0 &&
            angleB > 0 &&
            angleC > 0);

}

// a. Function to compute for the area of a triangle
double Triangle::areaTriangle(){

    double s = (sideA + sideB + sideC) / 2;

    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));

}

// b. Function to compute for the perimeter of a triangle
double Triangle::perimeterTriangle(){

    return sideA + sideB + sideC;

}

// c. Function that determines whether the triangle is acute-angled, obtuse-angled, or others
void Triangle::triangleType(){

    if(angleA < 90 && angleB < 90 && angleC < 90){
        std::cout << "Acute-angled";
    }
    else if(angleA > 90 || angleB > 90 || angleC > 90){
        std::cout << "Obtuse-angled";
    }
    else{
        std::cout << "Others";
    }

}
