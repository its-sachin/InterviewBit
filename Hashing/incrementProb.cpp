#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> solve(vector<int> &A) {
    unordered_map<int,set<int>> m;
    for (int i = 0; i < A.size(); i++){
    
        if(m.find(A[i])!=m.end()){
            int k = *m[A[i]].begin();
            m[A[i]].erase(m[A[i]].begin());
            m[A[i]].insert(i);
            
            if(m.find(A[i]+1)==m.end()){
                set<int> q;
                q.insert(k);
                m.insert({A[i]+1,q});
            }
            else{
                m[A[i]+1].insert(k);
            }
        }
        else{
            set<int> q;
            q.insert(i);
            m.insert({A[i],q});
        }
    }

    for(pair<int,set<int>> p: m){
        while(!p.second.empty()){
            A[*p.second.begin()]=p.first;
            p.second.erase(p.second.begin());
        }
    }


    return A;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 2, 3, 1, 4, 2, 1, 3};
    vector<int> ans = solve(v);

    for (int i = 0; i < ans.size(); i++){
    
        cout<<ans[i]<<" ";
    }
    cout<<""<<endl;
    return 0;
}