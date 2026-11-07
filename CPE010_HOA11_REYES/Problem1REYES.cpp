
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;

bool Unique(int A[], int n, long long& operations) {
    operations = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            operations++;

            if (A[i] == A[j])
                return false;
        }
    }

    return true;
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000, 16000};

    cout << left
         << setw(15) << "N"
         << setw(25) << "Operations"
         << "Time (ms)\n";

    cout << string(55, '-') << "\n";

    for (int s = 0; s < 5; s++) {
        int n = sizes[s];
        int* A = new int[n];

        for (int i = 0; i < n; i++)
            A[i] = i + 1;

        long long operations = 0;

        auto start = steady_clock::now();
        Unique(A, n, operations);
        auto end = steady_clock::now();

        double time = duration<double, milli>(
            end - start).count();

        cout << left
             << setw(15) << n
             << setw(25) << operations
             << fixed << setprecision(4)
             << time << " ms\n";

        delete[] A;
    }

    return 0;
}
