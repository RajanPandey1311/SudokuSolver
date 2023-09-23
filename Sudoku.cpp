#include <iostream>
#include <vector>
using namespace std;

// 9*9 Sudoku Solver By BackTracking 

bool isValid(vector<vector<int>>& grid, int r, int c, int k) {
    for (int i = 0; i < 9; ++i) {
        if (grid[r][i] == k || grid[i][c] == k)
            return false;
    }
    int rowStart = (r / 3) * 3;
    int colStart = (c / 3) * 3;
    for (int i = rowStart; i < rowStart + 3; ++i) {
        for (int j = colStart; j < colStart + 3; ++j) {
            if (grid[i][j] == k)
                return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>& grid, int r = 0, int c = 0) {
    if (r == 9)
        return true;
    else if (c == 9)
        return solve(grid, r + 1, 0);
    else if (grid[r][c] != 0)
        return solve(grid, r, c + 1);
    else {
        for (int k = 1; k <= 9; ++k) {
            if (isValid(grid, r, c, k)) {
                grid[r][c] = k;
                if (solve(grid, r, c + 1))
                    return true;
                grid[r][c] = 0;
            }
        }
        return false;
    }
}
int main() {
    vector<vector<int>> grid(9, vector<int>(9, 0));
    cout << "Enter the Sudoku puzzle (9x9) with 0s for empty cells:" << endl;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
        }
    }
    if (solve(grid)) {
        cout << "Solved Sudoku:" <<endl;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}