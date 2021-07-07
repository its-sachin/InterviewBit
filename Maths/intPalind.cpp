#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int isPalindrome(int A) {

    if(signbit(A))
        return 0;
    int a = 0;
    int b = A;

    while(A>0){
        a=a*10+A%10;
        A=A/10;
    }
    return a==b;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    cout<<isPalindrome(n)<<endl;
    return 0;
}