#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

void rotate(vector<vector<int> > &A) {

    int n = A.size();
    for (int i = 0; i <= n/2; i++){
    
        for (int j = i; j < n-i-1; j++){
        
            int t = A[i][j];
            A[i][j] = A[n-j-1][i];
            A[n-j-1][i] = A[n-i-1][n-1-j];
            A[n-1-i][n-1-j] = A[j][n-i-1];
            A[j][n-1-i]=t;
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> a = {
        {1,2,3,10},
        {4,5,6,11},
        {7,8,9,12},
        {13,14,15,16}
    };

    rotate(a);

    for (int i = 0; i < a.size(); i++){
    
        for (int j = 0; j < a[i].size(); j++){
        
            cout<<a[i][j]<<" ";
        }
        cout<<""<<endl;
    }
    return 0;
}