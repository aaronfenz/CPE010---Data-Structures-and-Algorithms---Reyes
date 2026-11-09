#include <iostream>
#include <string>
#include <thread>

void print (int n, const std::string &str) {
    std::cout << "-------------------------" << std::endl;
    std::cout << "Printing Integer: " << n << std::endl;
    std::cout << "Printing String: " << str << std::endl;
    std::cout << "-------------------------" << std::endl;
}

int main() {
    std::thread t1(print, 10, "T.I.P.");
    t1.join();
return 0;
}








