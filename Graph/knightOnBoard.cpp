#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int ans;

pair<int,int> size;
pair<int,int> final;

void add(pair<int,int> n, unordered_map<string,int> &m,int i){

    cout<<n.first<<" "<<n.second<<" "<<i<<endl;

    string a = to_string(n.first);
    a.push_back(' ');
    a.append(to_string(n.second));
        

    if(m.find(a)==m.end()){

        if(n==final){
            ans=min(ans,i);
        }
        m[a] = i;

        if(n.first-1>0){
            if(n.second-2>0){
                add({n.first-1,n.second-2},m,i+1);
            }
            if(n.second+2<=size.second){
                add({n.first-1,n.second+2},m,i+1);
            }
        }
        if(n.first-2>0){
            if(n.second-1>0){
                add({n.first-2,n.second-1},m,i+1);
            }
            if(n.second+1<=size.second){
                add({n.first-2,n.second+1},m,i+1);
            }
        }

        if(n.first+2<=size.first){
            if(n.second-1>0){
                add({n.first+2,n.second-1},m,i+1);
            }
            if(n.second+1<=size.second){
                add({n.first+2,n.second+1},m,i+1);
            }
        }
        if(n.first+1<=size.first){
            if(n.second-2>0){
                add({n.first+1,n.second-2},m,i+1);
            }
            if(n.second+2<=size.second){
                add({n.first+1,n.second+2},m,i+1);
            }
        }
    }
    else{
        m[a] = min(i,m[a]);
        if(n==final){
            ans=min(ans,m[a]);
        }
    }
}

int knight(int A, int B, int C, int D, int E, int F) {

    size = {A,B};
    final = {E,F};
    ans = INT32_MAX;
    pair<int,int> init = {C,D};

    unordered_map<string,int> m;
    add(init,m,0);  

    cout<<""<<endl;
    for(pair<string,int> p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }

    if(ans==INT32_MAX)
        return -1;
    return ans;
}


int main(int argc, char const *argv[])
{
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<knight(a,b,c,d,e,f)<<endl;
    return 0;
}