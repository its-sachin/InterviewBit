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

int lPalin(ListNode* A) {

    ListNode* curr = A;
    if(curr==nullptr)
        return 1;
    
    int n=0;
    while(curr!=nullptr){
        curr=curr->next;
        n+=1;
    }

    if(n==1)
        return 1;

    int k = n/2 + n%2;

    int i=1;
    curr=A;
    while(i!=k){
        curr=curr->next;
        i+=1;
    }

    ListNode* temp = curr;
    curr = curr->next;
    ListNode* next = curr->next;
    curr->next = temp;
    temp->next=nullptr;

    while(next!=nullptr){
        ListNode* temp = next->next;
        next->next = curr;
        curr= next;
        next = temp;
    }
    next=A;
    while(next!=nullptr){
        if(curr->val!=next->val)
            return 0;

        curr=curr->next;
        next=next->next;
    }
    return 1;

}

int main(int argc, char const *argv[])
{
    return 0;
}