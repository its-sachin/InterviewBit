#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back



int isInterleave(string A, string B, string C) {


    bool dp[A.size()+1][B.size()+1] = {false};

    for (int i = 0; i <= A.size(); i++){
    
        for (int j = 0; j <= B.size(); j++){
        
            if(i==0){
                if(j==0){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=(B[j-1]==C[j-1]);
                }
            }
            else{
                if(j==0){
                    dp[i][j]=(A[i-1]==C[i-1]);
                }
                else{
                    if(A[i-1]==C[i+j-1]){
                        if(B[j-1]==C[i+j-1]){
                            dp[i][j]=dp[i][j-1]||dp[i-1][j];
                        }
                        else{
                            dp[i][j]=dp[i-1][j];
                        }
                    }
                    else if(B[j-1]==C[i+j-1]){
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
    }
    return dp[A.size()][B.size()];

}


int main(int argc, char const *argv[])
{
    string A;
    cin>>A;
    
    string B;
    cin>>B;

    string C;
    cin>>C;
    
    cout<<isInterleave(A,B,C)<<endl;
    return 0;
}