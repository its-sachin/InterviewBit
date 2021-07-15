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



vector<vector<int> > levelOrder(TreeNode* A) {

    vector<vector<int>> ans; 
    if(!A)
        return ans;


    queue<pair<TreeNode*,int>> q;
    vector<int> v;

    q.push({A,0});
    
    
    while(!q.empty()){
        
        pair<TreeNode*,int> curr = q.front();

        int l = curr.second;

        if(ans.size()!=l+1){
            ans.push_back(v);
        }

        ans[l].push_back(curr.first->val);

        if(curr.first->left)
            q.push({curr.first->left,l+1});
            
        if(curr.first->right)
            q.push({curr.first->right,l+1});


        q.pop();

    }

    return ans;

}


int main(int argc, char const *argv[])
{
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;

    vector<vector<int>> ans = levelOrder(a);

    for (int i = 0; i < ans.size(); i++){
    
        for (int j = 0; j < ans[i].size(); j++){
        
            cout<<ans[i][j]<<" ";   
        }
        cout<<""<<endl;
    }
    return 0;
}