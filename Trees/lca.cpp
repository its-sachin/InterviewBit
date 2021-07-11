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

vector<int> solverec(TreeNode* A, int B){
    vector<int> v;
    if(A==nullptr) return v;
    if(A->val==B){
        v.push_back(B);
        return v;
    }
    vector<int> v1 = solverec(A->left,B);
    if(v1.size()!=0){
        v.push_back(A->val);
        for (int i = 0; i < v1.size(); i++){
            v.push_back(v1[i]);
        }
        return v;
    }
    v1 = solverec(A->right,B);
    if(v1.size()!=0){
        v.push_back(A->val);
        for (int i = 0; i < v1.size(); i++){
            v.push_back(v1[i]);
        }
        return v;
    }
    return v;
}

int lca(TreeNode* A, int B, int C) {
    vector<int> p1 = solverec(A,B);
    vector<int> p2 = solverec(A,C);

    int i=0;
    while(p1[i]==p2[i]) i++;
    return p1[i-1];
    
}

int main(int argc, char const *argv[])
{
    return 0;
}