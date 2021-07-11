#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int longestConsecutive(const vector<int> &A) {
    unordered_map<int,int> m;

    for (int i = 0; i < A.size(); i++){
        
        m.insert({A[i],i});
    }
    int ans=0;
    for (int i = 0; i < A.size(); i++){
        
        if(m.find(A[i]-1)==m.end()){
            int k=1;
            while(m.find(A[i]+k)!=m.end()){
                k+=1;
            }
            ans=max(ans,k);
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    return 0;
}