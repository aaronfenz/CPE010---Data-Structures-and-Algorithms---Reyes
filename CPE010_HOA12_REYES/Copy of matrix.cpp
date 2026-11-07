
#include <iostream>
#include <vector>
using namespace std;

int countPaths(const vector<vector<int>>& matrix,
               int row, int col, int remainingCost,
               vector<vector<vector<int>>>& memo) {
    int m = matrix.size();
    int n = matrix[0].size();

    if (row >= m || col >= n)
        return 0;

    if (matrix[row][col] > remainingCost)
        return 0;

    if (memo[row][col][remainingCost] != -1)
        return memo[row][col][remainingCost];

    remainingCost -= matrix[row][col];

    if (row == m - 1 && col == n - 1)
        return memo[row][col][remainingCost + matrix[row][col]]
            = (remainingCost == 0 ? 1 : 0);

    int right = countPaths(matrix, row, col + 1,
                           remainingCost, memo);

    int down = countPaths(matrix, row + 1, col,
                          remainingCost, memo);

    return memo[row][col][remainingCost + matrix[row][col]]
        = right + down;
}

int main() {
    vector<vector<int>> matrix = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int targetCost = 26;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<vector<int>>> memo(
        m, vector<vector<int>>(
            n, vector<int>(targetCost + 1, -1)
        )
    );

    cout << "Target cost: " << targetCost << endl;
    cout << "Number of valid paths: "
         << countPaths(matrix, 0, 0, targetCost, memo)
         << endl;

    return 0;
}
