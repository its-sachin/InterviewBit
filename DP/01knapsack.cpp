#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A, vector<int> &B, int C) {

    int n = A.size();
    int dp[n+1][C+1];

    for (int i = 0; i <=C; i++){
        dp[0][i]=0;
    }

    for (int i = 0; i <=n; i++){
        dp[i][0]=0;
    }

    for (int i = 1; i <=n; i++){
    
        for (int j = 1; j <=C; j++){
            
            if(B[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j-B[i-1]]+A[i-1],dp[i-1][j]);
            }
            
        }
    }
    return dp[n][C];
}


int main(int argc, char const *argv[])
{
    return 0;
}