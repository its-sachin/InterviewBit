#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int climbStairs(int A) {

    int dp[A+1];
    dp[0]=1;
    dp[1]=1;

    for (int i = 2; i <=A; i++){
    
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[A];

}


int main(int argc, char const *argv[])
{
    return 0;
}