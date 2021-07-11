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

TreeNode* solve(TreeNode* A, TreeNode* B) {

    if(!A) return B;
    if(!B) return A;

    TreeNode* c = new TreeNode(A->val+B->val);
    c->left = solve(A->left,B->left);
    c->right = solve(A->right,B->right);
    return c;
}

int main(int argc, char const *argv[])
{
    return 0;
}