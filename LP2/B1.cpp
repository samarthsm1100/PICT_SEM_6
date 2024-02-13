#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printBoard(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueensUtil(int n, int row, vector<int>& board, int& count) {
    if (row == n) {
        ++count;
        cout << "Solution " << count << ":\n";
        printBoard(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueensUtil(n, row + 1, board, count);
            board[row] = -1; // backtrack
        }
    }
}

int solveNQueens(int n) {
    vector<int> board(n, -1);
    int count = 0;
    solveNQueensUtil(n, 0, board, count);
    return count;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    int solutions = solveNQueens(n);
    cout << "Number of solutions for " << n << " queens: " << solutions << endl;
    return 0;
}
