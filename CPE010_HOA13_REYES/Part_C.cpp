
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

void bubbleSort(std::vector<int>& arr, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start); j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> arr = {29, 8, 41, 15, 3, 26, 12, 35};

    std::cout << "Original array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    int mid = arr.size() / 2;

    std::thread T1(bubbleSort, std::ref(arr), 0, mid - 1);
    std::thread T2(bubbleSort, std::ref(arr), mid, arr.size() - 1);

    T1.join();
    T2.join();

    std::sort(arr.begin(), arr.end());

    std::cout << "Sorted array: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
