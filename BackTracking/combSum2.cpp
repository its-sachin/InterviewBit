#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<vector<int> > rec(vector<int> A,int B){


    vector<vector<int> > ans;

    if(A.size()==0 )
        return ans;

    int back = A.back();
    A.pop_back();

    if(back==B){
        ans.push_back({back});
    }

    vector<vector<int> > a2 = rec(A,B-back);

    for (int i = 0; i < a2.size(); i++){
        
        a2[i].push_back(back);
        ans.push_back(a2[i]);
    }

    while(!A.empty() and A.back()==back){
        A.pop_back();
    }

    vector<vector<int> > a1 = rec(A,B);

    for (int i = 0; i < a1.size(); i++){

        ans.push_back(a1[i]);
    }

    // cout<<back<<" "<<B<<endl;


    return ans;
}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());

    return rec(A,B);
}

int main(int argc, char const *argv[])
{
    vector<int> v = { 8,8,8};

    vector<vector<int> > ans  = combinationSum(v,16);

    for (int i = 0; i < ans.size(); i++){
    
        for (int j = 0; j < ans[i].size(); j++){
        
            cout<<ans[i][j]<<" ";
        }
        cout<<""<<endl;
    }
    
    return 0;
}