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

TreeNode* flatten(TreeNode* A) {

    if(A==nullptr) return nullptr;

    TreeNode* ans = new TreeNode(A->val);
    TreeNode* curr = ans;

    stack<TreeNode*> s;
    if(A->right)
        s.push(A->right);
    if(A->left)
        s.push(A->left);

    while(!s.empty()){

        TreeNode* top=s.top();
        s.pop();
        if(top->right)
            s.push(top->right);
        if(top->left)
            s.push(top->left);

        curr->right = top;
        curr=top;
        curr->left=nullptr;
        curr->right=nullptr;

    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}