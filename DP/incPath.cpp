#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<vector<int> > &A) {

    if(!A.size())
        return -1;

    int n = A.size();
    int m = A[0].size();

    pair<int,bool> dp[n][m];

    for (int i = n-1; i >=0; i--){
    
        for (int j = m-1; j >=0; j--){
            
            if(i==n-1 and j==m-1)
                dp[i][j] = {1,true};

            else{
                if(i==n-1 or A[i+1][j]<=A[i][j]){
                    if(j==m-1 or A[i][j+1]<=A[i][j]){
                        dp[i][j]={1,false};
                    }
                    else{
                        dp[i][j] = {dp[i][j+1].first+1,dp[i][j+1].second};
                    }
                }
                else{
                    if(j==m-1 or A[i][j+1]<=A[i][j]){
                        dp[i][j] = {dp[i+1][j].first+1,dp[i+1][j].second};
                    }
                    else{
                        if(!dp[i+1][j].second){
                            if(!dp[i][j+1].second)
                                dp[i][j] = {1,false};
                            else
                                dp[i][j] = {dp[i][j+1].first+1,true};
                        }
                        else{
                            if(!dp[i][j+1].second)
                                dp[i][j] = {dp[i+1][j].first+1,true};
                            else
                                dp[i][j] = {max(dp[i+1][j].first,dp[i][j+1].first)+1,true};
                        }
                    }

                }
            }
        }
    }
    if(!dp[0][0].second)
        return -1;
    return dp[0][0].first;
}


int main(int argc, char const *argv[])
{
    return 0;
}