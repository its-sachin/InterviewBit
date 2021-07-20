#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A) {
    unordered_map<int,int> ml;
    int ans=INT32_MAX;
    for (int i = 0; i < A.size(); i++){
    
        if(ml.find(A[i])!=ml.end())
            ans=min(ans,ml[A[i]]);
        ml[A[i]]=i;
    }
    if(ans==INT32_MAX)
        return -1;
    return A[ans];
}

int main(int argc, char const *argv[])
{
    return 0;
}