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


TreeNode* invertTree(TreeNode* A) {
    if(A==nullptr or (A->left==nullptr and A->right==nullptr))
        return A;

    TreeNode* c = new TreeNode(A->val);
    c->left = invertTree(A->right);
    c->right = invertTree(A->left);
    return c;

}

int main(int argc, char const *argv[])
{
    return 0;
}