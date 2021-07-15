#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<vector<int> > solve(int K, vector<vector<int> > &A) {

    vector<vector<int>> ans;

    if(A.size()==0)
        return ans;

    int dp[A.size()][A[0].size()][K+1];

    for (int i = 0; i < A.size(); i++){
    
        for (int j = 0; j < A[i].size(); j++){
        
            dp[i][j][0] = A[i][j];
        }
    }


    for (int k = 1; k <= K; k++){
    
        for (int i = 0; i < A.size(); i++){
    
            for (int j = 0; j < A[i].size(); j++){

                int a1 = INT32_MIN;
                int a2 = INT32_MIN;
                int a3 = INT32_MIN;
                int a4 = INT32_MIN;

                if(i>0)
                    a1=dp[i-1][j][k-1];
                if(i<A.size()-1)
                    a2 = dp[i+1][j][k-1];
                if(j>0)
                    a3 = dp[i][j-1][k-1];
                if(j<A[i].size()-1)
                    a4 = dp[i][j+1][k-1];
            
                dp[i][j][k] = max(max(max(a1,a3),max(a2,a4)),A[i][j]);
            }
        }
    }

    for (int i = 0; i < A.size(); i++){
        
        vector<int> a;
        for (int j = 0; j < A[i].size(); j++){
        
            a.push_back(dp[i][j][K]);
        }
        ans.push_back(a);
    }
    return ans;
    
}


int main(int argc, char const *argv[])
{
    int k=2;
    vector<vector<int>> v = {{1,2,4},{4,5,8}};
    
    vector<vector<int>> a = solve(k,v);

    for (int i = 0; i < a.size(); i++){
        
        for (int j = 0; j < a[i].size(); j++){
        
            cout<<a[i][j]<<", ";
        }
        cout<<""<<endl;
        
    }
    
    return 0;
}