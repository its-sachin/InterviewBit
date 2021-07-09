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

ListNode* reverseList(ListNode* A) {
    ListNode* c = A;
    if(c==nullptr)
        return nullptr;

    ListNode* next = c->next;
    c->next = nullptr;
    while(next!=nullptr){
        ListNode* temp = next->next;
        next->next = c;
        c= next;
        next = temp;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    return 0;
}