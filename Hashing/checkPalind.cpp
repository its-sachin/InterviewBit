#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(string A) {

    unordered_map<char,int> m;
    for (int i = 0; i < A.size(); i++){
    
        if(m.find(A[i])==m.end())
            m.insert({A[i],1});
        else
            m[A[i]]+=1;
    }
    int odd=0;
    for(pair<char,int> p:m){
        if(p.second&1)
            odd+=1;

        if(odd>1)
            return 0;
    }
    return 1;
}


int main(int argc, char const *argv[])
{
    return 0;
}