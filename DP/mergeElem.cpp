#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int rec(vector<int> &A, int i, int j, int** dp){

    if(i>=j)
        return 0;
    
    if(dp[i][j] !=-1)
        return dp[i][j];

    int s=0;
    for (int k = i; k <=j; k++){
    
        s+=A[k];
    }

    int ans = INT32_MAX;
    for (int k = i+1; k <= j; k++){
    
        ans=min(ans,s+rec(A,i,k-1,dp)+rec(A,k,j,dp));
    }
    dp[i][j]=ans;
    return ans;
}

int solve(vector<int> &A) {

    if(A.size()<2)
        return 0;
    if(A.size()==2)
        return A[0]+A[1];

    int** dp = new int*[A.size()];
    for (int i = 0; i < A.size(); i++){
    
        dp[i]=new int[A.size()];
        for (int j = 0; j < A.size(); j++){
        
            dp[i][j]=-1;
        }
    }

    return rec(A,0,A.size()-1,dp);
}

int main(int argc, char const *argv[])
{
    vector<int> v = {218, 85, 1, 170, 225, 229, 109, 213, 215, 206, 146, 32, 78, 212, 242, 246, 193, 78, 187, 142, 105, 153, 154, 43, 133, 172, 217, 219, 146, 198, 227, 22, 39, 120, 163, 168, 50, 36, 145, 204, 62, 73, 84, 174, 165, 142, 212, 4, 119, 48, 145, 163, 8, 38, 110, 224, 242, 30, 29, 67, 36, 191, 93, 39, 107, 41, 193, 15, 149, 197, 56, 141, 230, 121, 101, 7, 102, 144, 49, 130, 124, 85, 205, 7, 91, 217, 127, 182, 59, 195, 190, 127};
    cout<<solve(v)<<endl;
    
    return 0;
}