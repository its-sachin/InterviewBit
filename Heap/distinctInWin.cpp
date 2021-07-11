#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> dNums(vector<int> &A, int B) {
    unordered_map<int,int> u;
    vector<int> v;
    for (int i = 0; i < A.size(); i++){

        if(u.find(A[i])==u.end())
            u.insert({A[i],1});
        else u[A[i]]++;

        if(i>=B-1){

            v.push_back(u.size());
            if(u[A[i-B+1]]==1)
                u.erase(u.find(A[i-B+1]));
            else u[A[i-B+1]]--;
        }

    }
    return v;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 1, 3, 4, 3};
    int b= 3;
    
    vector<int> ans = dNums(v,b);

    for (int i = 0; i < ans.size(); i++){
    
        cout<<ans[i]<<" ";
    }
    cout<<""<<endl;
    return 0;
}