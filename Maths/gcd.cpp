#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int gcd(int A, int B) {

    if(A==0)
        return B;
    else if (B==0)
        return A;
    while(A!=B){
        if(A>B)
            A=A-B;
        else 
            B=B-A;
    }
    return A;

}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;

    int m;
    cin>>m;
    
    
    cout<<gcd(n,m)<<endl;
    return 0;
}