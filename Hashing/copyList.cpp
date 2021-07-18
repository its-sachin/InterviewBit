#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyRandomList(RandomListNode* A) {


    if(!A)
        return nullptr;

    unordered_map<RandomListNode* ,RandomListNode*> m;
    RandomListNode* root = new RandomListNode(A->label);

    RandomListNode* cop = root;
    m.insert({A,cop});

    if(A->random){
        if(A->random==A)
            cop->random = cop;
        else{
            cop->random = new RandomListNode(A->random->label);
            m[A->random]=cop->random;
        }
    }

    A=A->next;
    while(A!=nullptr){

        if(m.find(A)==m.end()){
            cop->next= new RandomListNode(A->label);
            m[A] = cop->next;
        }
        else{
            cop->next=m[A];
        }

        cop=cop->next;

        if(A->random){
            if(m.find(A->random) ==m.end()){
                cop->random = new RandomListNode(A->random->label);
                m[A->random] = cop->random;
            }
            else{
                cop->random = m[A->random];
            }
        }

        A=A->next;
    }

    return root;

}

int main(int argc, char const *argv[])
{
    RandomListNode* a[14];
    int ar[14] = {83 ,188 ,253 ,281, 254, 56, 70 ,3, 276, 233, 280 ,224 ,16, 173};

    a[0] = new RandomListNode(ar[0]);
    for (int i = 1; i < 14; i++){

        a[i] = new RandomListNode(ar[i]);
        a[i-1]->next=a[i];
    }
    // RandomListNode* a = new RandomListNode(83);
    // RandomListNode* b = new RandomListNode(188);
    // RandomListNode* c = new RandomListNode(253);
    // RandomListNode* d = new RandomListNode(281);

    // a->next =b;
    // a->random = b;

    // b->next = c;
    // b->random = d;

    // c->next = d;
    // c->random = a;

    // d->random = d;

    RandomListNode* ans = copyRandomList(a[0]);

    RandomListNode* curr = ans;
    while(curr!=nullptr){
        cout<<curr->label<<"->";
        curr=curr->next;
    }

    cout<<""<<endl;

    while(ans!=nullptr){
        if(ans->random)
            cout<<ans->label<<" : "<<ans->random->label<<endl;
        else
            cout<<ans->label<<" : NULL"<<endl;
        ans=ans->next;
    }
    return 0;
}