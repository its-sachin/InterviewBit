#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int inter(int j, int i, vector<vector<int>> &v, int** dp){
    if(i>=v.size())
        return 0;


    int two = dp[j][i+1];

    if(two==-1){
        two = inter(j,i+1,v,dp);
        dp[j][i+1] = two;
    }
    if(v[i][0]>v[j][1]){
        int one = dp[i][i+1];
        if(one==-1){
            one = inter(i,i+1,v,dp);
            dp[i][i+1] = one;
        }
        return max(one+1,two);
    }
    else{
        return two;
    }

        
}

int solve(vector<vector<int> > &A) {

    int** dp = new int*[A.size()+1];
    for (int i = 0; i <= A.size(); i++){
    
        dp[i] = new int[A.size()+1];
        for (int j = i+1; j <= A.size(); j++){
        
            dp[i][j]=-1;
        }
        dp[i][i]=1;
    }
    
    int ans = INT32_MIN;
    for (int i = 0; i < A.size(); i++){
    
        ans = max(ans,inter(i,i+1,A,dp)+1);
    }
    return ans;

}


int main(int argc, char const *argv[])
{
    vector<vector<int>> A = { {5, 24},
        {39, 60},
        {15, 28},
        {27, 40},
        {50, 90}
     };
    cout<<solve(A)<<endl;
    return 0;
}