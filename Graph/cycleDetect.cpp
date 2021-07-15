#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(int A, vector<vector<int> > &B) {

    if(A<=0)
        return 1;

    vector<vector<int>> adj(A+1);


    for (int i = 0; i < B.size(); i++){
    
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }


    int color[A+1];
    memset(color,-1,sizeof(color));

    queue<pair<int,int>> q;
    

    for (int i = 1; i <= A; i++){
    
        if(color[i]==-1){
            q.push({i,0});

            color[i]=1;

            while(!q.empty()){

                pair<int,int> p = q.front();
                int k= p.first;
                q.pop();

                for(int n: adj[k]){

                    if(n!=p.second){
                        if(color[n]!=-1)
                            return 1;
                        
                        color[n]=1;
                        q.push({n,k});
                    }
                    
                }
            }
        }
    }
    return 0;

}

int main(int argc, char const *argv[])
{
    int a = 2;
    vector<vector<int>> v = {{1,2}};

    cout<<solve(a,v)<<endl;
    
    return 0;
}