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

vector<int> postorderTraversal(TreeNode* A) {

    stack<TreeNode*> s;
    vector<int> v;
    
    if(A)
        s.push(A);
    TreeNode* p = nullptr;
    while(!s.empty()){
        
        TreeNode* top = s.top();

        if(p==nullptr or p->left==top or p->right == top){
            
            if(top->left)
                s.push(top->left);
            else if(top->right)
                s.push(top->right);
            else{
                s.pop();
                v.push_back(top->val);
            }
        }

        else if(top->left==p){
            if(top->right)
                s.push(top->right);

            else{
                s.pop();
                v.push_back(top->val);
            }
        }

        else if(top->right==p){
            s.pop();
            v.push_back(top->val);
        }
        p=top;
    }
    return v;
}

int main(int argc, char const *argv[])
{
    return 0;
}