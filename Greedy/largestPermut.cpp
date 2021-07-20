#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> solve(vector<int> &A, int B) {

    int pos[A.size()+1];
    for (int i = 0; i < A.size(); i++){
    
        pos[A[i]]=i;
    }

    int sw=0;

    int i=0;
    int k=A.size();
    while(sw<B and i<A.size()){
        if(pos[k]!=i){
            sw+=1;
            pos[A[i]]=pos[k];
            A[pos[k]]=A[i];
            A[i]=k;
        }
        i+=1;
        k--;
    }
    return A;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,3,2,4};
    solve(v,2);

    for (int i = 0; i < v.size(); i++){
    
        cout<<v[i]<<" ";
    }
    cout<<""<<endl;
    
    return 0;
}