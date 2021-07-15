#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int m = INT32_MIN;
    for (int i = 0; i < A.size(); i++){
    
        m = max(m,abs(A[i]-B[i]));
    }
    return m;
}


int main(int argc, char const *argv[])
{
    return 0;
}