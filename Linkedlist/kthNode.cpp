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

int solve(ListNode* A, int B) {

    ListNode* curr = A;
    if(curr==nullptr)
        return -1;
    
    int n=0;
    while(curr!=nullptr){
        curr=curr->next;
        n+=1;
    }

    n=(n/2)+1-B;
    if(n<0)
        return -1;

    curr=A;
    int i=0;
    while(i<n){
        curr=curr->next;
        i+=1;
    }
    return curr->val;

}

int main(int argc, char const *argv[])
{
    return 0;
}