#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

string convert(string s, int numRows) {
    
    int n = numRows-1;

    if(n==0){
        return s;
    }
    
    int l = s.size();
    string ans = "";

    int i=0;
    while(i*n<l){
        ans.push_back(s[n*i]);
        i+=2;
    }

    
    for (int i = 1; i < n; i++){
        if(i>=l){
            return ans;
        }
        ans.push_back(s[i]);
        int j=2;

        while(j*n-i<l){
            ans.push_back(s[j*n-i]);
            if(j*n+i<l)
                ans.push_back(s[j*n+i]);
            j+=2;
        }
    }

    i=1;
    while(i*n<l){
        ans.push_back(s[n*i]);
        i+=2;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}