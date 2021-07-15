#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

unordered_map<int,UndirectedGraphNode *> all;


UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {

    UndirectedGraphNode* n = new UndirectedGraphNode(node->label);
    all[node->label] = n;
    for (int i = 0; i < node->neighbors.size(); i++){
        
        if(all.find(node->neighbors[i]->label)==all.end()){
            n->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        else{
            n->neighbors.push_back(all[node->neighbors[i]->label]);
        }
       
    }

    return node;
    
}

int main(int argc, char const *argv[])
{
    UndirectedGraphNode* a = new UndirectedGraphNode(10);
    UndirectedGraphNode* b = new UndirectedGraphNode(20);
    UndirectedGraphNode* c = new UndirectedGraphNode(30);
    UndirectedGraphNode* d = new UndirectedGraphNode(40);
    a->neighbors.push_back(b);
    b->neighbors.push_back(a);

    a->neighbors.push_back(c);
    c->neighbors.push_back(a);

    c->neighbors.push_back(d);
    d->neighbors.push_back(c);

    UndirectedGraphNode* g = cloneGraph(a);

    for (int i = 0; i < g->neighbors.size(); i++){
        
        cout<<g->neighbors[i]->label<<endl;
    }

    cout<<""<<endl;
    UndirectedGraphNode* h = g->neighbors[0];

    for (int i = 0; i < h->neighbors.size(); i++){
        
        cout<<h->neighbors[i]->label<<endl;
    }

    cout<<""<<endl;
    UndirectedGraphNode* l = g->neighbors[1];

    for (int i = 0; i < l->neighbors.size(); i++){
        
        cout<<l->neighbors[i]->label<<endl;
    }
    return 0;
}