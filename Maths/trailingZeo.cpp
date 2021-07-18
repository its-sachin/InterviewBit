#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int trailingZeroes(int A) {
    
    long long int i=5;
    int ans =0;
    while(i<=A){
        ans+=A/i;
        i*=5;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    cout<<trailingZeroes(n)<<endl;
    return 0;
}