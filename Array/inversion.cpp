#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int countInversions(vector<int> &A) {

    int c=0;
    map<int,int> m;
    m[A[0]]=0;

    for (int i = 1; i < A.size(); i++){
        
        auto j = m.upper_bound(A[i]);
        if(j!=m.end()){
            c+=i-j->second;
        }

        m[A[i]] = i;
    }
    return c;
}   


int main(int argc, char const *argv[])
{
    return 0;
}