#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

unordered_map<string, bool> dp;


int isScramble(const string A, const string B) {

    if(A.size()!=B.size())
        return 0;
    if(A==B)
        return 1;

    int n = A.size();

    if(n<2)
        return 0;

    string key = A;
    key.push_back(' ');
    key.append(B);

    if(dp.find(key) != dp.end())
        return dp.at(key);

    for (int i = 1; i < n; i++){

        if((isScramble(A.substr(0,i),B.substr(0,i)) and isScramble(A.substr(i,n-i), B.substr(i,n-i)))
        or (isScramble(A.substr(i,n-i),B.substr(0,n-i)) and isScramble(A.substr(0,i), B.substr(n-i,i)))){
            dp.insert({key,true});
            return 1;
        }
    }
    dp.insert({key,false});
    return 0;

}


int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    string A;
    cin>>A;
    
    cout<<isScramble(s,A)<<endl;
    return 0;
}