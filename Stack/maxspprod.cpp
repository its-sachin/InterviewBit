#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int maxSpecialProduct(vector<int> &A) {

    stack<pair<int,int>> s;
    s.push({A[0],0});
    long long int right[A.size()];
    for (int i = 1; i < A.size(); i++){

        if(s.empty())
            s.push({A[i],i});

        while(!s.empty() and s.top().first < A[i]){
            right[s.top().second]=i;
            s.pop();
        }

        s.push({A[i],i});
    }

    while(!s.empty()){
        right[s.top().second]=0;
        s.pop();
    }


    stack<pair<int,int>> s1;
    s1.push({A[A.size()-1],A.size()-1});
    long long int left[A.size()];

    for (int i = A.size()-2; i >= 0; i--){
        if(s1.empty())
            s1.push({A[i],i});

        while(!s1.empty() and s1.top().first < A[i]){
            left[s1.top().second]=i;
            s1.pop();
        }

        s1.push({A[i],i});
    }

    while(!s1.empty()){
        left[s1.top().second]=0;
        s1.pop();
    }


    long long int ans = 0;

    for (int i = 1; i < A.size()-1; i++){
    
        ans = max(ans,(left[i]*right[i])%mod);
    }
    return ans;
    
}


int main(int argc, char const *argv[])
{
    vector<int> v = {5, 9, 6, 8, 6, 4, 6, 9, 5, 4, 9};
    cout<<maxSpecialProduct(v) <<endl;
    return 0;
}