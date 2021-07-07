#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int perfectPeak(vector<int> &A) {
    pair<int,int> suffix[A.size()];
    suffix[A.size()-1]={0,A[A.size()-1]};
    suffix[0] = {A[0],0};

    for (int i = A.size()-2; i >=0; i--){

        suffix[i].second = min(suffix[i+1].second,A[i]);
        suffix[A.size()-i-1].first = max(suffix[A.size()-i-2].first,A[A.size()-i-1]);
    }

    for (int i = 1; i < A.size()-1; i++){
    
        if(A[i]>suffix[i-1].first and A[i]<suffix[i+1].second){
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    vector<int> a;
    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        a.push_back(ai);
    }

    perfectPeak(a);

    return 0;
}