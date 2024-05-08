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

bool isSafe(int row, int col, const vector<vector<int>>& board, int n) {
    // Check column to the left
    for (int y = col; y >= 0; y--) {
        if (board[row][y] == 1)
            return false;
    }

    // Check upper diagonal on left side
    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--) {
        if (board[x][y] == 1)
            return false;
    }

    // Check lower diagonal on left side
    for (int x = row, y = col; x < n && y >= 0; x++, y--) {
        if (board[x][y] == 1)
            return false;
    }

    return true;
}

void solve(int col, vector<vector<int>> &board, int n, int &solutionCount) {
    if (col == n) {
        cout << "\nSolution " << ++solutionCount << ":\n";
        printSolution(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, board, n, solutionCount);
            board[row][col] = 0;  // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    int solutionCount = 0;
    solve(0, board, n, solutionCount);

    cout << "Number of solutions: " << solutionCount << endl;

    return 0;
}
