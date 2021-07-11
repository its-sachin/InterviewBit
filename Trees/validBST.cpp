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

int isValidBST(TreeNode* A) {
    if(A==nullptr)
        return 1;
    
    if(A->left){
        if(A->val<A->left->val)
            return 0;
        if(A->right){
            if(A->val>A->right->val)
                return 0;
            return isValidBST(A->left)&isValidBST(A->right);
        }
        isValidBST(A->left);
    }

    if(A->right){
        if(A->val>A->right->val)
            return 0;
        return isValidBST(A->right);
    }
    return 1;

}

int main(int argc, char const *argv[])
{
    return 0;
}