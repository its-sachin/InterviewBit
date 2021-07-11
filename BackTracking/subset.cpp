#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<vector<int> > subsets(vector<int> &A) {
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    if(A.size()==0){
        ans.push_back({});
        return ans;
    }
    if(A.size()==1){
        ans.push_back({});
        ans.push_back(A);
        return ans;
    }

    int f = A.back();
    A.pop_back();
    vector<vector<int> > a=subsets(A);

    for (int i = 0; i < a.size(); i++){
    
        ans.push_back(a[i]);
        a[i].push_back(f);
        ans.push_back(a[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}


int main(int argc, char const *argv[])
{
    return 0;
}