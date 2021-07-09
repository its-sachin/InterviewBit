#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A, int B) {
    unordered_map<int,int> m;
    for (int i = 0; i < A.size(); i++){
    
        m.insert({A[i],i});
    }
    int c=0;
    for (int i = 0; i < A.size(); i++){
        int x = B^A[i];
        if(m.find(x)!=m.end() and m[x]!=i)
        c+=1;
    }
    return c/2;
    
}


int main(int argc, char const *argv[])
{
    return 0;
}