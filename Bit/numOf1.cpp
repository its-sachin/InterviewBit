#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int numSetBits(unsigned int A) {
    
    int c=0;
    while(A>0){
        if(!A&1)
            c+=1;
        A>>=1;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    return 0;
}