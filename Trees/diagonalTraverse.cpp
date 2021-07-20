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

void rec(TreeNode* A, vector<vector<int>> &a, int level){
    if(A){
        if(a.size()>=level)
            a.push_back({});
        a[level].push_back(A->val);
        rec(A->left,a,level+1);
        rec(A->right,a,level);
    }
}

vector<int> solve(TreeNode* A) {
    vector<vector<int>> levels;
    rec(A,levels,0);
    
    vector<int> ans;
    for (int i = 0; i < levels.size(); i++){
    
        for (int j = 0; j < levels[i].size(); j++){
        
            ans.push_back(levels[i][j]);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}