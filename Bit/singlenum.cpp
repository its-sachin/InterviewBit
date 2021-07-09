#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution{


int Solution::singleNumber(const vector<int> &A) {
    int xorr=0;
    for (int i = 0; i < A.size(); i++){
    
        xorr^=A[i];
    }
    return xorr;
}

};

int main(int argc, char const *argv[])
{
    return 0;
}