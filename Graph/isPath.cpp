#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


void dfs(int n, unordered_map<int,pair<bool,vector<int>>> &m){
    if(!m[n].first){
        m[n].first=true;
        for (int i = 0; i < m[n].second.size(); i++){
        
            dfs(m[n].second[i],m);
        }
    }
}

int solve(int A, vector<vector<int> > &B) {

    unordered_map<int,pair<bool,vector<int>>> m;
    for (int i = 0; i < B.size(); i++){
        
        if(m.find(B[i][0])==m.end()){
            m[B[i][0]] = {false,{B[i][1]}};
        }
        else{
            m[B[i][0]].second.push_back(B[i][1]);
        }
        
    }


    dfs(1,m);
    return m[A].first;


}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
    {1, 4},
    {2, 1},
    {4, 3},
    {4, 5},
    {2, 3},
    {2, 4},
    {1, 5},
    {5, 3},
    {2, 5},
    {5, 1},
    {4, 2},
    {3, 1},
    {5, 4},
    {3, 4},
    {1, 3},
    {4, 1},
    {3, 5},
    {3, 2},
    {5, 2}
    };

    cout<<solve(5,v)<<endl;
    
    return 0;
}