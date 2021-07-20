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



vector<int> solve(TreeNode* A) {

    vector<int> ans;
    if(!A)
        return ans;

    queue<TreeNode*> q;
    stack<int> s;
    q.push(A);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        s.push(curr->val);
        if(curr->right)
            q.push(curr->right);
        if(curr->left)
            q.push(curr->left);
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

}

int main(int argc, char const *argv[])
{
    return 0;
}