#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back
#define all(x) x.begin(),x.end() 

class Solution{

int Solution::findMinXor(vector<int> &A) {

    sort(all(A));
    int m = A[1]^A[0];
    for (int i = 2; i < A.size(); i++){
    
        if(A[i]^A[i-1]<m){
            m=A[i]^A[i-1];
        }
    }
    return m;
}

};

int main(int argc, char const *argv[])
{
    return 0;
}