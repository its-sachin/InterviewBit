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

vector<int> ans;
int level;
void solveRec(TreeNode* A, int i){

    if(A!=nullptr){
        if(i>=level){
            ans.push_back(A->val);
            level+=1;
        }
        solveRec(A->right,i+1);
        solveRec(A->left,i+1);
    }
}

vector<int> solve(TreeNode* A) {

    ans.clear();
    level=0;
    TreeNode* curr=A;
    while(curr!=nullptr){
        ans.push_back(curr->val);
        level+=1;
        curr=curr->right;
    }

    solveRec(A->right,1);
    solveRec(A->left,1);

    return ans;
}



int main(int argc, char const *argv[])
{
    return 0;
}