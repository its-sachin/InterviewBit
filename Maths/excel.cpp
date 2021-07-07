#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int titleToNumber(string A) {
    int ans = 0;
    long int pow = 1;
    for (int i = 0; i < A.size(); i++){
    
        ans+=pow*(A[A.size()-i-1]-64);
        pow*=26;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}