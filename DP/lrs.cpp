#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


int anytwo(string A) {

    int n = A.size();

    int dp[n+1][n+1];

    for (int i = 0; i <= n; i++){
    
        dp[i][0]=0;
        dp[0][i]=0;
    }

    for (int i = 1; i <= n; i++){
    
        for (int j = 1; j <= n; j++){
        
            if(i!=j and  A[i-1]==A[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][n];
}


int main(int argc, char const *argv[])
{
    return 0;
}