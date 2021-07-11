#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back



int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int n = B.size();

    int s = INT32_MIN;
    for (int i = 0; i < A.size(); i++){
      s = max(s,A[i]);  
    }

    int dp[n+1][s+1];

    for (int i = 0; i <=s; i++){
        dp[0][i]=-1;
    }

    for (int i = 0; i <=n; i++){
        dp[i][0]=0;
    }

    for (int i = 1; i <=n; i++){
    
        for (int j = 1; j <=s; j++){
            
            if(B[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else{
                if(dp[i][j-B[i-1]]==-1){
                    dp[i][j] = dp[i-1][j];
                }
                else if(dp[i-1][j] == -1){
                    dp[i][j] = dp[i][j-B[i-1]]+C[i-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-B[i-1]]+C[i-1]);
                }
            }
            
        }
    }

    int ans=0;
    for (int i = 0; i <A.size(); i++){
    
        ans+=dp[n][A[i]];
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {2, 3, 1, 5, 4 };
    vector<int> B = {3, 2, 4, 1 };
    vector<int> C = {1, 2, 5, 10 };

    cout<<solve(A,B,C)<<endl;
    return 0;
}