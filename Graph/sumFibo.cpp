#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int fibsum(int A) {

    int i=1;
    int j=1;
    while(j<A){
        int t=i;
        i=j;
        j=t+j;
    }

    if(i==A or j==A)
        return 1;

    return 1+fibsum(A-i);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    cout<<fibsum(n)<<endl;
    
    return 0;
}