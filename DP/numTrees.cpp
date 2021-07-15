#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int numTrees(int A) {
    int dp[A+1] = {0};
    dp[1]=1;
    dp[0]=1;

    for (int i = 2; i <= A; i++){
    
        for (int j = 1; j <=i; j++){
        
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }

    return dp[A];
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    cout<<numTrees(n)<<endl;
    return 0;
}