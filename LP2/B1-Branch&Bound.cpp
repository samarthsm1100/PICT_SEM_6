#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(int row, int col, const vector<bool>& rows, const vector<bool>& leftDiagonals, const vector<bool>& rightDiagonals, int& safetyChecks) {
    safetyChecks++;
    if (rows[row] || leftDiagonals[row + col] || rightDiagonals[col - row + rows.size() - 1]) {
        return false;
    }
    return true;
}

void solveNQueens(vector<vector<int>>& board, int col, vector<bool>& rows, vector<bool>& leftDiagonals, vector<bool>& rightDiagonals, int& solutionCount, int& safetyChecks) {
    int n = board.size();
    if (col == n) {
        cout << "\nSolution " << ++solutionCount << ":\n";
        printSolution(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, rows, leftDiagonals, rightDiagonals, safetyChecks)) {
            board[row][col] = 1;
            rows[row] = true;
            leftDiagonals[row + col] = true;
            rightDiagonals[col - row + n - 1] = true;

            solveNQueens(board, col + 1, rows, leftDiagonals, rightDiagonals, solutionCount, safetyChecks);

            board[row][col] = 0;
            rows[row] = false;
            leftDiagonals[row + col] = false;
            rightDiagonals[col - row + n - 1] = false;
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<bool> rows(n, false);
    vector<bool> leftDiagonals(2 * n - 1, false);
    vector<bool> rightDiagonals(2 * n - 1, false);
    int solutionCount = 0;
    int safetyChecks = 0;

    solveNQueens(board, 0, rows, leftDiagonals, rightDiagonals, solutionCount, safetyChecks);

    cout << "\nTotal number of solutions: " << solutionCount << endl;
    cout << "Number of safety checks: " << safetyChecks << endl;

    return 0;
}
