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
};

typedef struct TreeNode treenode;

treenode* treenode_new(int val) {
    treenode* node = (treenode *) malloc(sizeof(treenode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

treenode* getMin(treenode* currRoot){
    if(!currRoot){
        return currRoot;
    }
    treenode* curr = currRoot;
    while(curr->left){
        curr=curr->left;
    }
    return curr;
}

treenode* getSuccessor(treenode* A, int B) {
    if(A==nullptr) return nullptr;

    treenode* lastLeft = nullptr;
    while(A!=nullptr){
        if(A->val<B){
            A=A->right;
        }
        else if(A->val>B){
            if(A->left==nullptr)
                return A;
            lastLeft=A;
            A=A->left;
        }
        else{
            if(A->right)
                return getMin(A->right);
            return lastLeft;
        }
    }
    return lastLeft;
}


int main(int argc, char const *argv[])
{
    return 0;
}