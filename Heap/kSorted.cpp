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

 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(10101);
        ListNode* ansN = ans;
        while(l1 != nullptr and l2 != nullptr){
            if(l1->val>=l2->val){
                while(l2!=nullptr and l1->val>=l2->val){
                    ansN->next = l2;
                    ansN = ansN->next;
                    l2 = l2->next;
                }
            }
            if(l2!= nullptr and l2->val>=l1->val){
                while(l1!=nullptr and l2->val>=l1->val){
                    ansN->next = l1;
                    ansN = ansN->next;
                    l1 = l1->next;
                }
            }
        }

        if(l1!=nullptr){
            while(l1!=nullptr){
                ansN->next = l1;
                ansN = ansN->next;
                l1 = l1->next;
            }
        }

        if(l2!=nullptr){
            while(l2!=nullptr){
                ansN->next = l2;
                ansN = ansN->next;
                l2 = l2->next;
            }
        }

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0){
            return nullptr;
        }

        else if(lists.size()==1){
            return lists[0];
        }

        ListNode* prev = mergeTwoLists(lists[0],lists[1]);
        for (int i = 2; i < lists.size(); i+=2){
            if(i==lists.size()-1){
                prev = mergeTwoLists(prev,lists[i]);
                continue;
            }
            prev = mergeTwoLists(prev,mergeTwoLists(lists[i],lists[i+1]));
        }
        return prev;
    }




int main(int argc, char const *argv[])
{
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(10);
    ListNode* c = new ListNode(20);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(11);
    ListNode* f = new ListNode(13);
    ListNode* g = new ListNode(3);
    ListNode* h = new ListNode(8);
    ListNode* i = new ListNode(9);

    a->next = b;
    b->next = c;

    d->next = e;
    e->next = f;

    g->next = h;
    h->next = i;
    
    vector<ListNode*> v = {nullptr, a};
    ListNode* j = mergeKLists(v);

    while(j!=nullptr){
        cout<<j->val<<"->";
        j=j->next;
    }
    cout<<""<<endl;
    return 0;
}