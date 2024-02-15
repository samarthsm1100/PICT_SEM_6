#include<bits/stdc++.h>
using namespace std;

int n;
int cnt;

void printSol(vector<vector<int>>board){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool isSafe(int row ,int col ,vector<bool>rows , vector<bool>left_digonals ,vector<bool>Right_digonals){
    cnt++;
    if(rows[row] == true || left_digonals[row+col] == true || Right_digonals[col-row+n-1] == true){
        return false;
    }   
    return true;
}

void solve(vector<vector<int>>& board ,int col ,vector<bool>rows , vector<bool>left_digonals ,vector<bool>Right_digonals, int &count){	 
	// base case : If all Queens are placed 
	if(col==n){
        count++;
        cout << "\nSolution "<< count << " : " << endl;
        printSol(board);
		return;
	}

	for(int i = 0;i<n;i++){
		if(isSafe(i,col,rows,left_digonals,Right_digonals) == true){
            // Place the Queen
			rows[i] = true;
			left_digonals[i+col] = true;
			Right_digonals[col-i+n-1] = true;
			board[i][col] = 1; 

			solve(board,col+1,rows,left_digonals,Right_digonals, count);

			// Backtracking 
			rows[i] = false;
			left_digonals[i+col] = false;
			Right_digonals[col-i+n-1] = false;
			board[i][col] = 0; 

		}
	}
}


int main(){
    cnt = 0;
    cout<<"Enter the value of n: ";
    cin>>n;
    int count = 0;

    vector<vector<int>>board(n,vector<int>(n,0));
    vector<bool>rows(n,false);		 

    vector<bool>left_digonals(2*n-1,false);
    vector<bool>Right_digonals(2*n-1,false);

    solve(board , 0, rows,left_digonals,Right_digonals, count);

    cout<<"\nTotal number of solutions: "<<count<<endl;

    cout << "isSAfe : " << cnt << "\n";

    return 0;
}
