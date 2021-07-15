#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int dfs(int node, int c, int col[], vector<vector<int>> &adj){
    col[node]=c;
    for(int child:adj[node]){
        if(col[child]==c) return 0;
        if(col[child]==-1 && dfs(child, (c^1), col, adj)==0) return 0;
    }
    return 1;
}

int solve(int A, vector<vector<int> > &B) {
    
    vector<vector<int>> adj(A+1);


    for (int i = 0; i < B.size(); i++){
    
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    int color[A+1];
    memset(color,-1,sizeof(color));


    for(int i=1; i<=A; i++){
        if(color[i]==-1 && dfs(i, 0, color, adj)==0) return 0;
    }
    return 1;
}


int solve1(int A, vector<vector<int> > &B) {

    vector<vector<int>> adj(A+1);


    for (int i = 0; i < B.size(); i++){
    
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }

    int color[A+1];
    memset(color,-1,sizeof(color));

    queue<int> q;
    

    for (int i = 1; i <= A; i++){
    
        if(color[i]==-1){
            q.push(i);

            color[i]=1;

            while(!q.empty()){

                int k = q.front();
                q.pop();

                for(int n: adj[k]){

                    if(color[n]==-1){
                        color[n]=1-color[k];
                        q.push(n);
                    }
                    if(color[n]==color[k]){
                        return 0;
                    }
                }
            }
        }
    }

    return 1;

}


int main(int argc, char const *argv[])
{
    int A = 11;
    vector<vector<int>> B = {
    {8, 7},
  {8, 6},
  {8, 2},
  {4, 9},
  {11, 10},
  {5, 10},
  {1, 10},
  {3, 7},
  {3, 6},
  {11, 7},
  {5, 7},
  {1, 6},
  {3, 2},
  {8, 9},
  {4, 10},
  {5, 6},
  {4, 7},
  {4, 6}
    };

    cout<<solve(A,B)<<endl;
    return 0;
}