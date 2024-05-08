#include <iostream>
#include <vector>

using namespace std;

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x, y;

    // Check column to the left
    for (y = col; y >= 0; y--) {
        if (board[row][y] == 1)
            return false;
    }

    // Check upper diagonal on left side
    for (x = row, y = col; x >= 0 && y >= 0; x--, y--) {
        if (board[x][y] == 1)
            return false;
    }

    // Check lower diagonal on left side
    for (x = row, y = col; x < n && y >= 0; x++, y--) {
        if (board[x][y] == 1)
            return false;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    if (col == n) {
        addSolution(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;  // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    cout << "Number of solutions: " << ans.size() << endl;

    for (const auto &sol : ans) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << sol[i * n + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
