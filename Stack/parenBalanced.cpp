#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(string A) {
    int i=0;
    for (int j = 0; j < A.size(); j++){
    
        if(A[j]=='(')
            i+=1;
        else
            i-=1;

        if(i<0)
            return 0;
    }
    return i==0;
}

int main(int argc, char const *argv[])
{
    return 0;
}