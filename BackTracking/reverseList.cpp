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

ListNode* revRec(ListNode* curr, ListNode* prev){
    
    if(curr == nullptr) return curr;

    ListNode* next = curr->next;
    curr->next = prev;
    if(next==nullptr)
        return curr;
    return revRec(next,curr);
}

ListNode* reverseList(ListNode* A) {
    return revRec(A,nullptr);
    
}

int main(int argc, char const *argv[])
{
    return 0;
}