#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 10003
#define pb push_back

int solve(string A) {
    unordered_map<char,bool> vowel = {{'a',true},{'o',true},{'e',true},{'i',true},{'u',true}};
    int ans=0;
    for (int i = 0; i < A.size(); i++){
    
        if(vowel.find(tolower(A[i]))!=vowel.end())
            ans= (ans + (A.size()-i)%mod)%mod;
    }
    return ans;
}

int main(int argc, char const *argv[])
{

    string s;
    cin>>s;
    
    cout<<solve(s)<<endl;

    return 0;
}