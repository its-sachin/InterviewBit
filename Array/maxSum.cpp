#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int solve(vector<int> &A) {

    int suffix[A.size()+1];
    suffix[A.size()]=0;
    for(int i=A.size()-1; i>=0;i--){
        suffix[i]=max(A[i],suffix[i+1]);
    }

    set<int> tree;
    tree.insert(INT32_MIN);
    int maxx = -1;
    for(int i=0; i<A.size()-1; i++){
        int ma = suffix[i+1];
        if(ma>A[i]){
            int mi = *(--tree.lower_bound(A[i]));
            if(maxx==-1 or mi+ma+A[i]>maxx){
                maxx = mi+ma+A[i];
            }
        }
        tree.insert(A[i]);
    }
    return maxx;
}

int main(int argc, char const *argv[])
{
    vector<int> a;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        a.push_back(ai);
    }
    cout<<solve(a)<<endl;
    return 0;
}

// 18468 6335 26501 19170 15725 11479 29359 26963 24465 5706 28146 23282 16828 9962 492 2996 11943 4828 5437 32392 14605
