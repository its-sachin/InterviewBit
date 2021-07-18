#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int divide(int dividend, int divisor) {

    long long int t=1;
    int sign=1;
    if(signbit(dividend) != signbit(divisor))
        sign=-1;
    
    long long int div=abs(divisor);

    long long ans=0,temp=0;

    if(dividend==INT32_MIN){
        if(divisor==1)
            return INT32_MIN;
        if(divisor==-1)
            return INT32_MAX;
        if(divisor==INT32_MIN)
            return 1;
        else{
            dividend+=div;
            ans+=1;
        }
    }

    long long int di=abs(dividend);

    for(int i=31;i>=0;i--)
    {    
        if(temp+(div<<i)<=di)
        {
            ans=ans+ (t<<i);
            temp=temp+(div<<i); 
            
        }
    
    }
    ans=ans*sign;
    if(ans>=INT32_MAX || ans<=INT32_MIN)
        return INT_MAX;
    return ans;
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    int a;
    cin>>a;
    
    cout<<divide(n,a)<<endl;
    return 0;
}