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

pair<int,int> rec(TreeNode* A){
    if(!A)
        return {0,0};
    
    if(A->left){
        if(A->right){

            pair<int,int> a = rec(A->left);
            pair<int,int> b = rec(A->right);

            int rooted = max(max(a.second+A->val,b.second+A->val),A->val);
            int nRooted = max(max(a.second+b.second+A->val,rooted),max(a.first,b.first));

            cout<<A->val<<" "<<rooted<<" "<<nRooted<<endl;

            return {nRooted,rooted};
        }
        else{
            pair<int,int> a = rec(A->left);
            int rooted = max(a.second+A->val,A->val);
            return {max(a.first,rooted),rooted};
        }
    }
    else if(A->right){
        pair<int,int> a = rec(A->right);
        int rooted = max(a.second+A->val,A->val);
        return {max(a.first,rooted),rooted};
    }

    else{
        return {A->val,A->val};
    }

}

int maxPathSum(TreeNode* A) {

    pair<int,int> p = rec(A);
    cout<<p.first<<" "<<p.second<<endl;
    return max(p.first,p.second);

}

int main(int argc, char const *argv[])
{
    TreeNode* a = new TreeNode(-200);
    TreeNode* b = new TreeNode(-100);
    TreeNode* c = new TreeNode(-300);
    TreeNode* d = new TreeNode(-400);

    a->left = b;
    b->left = c;
    b->right = d;

    cout<<maxPathSum(a)<<endl;
    return 0;
}