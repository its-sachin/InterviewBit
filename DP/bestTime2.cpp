#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int maxProfit(const vector<int> &A) {

    if(A.size()<2)
        return 0;

    int sum=0;
    vector<int> b(A.size()-1);
    for (int i = 0; i < A.size()-1; i++){
    
        b[i]=A[i+1]-A[i];
    }
    for (int i = 0; i < b.size(); i++){
    
        if(b[i]>0)
            sum+=b[i];
    }
    return sum;
}


int main(int argc, char const *argv[])
{
    return 0;
}