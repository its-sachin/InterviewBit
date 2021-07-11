#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<vector<int> > result;

bool isSafe(vector<vector<int> > board, int row, int col){
    int i, j;
    int N = board.size();
 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
bool solveNQUtil(vector<vector<int> >& board, int col){

    int N = board.size();
    if (col == N) {
        vector<int> v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1)
                    v.push_back(j + 1);
            }
        }
        result.push_back(v);
        return true;
    }
 
    bool res = false;
    for (int i = 0; i < N; i++) {

        if (isSafe(board, i, col)) {
            board[i][col] = 1;
 
            res = solveNQUtil(board, col + 1) || res;

            board[i][col] = 0;
        }
    }
    return res;
}
 
vector<vector<string>> solveNQueens(int A)
{
    result.clear();
    vector<vector<int> > board(A, vector<int>(A, 0));
 
    if (solveNQUtil(board, 0) == false) {
        return {};
    }
 
    sort(result.begin(), result.end());
    vector<vector<string>> ans;
    for (int i = 0; i < result.size(); i++){
        
        vector<string> curr;
        string dot = "";
        for (int j = 0; j < A; j++){
            dot.push_back('.');
        }

        for (int j = 0; j < A; j++){
            string u = dot;
            u[result[i][j]-1]='Q';
            curr.push_back(u);
        }
        ans.push_back(curr);
        
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    vector<vector<string>> a = solveNQueens(n);

    for (int i = 0; i < a.size(); i++){
        
        cout<<i<<endl;
        for (int j = 0; j < a[i].size(); j++){
        
            cout<<"\""<<a[i][j]<<"\" \n";
        }
        cout<<"\n"<<endl;
    }
    return 0;
}