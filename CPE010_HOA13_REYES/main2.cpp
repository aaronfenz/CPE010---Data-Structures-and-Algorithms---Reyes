
#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <algorithm>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= right) {
        temp.push_back(arr[j++]);
    }

    for (int k = 0; k < static_cast<int>(temp.size()); k++) {
        arr[left + k] = temp[k];
    }
}

void parallelMergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    if (right - left < 3) {
        std::sort(arr.begin() + left, arr.begin() + right + 1);
        return;
    }

    int mid = left + (right - left) / 2;

    std::thread leftThread(
        parallelMergeSort, std::ref(arr), left, mid
    );

    parallelMergeSort(arr, mid + 1, right);

    leftThread.join();

    merge(arr, left, mid, right);
}

int main() {
    std::vector<int> arr = {38, 12, 45, 7, 23, 19, 50, 4};

    std::cout << "Original array: ";
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    parallelMergeSort(arr, 0, static_cast<int>(arr.size()) - 1);

    std::cout << "Sorted array: ";
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
















