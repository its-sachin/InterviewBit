#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int singleNumber(const vector<int> &A) {
    unordered_map<int,int> m;
    for (int i = 0; i < A.size(); i++){
    
        if(m.find(A[i])!=m.end()){
            if(m[A[i]]==2)
                m.erase(m.find(A[i]));
            else
                m[A[i]]+=1;
        }
        else{
            m[A[i]]=1;
        }
    }

    return m.begin()->first;
}


int main(int argc, char const *argv[])
{
    return 0;
}