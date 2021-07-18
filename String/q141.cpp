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

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(true){
            if(fast == nullptr or fast->next == nullptr)
                return false;
            if(slow==fast)
                return true;

            slow=slow->next;
            fast=fast->next->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}