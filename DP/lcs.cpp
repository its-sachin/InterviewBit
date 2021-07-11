#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(string A, string B) {
    int n = A.size();
    int m = B.size();

    int dp[n+1][m+1];

    for (int i = 0; i <= n; i++){
    
        dp[i][0]=0;
    }

    for (int i = 0; i <= m; i++){
    
        dp[0][i]=0;
    }

    for (int i = 1; i <= n; i++){
    
        for (int j = 1; j <= m; j++){
        
            if(A[i-1]==B[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    return 0;
}