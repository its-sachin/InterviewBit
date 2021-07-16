#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int minPathSum(vector<vector<int> > &A) {
    if(!A.size())
        return 0;

    int m = A.size();
    int n = A[0].size();

    int dp[m][n];

    dp[m-1][n-1]=A[m-1][n-1];
    for (int i = m-2; i >=0; i--){
    
        dp[i][n-1]=dp[i+1][n-1]+A[i][n-1];
    }
    for (int i = n-2; i >=0; i--){
    
        dp[m-1][i]=dp[m-1][i+1]+A[m-1][i];
    }

    for (int i = m-2; i >=0; i--){
    
        for (int j = n-2; j >=0; j--){
            dp[i][j] = min(dp[i+1][j],dp[i][j+1])+A[i][j];
        }
    }
    return dp[0][0];

}


int main(int argc, char const *argv[])
{
    return 0;
}