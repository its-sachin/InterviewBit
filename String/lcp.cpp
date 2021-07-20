#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

string longestCommonPrefix(vector<string> &A) {

    string ans="";

    if(A.size()==0)
        return ans;
    if(A.size()==1)
        return A[0];

    int m=INT32_MAX;
    for (int i = 0; i < A.size(); i++){
    
        m=min(m,(int)A[i].size());
    }

    for (int i = 0; i < m; i++){
    
        bool done =true;
        char c = A[0][i];
        for (int j = 1; j < A.size(); j++){
        
            if(A[j][i]!=c){
                done =false;
                break;
            }
        }

        if(!done)
            return ans;
        ans.push_back(c);
    }
    return ans;


}


int main(int argc, char const *argv[])
{
    return 0;
}