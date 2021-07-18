#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int candy(vector<int> &A) {

    if(A.size()<=1)
        return A.size();

    int ans[A.size()];

    ans[0]=1;
    for (int i = 0; i < A.size()-1; i++){

        ans[i+1]=1;
        if(A[i+1]>A[i]){
            ans[i+1]=1+ans[i];
        }
    }

    int val=ans[A.size()-1];
    for (int i = A.size()-1; i >0; i--){
    
        if(A[i-1]>A[i]){
            ans[i-1]=max(1+ans[i],ans[i-1]);
        }
        val+=ans[i-1];
    }

    return val;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,5,2,1};
    cout<<candy(v)<<endl;
    return 0;
}