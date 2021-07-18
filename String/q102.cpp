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



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root)
            return ans;

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            pair<TreeNode* ,int> p =q.front();
            q.pop();

            if(ans.size()==p.second)
                ans.push_back({});
            
            ans[p.second].push_back(p.first->val);

            if(p.first->left)
                q.push({p.first->left,p.second+1});
            if(p.first->right)
                q.push({p.first->right,p.second+1});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}