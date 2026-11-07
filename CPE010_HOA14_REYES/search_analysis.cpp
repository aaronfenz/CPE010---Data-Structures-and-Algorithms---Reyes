
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

// LINEAR SEARCH
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

// BINARY SEARCH
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// MEASURE BINARY SEARCH
double measureBinary(const std::vector<int>& arr, int target) {
    volatile int result = -1;
    const int repetitions = 1000;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++)
        result = binarySearch(arr, target);

    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration<double, std::milli>(
        end - start).count() / repetitions;
}

// MEASURE LINEAR SEARCH
double measureLinear(const std::vector<int>& arr, int target) {
    volatile int result = -1;
    const int repetitions = 1000;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < repetitions; i++)
        result = linearSearch(arr, target);

    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration<double, std::milli>(
        end - start).count() / repetitions;
}

int main() {
    int sizes[] = {1000, 10000, 100000};

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "WORST-CASE SEARCH ANALYSIS\n";

    for (int n : sizes) {
        std::vector<int> arr(n);

        for (int i = 0; i < n; i++)
            arr[i] = i + 1;

        // Target is absent, forcing both searches
        // to examine the full search range.
        int target = n + 1;

        std::cout << "\nInput Size: " << n << "\n";

        std::cout << "Binary Search: "
                  << measureBinary(arr, target) << " ms\n";

        std::cout << "Linear Search: "
                  << measureLinear(arr, target) << " ms\n";
    }

    return 0;
}
