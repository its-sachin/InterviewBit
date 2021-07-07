#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int isPrime(int A) {

    if(A%2==0 || A%3==0)
        return 1;

    int i=5;
    while(i*i<=A){
        if(A%i==0){
            cout<<i<<endl;
            return 1;
        }
        i+=2;
    }    
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    cout<<isPrime(n)<<endl;
    return 0;
}