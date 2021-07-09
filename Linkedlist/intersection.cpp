#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* getIntUtil(ListNode* A, int size1, ListNode* B, int size2){
    //size1<=size2

    ListNode* curr2 = B;
    while(curr2!= nullptr and size1<size2){
        curr2=curr2->next;
        size2-=1;
    }

    ListNode* curr1 = A;
    while(curr1 !=nullptr and curr2!=nullptr and curr1!=curr2){
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return curr1;

}

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    
    ListNode* curr1 = A;
    int size1=0;
    while(curr1!=nullptr){
        curr1=curr1->next;
        size1+=1;
    }

    ListNode* curr2 = B;
    int size2=0;
    while(curr2!=nullptr){
        curr2=curr2->next;
        size2+=1;
    }
    if(size1<=size2) return getIntUtil(A,size1,B,size2);
    else return getIntUtil(B,size2, A,size1);
}


int main(int argc, char const *argv[])
{
    return 0;
}