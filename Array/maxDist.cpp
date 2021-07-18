#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int maximumGap(const vector<int> &A) {
    int n = A.size();
    int minA[n];
    int maxA[n];

    minA[0]=A[0];
    maxA[n-1]=A[n-1];

    for (int i = 1; i < n; i++){
        
        minA[i]=min(minA[i-1],A[i]);
        maxA[n-i-1] = max(maxA[n-i],A[n-i-1]);
        
    }

    int i = 0;
    int j = 0;
    int ans = -1;
    while (j < n && i < n) {
        if (minA[i] <= maxA[j]) {
            ans = max(ans, j - i);
            j = j + 1;
        }
        else
            i = i + 1;
    }
 
    return ans;
}


int main(int argc, char const *argv[])
{
    return 0;
}