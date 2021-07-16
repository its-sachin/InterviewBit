#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A) {

    int s=0;
    for (int i = 0; i < A.size(); i++){
        s+=A[i];
    }

    bool dp[A.size()+1][s+1];

    for (int i = 0; i <= A.size(); i++){
    
        dp[i][0]=true;
    }

    for (int i = 1; i <=s; i++){
    
        dp[0][i]=false;
    }

    for (int i = 1; i <= A.size(); i++){
    
        for (int j = 1; j <=s; j++){
        
            if(A[i-1]>s)
                dp[i][j]=false;

            else{
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }
        }
    }

    int k = s/2;
    while(!dp[A.size()-1][k])
        k--;
    return (s-2*k);
}

int main(int argc, char const *argv[])
{
    return 0;
}