#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> allFactors(int A) {
    
    if(A==1)
        return {1};
    vector<int> ans = {1,A};

    int i=2;
    while(i*i<=A){
        if(A%i==0){
            ans.push_back(i);
            if(A/i!=i)
                ans.push_back(A/i);
        }
        i++;
    }
    sort(ans.begin(),ans.end());
    return ans;

}


int main(int argc, char const *argv[])
{
    return 0;
}