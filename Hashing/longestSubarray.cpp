#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A) {
    
    unordered_map<int,int> m;
    int s=0;
    int ans=0;
    for (int i = 0; i < A.size(); i++){
    
        if(A[i]==0)
            s-=1;
        else
            s+=1;

        if(s==1)
            ans=max(i+1,ans);

        if(m.find(s)==m.end())
            m[s]=i;

        if(m.find(s-1)!=m.end())
            ans=max(ans,i-m[s-1]);
    }
    return ans;
}   


int main(int argc, char const *argv[])
{
    vector<int> v = {0, 1, 1, 0, 0, 1};
    cout<<solve(v)<<endl;
    return 0;
}