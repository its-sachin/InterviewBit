#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> solve(TreeNode* A, int B) {

    vector<int> ans;
    if(!A)
        return ans;

    vector<vector<pair<int,int>>> v;

    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({A,{0,-1}});
    int val=-1;

    while(!q.empty()){

        pair<TreeNode*,pair<int,int>> curr = q.front();
        q.pop();

        if(v.size()<curr.second.first+1)
            v.push_back({});

        if(val != -1 and v.size()>val+1)
            break;

        if(curr.first->val==B)
            val=curr.second.first;

        v[curr.second.first].push_back({curr.first->val,curr.second.second});

        if(curr.first->left)
            q.push({curr.first->left,{curr.second.first+1,curr.first->val}});
        if(curr.first->right)
            q.push({curr.first->right,{curr.second.first+1,curr.first->val}});
    }


    for (int i = 0; i < v[val].size(); i++){
    
        ans.push_back(v[val][i].first);
        if(v[val][i].first==B){
            ans.pop_back();
            if(i>0 and v[val][i].second==v[val][i-1].second){
                ans.pop_back();
            }
            else if(i<v[val].size() and v[val][i].second==v[val][i+1].second)
                i+=1;
        }
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    return 0;
}