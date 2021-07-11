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


int maxDepth(TreeNode* A) {

    if(A==nullptr)
        return 0;
    return max(maxDepth(A->left),maxDepth(A->right))+1;
}

int main(int argc, char const *argv[])
{
    return 0;
}