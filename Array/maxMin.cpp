#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A) {

    if(A.size()==1)
        return 2*A[0];
    int mi,ma;
    if(A[0]>=A[1]){
        mi=A[1];
        ma=A[0];
    }
    else{
        mi=A[0];
        ma=A[1];
    }

    for (int i = 2; i < A.size()-1; i+=2){
    
        if(A[i]>=A[i+1]){
            mi=min(mi,A[i+1]);
            ma=max(ma,A[i]);
        }
        else{
            mi=min(mi,A[i]);
            ma=max(ma,A[i+1]);
        }
    }

    ma=max(A[A.size()-1],ma);
    mi=min(A[A.size()-1],mi);
    return ma+mi;

}


int main(int argc, char const *argv[])
{
    vector<int> v = {1, 3, 4, 1};
    cout<<solve(v)<<endl;
    return 0;
}