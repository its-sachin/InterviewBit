#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for (int i = 0; i < A.size(); i++){
        
        if((i!=A.size()-1 and A[i]!=A[i+1] and A[i]==A.size()-i-1) or (i==A.size()-1 and A[i]==0))
            return 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    return 0;
}