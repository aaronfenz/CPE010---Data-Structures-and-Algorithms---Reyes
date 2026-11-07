
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace chrono;

long long rOperations, brOperations;

long long rpower(long long x, int n) {
    rOperations++;
    if (n == 0)
        return 1;
    return x * rpower(x, n - 1);
}

long long brpower(long long x, int n) {
    brOperations++;
    if (n == 0)
        return 1;
    long long y;
    if (n % 2 == 1) {
        y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }
    y = brpower(x, n / 2);
    return y * y;
}

int main() {
    int sizes[] = {100, 200, 400, 800, 1600};

    cout << left
         << setw(10) << "N"
         << setw(20) << "rpower Calls"
         << setw(20) << "rpower (ms)"
         << setw(20) << "brpower Calls"
         << "brpower (ms)\n";

    cout << string(90, '-') << "\n";

    for (int i = 0; i < 5; i++) {
        int n = sizes[i];
        rOperations = 0;
        auto start1 = steady_clock::now();
        rpower(1, n);
        auto end1 = steady_clock::now();
        double rTime = duration<double, milli>(
            end1 - start1).count();
        brOperations = 0;
        auto start2 = steady_clock::now();
        brpower(1, n);
        auto end2 = steady_clock::now();

        double brTime = duration<double, milli>(
            end2 - start2).count();

        cout << left
             << setw(10) << n
             << setw(20) << rOperations
             << setw(20) << fixed << setprecision(4) << rTime
             << setw(20) << brOperations
             << brTime << "\n";
    }

    return 0;
}
