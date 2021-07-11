#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

struct ListNode {
    int val;
    ListNode *next = nullptr;
    ListNode(int x) : val(x), next(NULL) {}
};

// void print(ListNode* s){
//     ListNode* curr = s;
//     while(curr!=nullptr){
//         cout<<s->val<<", ";
//         curr=curr->next;
//     }
//     cout<<""<<endl;
// }

vector<int> order1(vector<int> &heights, vector<int> &infronts) {
    map<int,int> a;
    for (int i = 0; i < heights.size(); i++){
        a.insert({heights[i],infronts[i]});
    }


    ListNode* s = new ListNode(a.rbegin()->first);
    a.erase(a.rbegin()->first);

    while(!a.empty()){
        ListNode* n = new ListNode(a.rbegin()->first);
        int in = a.rbegin()->second;
        a.erase(a.rbegin()->first);

        ListNode* curr=s;

        if(in==0){
            s = n;
            s->next = curr;
        }
        else{
            int i=1;
            while(i<in){
                curr=curr->next;
                i+=1;
            }
            ListNode* k= curr->next;
            curr->next = n;
            n->next = k;
        }
    }

    vector<int> ans;
    while(s!=nullptr){
        ans.push_back(s->val);
        s=s->next;
    }
    return ans;


}

vector<int> order2(vector<int> &heights, vector<int> &infronts) {

    map<int,int> a;
    for (int i = 0; i < heights.size(); i++){
        a.insert({heights[i],infronts[i]});
    }

    vector<int> ans(heights.size(),-1);
    for(auto iter : a){

        int i = 0;
        int j = 0;
        while(i != iter.second)
        {
            if(ans[j] == -1)
                i++;
            j++;
        }
        while(ans[j] != -1)
        {
            j++;
        }
        ans[j] = iter.first;
    }
}

class SegTree{
    public:
        int n;
        int *tree;
        
        SegTree(int nn){
            n=nn;
            tree=new int[5*nn+5];
            memset(tree,0,sizeof(tree));
            build(0,n-1,0);
        }
        
        int build(int l,int r,int i){
            if(l>r) return 0;
            if(l==r) {
                tree[i]=1;
                return 1;
            }
            int mid=(l+r)/2;
            int L=build(l,mid,left(i));
            int R=build(mid+1,r,right(i));
            tree[i]=L+R;
            return tree[i];
        }
        
        int update(int i,int value,int l,int r,int index){
            if(l>r) return 0;
            if(l==r) {
                tree[index]=value;
                return value;
            }
            int mid=(l+r)/2;
            int L=0,R=0;
            if(i<=mid) L=update(i,value,l,mid,left(index));
            else R=update(i,value,mid+1,r,right(index));
            
            return tree[index]=tree[left(index)] + tree[right(index)];
        }
        
        int query(int spaces,int l,int r,int i){
            if(l>r) return -1;
            int left_spaces=tree[left(i)];
            int right_spaces=tree[right(i)];
            
            if(l==r) return l;
            
            if(left_spaces>=spaces) {
                return query(spaces,l,(l+r)/2,left(i));
            }
            else {
                return query(spaces-left_spaces,(l+r)/2+1,r,right(i));
            }
        }
        
        int left(int i){
            return 2*i+1;
        }
        
        int right(int i){
            return 2*i+2;
        }
};

vector<int> order(vector<int> &heights, vector<int> &infronts) {
    
    vector< pair<int,int> > v;
    int n=heights.size();
    vector<int> ans(n);
    
    for(int i=0;i<n;i++){
        v.push_back(make_pair(heights[i],infronts[i]));
    }
    
    sort(v.begin(),v.end());
    
    SegTree s(n);
    
    for(int i=0;i<n;i++){
        int index=s.query(v[i].second+1,0,n-1,0); 
        ans[index]=v[i].first;
        s.update(index,0,0,n-1,0);
    }
    
    return ans;
}



int main(int argc, char const *argv[])
{
    vector<int> v = {5, 3, 2, 6, 1, 4};
    vector<int> a = {0, 1, 2, 0, 3, 2}; 

    vector<int> ans = order(v,a);

    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<""<<endl;
    
    
    return 0;
}