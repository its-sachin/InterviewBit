#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int lis(const vector<int> &A) {

    if(A.size()==0)
        return 0;

    int dp[A.size()] = {-1};
    int ans = INT32_MIN;

    for (int i = A.size()-1; i >=0; i--){
        
        dp[i]=1;
        for (int j = i+1; j < A.size(); j++){
            
            if(A[j]>A[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }   
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 1, 5};
    cout<<lis(v)<<endl;
    return 0;
}