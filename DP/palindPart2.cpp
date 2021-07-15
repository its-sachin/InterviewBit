#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int** dp;

bool isPalind(string &A, int l, int h){
    int i=l;
    int j=h;

    while(i<j){
        if(A[i]!=A[j])
            return false;

        i+=1;
        j-=1;
    }
    return true;
}

int rec(string &A, int l, int h){

    if(h-l<1)
        return 0;

    if(dp[l][h]!=-1)
        return dp[l][h];

    if(isPalind(A,l,h)){
        dp[l][h] = 0;
        return 0;
    }

    int m = INT32_MAX;

    for (int i = l+1; i <= h; i++){
        
        m=min(m,rec(A,l,i-1)+rec(A,i,h)+1);
    }

    dp[l][h]=m;
    return m;

}

int minCut(string A) {

    dp = new int*[A.size()];
    for (int i = 0; i < A.size(); i++){
    
        dp[i] = new int[A.size()];
        for (int j = 0; j < A.size(); j++){
        
            dp[i][j]=-1;
        }
    }

    return rec(A,0,A.size()-1);

}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    cout<<minCut(s)<<endl;
    return 0;
}