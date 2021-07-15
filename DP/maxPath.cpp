#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<vector<int> > &A) {

    for (int i = A.size()-2; i >= 0; i--){
    
        for (int j = i; j >=0; j--){
    
            A[i][j] = max(A[i+1][j+1],A[i+1][j]) + A[i][j];
        }
    }

    for (int i = 0; i < A.size(); i++){
        
        cout<<"[";
        for (int j = 0; j < A.size(); j++){
        
            cout<<A[i][j]<<", ";
        }
        cout<<"]"<<endl;
    }
    return A[0][0];
}


int main(int argc, char const *argv[])
{
     vector<vector<int>> A = {
        {3, 0, 0, 0},
        {7, 4, 0, 0},
        {2, 4, 6, 0},
        {8, 5, 9, 3}
     };

     cout<<solve(A)<<endl;
    return 0;
}