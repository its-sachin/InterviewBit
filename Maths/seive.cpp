#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution{


vector<int> Solution::sieve(int n){
    int* spf = new int[n+1];
    for (int i=0; i<=n; i++){
        spf[i]=i;
    }
    int i=2;
    while(i*i<=n){
        if(spf[i]==i){
            int j=i*i;
            while(j<=n){
                spf[j]=i;
                j+=i;
            }
        }
        i+=1;
    }

    vector<int> ans;
    
    for(int i=0; i<=n; i++){
        if(spf[i]==i){
            ans.push_back(i);
        }
    }
    return ans;
}

};



int main(int argc, char const *argv[])
{
    return 0;
}