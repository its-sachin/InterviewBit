#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

long long int hashh(const string &s,long long int* power){
    long long int hPat=0;
    for (int i = 0; i < s.size(); i++){
        hPat = (hPat + power[s[i]-'a'+1])%mod;
    }
    return hPat;
}

vector<vector<int> > anagrams(const vector<string> &strs) {

    int base = 100007;
    long long int power[27];
    long long int mt=1;
    int i=0;
    while(i<27){
        power[i]=mt;
        mt=base*(mt)%mod;
        i+=1;
    }
    
    unordered_map<int,int> m;
    vector<vector<int>> ans;
    
    int j=0;
    for (int i = 0; i < strs.size(); i++){

        long long h = hashh(strs[i],power);
        if(m.find(h) == m.end()){
            m.insert({h,j});
            ans.push_back({i+1});
            j+=1;
        }
        else{
            ans[m[h]].push_back(i+1);
        }
    }
    return ans;

}


int main(int argc, char const *argv[])
{
    return 0;
}