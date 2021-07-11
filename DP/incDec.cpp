#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int inter(int i, int j, int isdec, const vector<int> &A, int*** dp){
    if(j>=A.size())
        return 0;

    int b = dp[i][j+1][isdec];
    if(b==-1){
        b=inter(i,j+1,isdec,A,dp);
        dp[i][j+1][isdec] = b;
    }

    if(isdec){
        if(A[j]<A[i]){
            int c = dp[j][j+1][isdec];
            if(c==-1){
                c=inter(j,j+1,isdec,A,dp);
                dp[j][j+1][isdec] = c;
            }
            return max(c+1,b);
        }
        return b;
    }

    else{

        if(A[j]>A[i]){

            int k = dp[i][j+1][1];
            if(k==-1){
                k = inter(i,j+1,1,A,dp);
                dp[i][j+1][1] = k;
            }

            int c = dp[j][j+1][isdec];
            if(c==-1){
                c=inter(j,j+1,isdec,A,dp);
                dp[j][j+1][isdec] = c;
            }
            return max(c+1,max(b,k));
        }
        if(A[j]==A[i]){
            return b;
        }
        else{
            int l = dp[j][j+1][1];
            if(l==-1){
                l = inter(j,j+1,1,A,dp);
                dp[j][j+1][1] = l;
            }
            return max(l+1,b);
        }
    }
}

int longestSubsequenceLength1(const vector<int> &A) {

    if(A.size()<2)
        return A.size();

    int*** dp = new int**[A.size()+1];
    for (int i = 0; i <= A.size(); i++){
    
        dp[i] = new int*[A.size()+1];
        for (int j = 0; j <= A.size(); j++){
            dp[i][j] = new int[2];
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
        dp[i][i][0]=1;
        dp[i][i][1]=1;
    }

    int ans = INT32_MIN;
    for (int i = 0; i < A.size(); i++){
        ans=max(ans,inter(i,i+1,0,A,dp)+1);
    }
    return ans;
}

int longestSubsequenceLength(const vector<int> &A) {

    int n=A.size();
    
    vector<int> lis(n,1);
    vector<int> lds(n,1);

    for(int i=1;i<n;i++){

        for(int j=0;j<i;j++){
            if(A[i]>A[j])
                lis[i] = max(lis[j]+1,lis[i]);
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(A[i]>A[j])
                lds[i]=max(lds[i],lds[j]+1);
        }
    }

    int ans=0;

    for(int i=0;i<n;i++)
        ans=max(ans,lis[i]+lds[i]-1);
        
    return ans;

}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,1,1,1};
    cout<<longestSubsequenceLength(v)<<endl;
    return 0;
}