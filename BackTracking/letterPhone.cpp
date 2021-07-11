#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<string> letterCombinations(string digits) {
    unordered_map<int,vector<char>> phone = {{48,{'0'}},{49,{'1'}},{50,{'a','b','c'}},{51,{'d','e','f'}},{52,{'g','h','i'}},{53,{'j','k','l'}},{54,{'m','n','o'}},{55,{'p','q','r','s'}},{56,{'t','u','v'}},{57,{'w','x','y','z'}}};
        vector<string> ans;
        if(digits=="")
            return ans;
        for(int k=0;k<phone.at(int(digits[0])).size();k++){
            ans.push_back(string(1,phone.at(int(digits[0]))[k]));
        }
        for(int i=1; i<digits.size(); i++){
            int s = ans.size();
            for(int j=0;j<s;j++){
                for(int k=1;k<phone.at(int(digits[i])).size();k++){
                    ans.push_back(ans[j]+phone.at(int(digits[i]))[k]);
                }
                ans[j].push_back(phone.at(int(digits[i]))[0]);
            }
        }
        return ans;
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    vector<string> ans = letterCombinations(s);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
        // code
    }
    return 0;
}