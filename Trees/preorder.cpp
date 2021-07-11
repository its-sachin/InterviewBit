#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* A) {

    stack<TreeNode*> s;
    vector<int> v;
    
    if(A)
        s.push(A);
    while(!s.empty()){
        TreeNode* top = s.top();
        v.push_back(top->val);
        s.pop();
        if(top->right) s.push(top->right);
        if(top->left) s.push(top->left);
    }
    return v;
}



int main(int argc, char const *argv[])
{
    return 0;
}