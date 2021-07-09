#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution{

public:
int solve(vector<int> &A, int B) {
    unordered_map<int,int> m;
    for (int i = 0; i < A.size(); i++){
    
        m.insert({A[i],i});
    }

    for (int i = 0; i < A.size(); i++){
    
        if((m.find(A[i]-B)!=m.end() and m.at(A[i]-B)!=i) || (m.find(A[i]+B)!=m.end() and m.at(A[i]+B)!=i))
            return 1;
    }
    return 0;
}

};

int main(int argc, char const *argv[])
{
    vector<int> v = {5, 10, 3, 2, 50, 80};
    int b= 78;

    Solution o;
    cout<<o.solve(v,b)<<endl;
    
    return 0;
}