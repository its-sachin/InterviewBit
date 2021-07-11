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

TreeNode* buildRec(vector<int> &A, int l, int r){
    if(l>r) return nullptr;
    if(l==r){
        TreeNode* c = new TreeNode(A[l]);
        return c;
    }

    int maxAr[r-l+1];
    maxAr[0]=A[l];
    for (int i = l+1; i <=r; i++){
    
        maxAr[i-l]=max(maxAr[i-1-l],A[i]);
    }
    int i;
    for (i = r; i >l; i--){
    
        if(maxAr[i-1-l]!=maxAr[i-l])
            break;
    }
    
    TreeNode* root = new TreeNode(A[i]);
    root->left = buildRec(A,l,i-1);
    root->right = buildRec(A,i+1,r);

    return root;
}


TreeNode* buildTree(vector<int> &A) {

    
    return buildRec(A,0,A.size()-1);
    
}


int main(int argc, char const *argv[])
{
    vector<int> a = {2,1,3};
    TreeNode* ans = buildTree(a);


    return 0;
}