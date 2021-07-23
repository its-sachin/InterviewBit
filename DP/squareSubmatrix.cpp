#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<vector<int> > &A) {
    int dp[A.size()][A[0].size()];

    int ans = 0;
    for (int i = 0; i < A.size(); i++){
    
        dp[i][0] = A[i][0];
        ans = max(ans,dp[i][0]);
    }

    for (int i = 0; i < A[0].size(); i++){
    
        dp[0][i]  =A[0][i];
        ans = max(ans,dp[0][i]);
    }

    for (int i = 1; i < A.size(); i++){
    
        for (int j = 1; j < A[0].size(); j++){
        
            if(A[i][j]==1)
                dp[i][j] = min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            else
                dp[i][j]=0;   

            ans = max(ans,dp[i][j]); 
        }   

    }

    return ans*ans;
}


int main(int argc, char const *argv[])
{
    return 0;
}