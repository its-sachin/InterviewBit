#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* toBST(ListNode* head, ListNode* tail){
    ListNode* slow = head;
    ListNode* fast = head;
    if(head==tail) return nullptr;

    while(fast!=tail&&fast->next!=tail){
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode* thead = new TreeNode(slow->val);
    thead->left = toBST(head,slow);
    thead->right = toBST(slow->next,tail);
    return thead;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(head==nullptr) return nullptr;
    return toBST(head,nullptr);
}
    

void inorder(TreeNode* t){
    if(t){
        cout<<t->val<<" ";
        inorder(t->left);
        inorder(t->right);
    }
}

int main(int argc, char const *argv[])
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(4);
    ListNode* c = new ListNode(8);
    a->next=b;
    b->next=c;


    TreeNode* t = sortedListToBST(a);
    inorder(t);
    return 0;
}