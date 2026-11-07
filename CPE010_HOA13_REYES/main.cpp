
#include <iostream>
#include <thread>
#include <mutex>

int globalValue = 0;
std::mutex mtx;

void add(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    globalValue += value;
}

void display() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Global value: " << globalValue << std::endl;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    display();

    T1.join();
    display();

    T2.join();
    display();

    T3.join();
    display();

    return 0;
}











