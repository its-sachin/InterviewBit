#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(const vector<int> &A) {
    int n = A.size();

    int s=0;
    for (int i = 0; i < A.size(); i++){
    
        s+=A[i];
    }

    int dp[n+1][s+1];
    for (int i = 0; i <=s; i++){
    
        dp[0][i]=INT32_MAX-1;
    }

    for (int i = 0; i <=n; i++){
    
        dp[i][0]=0;
    }

    for (int i = 1; i <=n; i++){
    
        for (int j = 1; j <=s; j++){
        
            if(A[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-A[i-1]]+1);
            }
        }
    }

    int i = s/2;
    while(i>=0 and dp[n][i]==INT32_MAX-1) i-=1;

    cout<<i<<endl;
    return dp[n][i];
}


int main(int argc, char const *argv[])
{
    vector<int> v = {9,6};
    
    cout<<solve(v)<<endl;
    return 0;
}