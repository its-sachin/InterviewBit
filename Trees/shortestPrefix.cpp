#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Trie
{

private:   
    
    int words;

public:

    pair<Trie *,bool> edges[26];

    Trie(){

        for (int i = 0; i<26; ++i)
            edges[i] = {NULL,true};
        words = 0;
    }

    void insert(string s){

        int n = s.size();
        Trie *current = this;
        
        for (int i = 0; i<n; ++i){

            current->words += 1;
            if (!current->edges[s[i]-'a'].first){
                current->edges[s[i]-'a'].first = new Trie();
            }
            else{
                current->edges[s[i]-'a'].second = false;
            }
            current = current->edges[s[i]-'a'].first;
        }
    }
};

vector<string> prefix(vector<string> &A) {
    Trie* t = new Trie();
    for (int i = 0; i < A.size(); i++){
    
        t->insert(A[i]);
    }
    vector<string> ans;

    for (int i = 0; i < A.size(); i++){
    
        string cS = "";
        Trie* cT = t;

        int j=0;
        while(cT->edges[A[i][j]- 'a'].second == false){
            cT=cT->edges[A[i][j]-'a'].first;
            cS.push_back(A[i][j]);
            j+=1;
        }
        cS.push_back(A[i][j]);
        ans.push_back(cS);
    }
    return ans;

    
}

int main(int argc, char const *argv[]){

    vector<string> v = {"zebra", "dog", "duck", "dove"};
    vector<string> a = prefix(v);

    for (int i = 0; i < a.size(); i++){
    
        cout<<a[i]<<endl;
    }

    return 0;
}