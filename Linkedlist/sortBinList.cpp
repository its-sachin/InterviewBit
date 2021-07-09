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


ListNode* solve(ListNode* A) {

    ListNode* end = A;
    if(end==nullptr)
        return nullptr;
    while(end->next!=nullptr)
        end=end->next;

    ListNode* stop = end;
    ListNode* curr = A;
    ListNode* prev = nullptr;
    ListNode* ans = nullptr;
    while(curr!=stop){
        if(curr->val == 1){
            end->next = curr;
            end=curr;
            if(prev)
                prev->next = curr->next;
            ListNode* temp = curr->next;
            curr->next = nullptr;
            curr=temp;
        }
        else{
            if(!ans) ans = curr;
            prev=curr;
            curr=curr->next;
        }
    }
    if(!ans) return stop;
    return ans;
}


int main(int argc, char const *argv[])
{
    return 0;
}