#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include "sorting.h"

// MEASURE BUBBLE SORT
double measureBubble(const std::vector<int>& values) {
    std::vector<int> arr = values;

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(arr.data(), arr.size());
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::milli>(end - start).count();
}

// MEASURE SELECTION SORT
double measureSelection(const std::vector<int>& values) {
    std::vector<int> arr = values;

    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(arr.data(), static_cast<int>(arr.size()));
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    int sizes[] = {100, 1000, 10000};

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "TABLE 14-2: EXPERIMENTAL ANALYSIS\n";

    for (int n : sizes) {
        std::vector<int> sorted(n);
        std::vector<int> reversed(n);

        for (int i = 0; i < n; i++) {
            sorted[i] = i + 1;
            reversed[i] = n - i;
        }

        std::cout << "\nInput Size: " << n << "\n";

        std::cout << "Best Case:\n";
        std::cout << "Bubble Sort: "
                  << measureBubble(sorted) << " ms\n";
        std::cout << "Selection Sort: "
                  << measureSelection(sorted) << " ms\n";

        std::cout << "Worst Case:\n";
        std::cout << "Bubble Sort: "
                  << measureBubble(reversed) << " ms\n";
        std::cout << "Selection Sort: "
                  << measureSelection(reversed) << " ms\n";
    }

    return 0;
}