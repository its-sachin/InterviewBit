#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<string> rec(string &A, int l, unordered_map<string,bool> &m){

    vector<string> ans;
    if(l>=A.size())
        return ans;

    string a = "";
    for (int i = l; i < A.size()-1; i++){
        a.push_back(A[i]);

        if(m.find(a)!=m.end()){
            vector<string> b = rec(A,i+1,m);
            for (int j = 0; j < b.size(); j++){
                ans.push_back(a+" "+b[j]);
            }
        }
    }   

    a.push_back(A.back());
    if(m.find(a)!=m.end())
        ans.push_back(a);
    return ans;
}

vector<string> wordBreak(string A, vector<string> &B) {

    unordered_map<string,bool> m;
    for (int i = 0; i < B.size(); i++){
    
        m[B[i]] = true;
    }

    return rec(A,0,m);

}


int main(int argc, char const *argv[])
{
    string a = "catsanddog";
    vector<string> v = {"cat", "cats", "and", "sand", "dog"};

    vector<string> ans = wordBreak(a,v);
    for (int i = 0; i < ans.size(); i++){
    
        cout<<ans[i]<<endl;
    }
    return 0;
}