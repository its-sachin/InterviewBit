#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int pow( int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    long long int one =(x+d)%d;

    if(one==0)
        return 0;

    if(n==0)
        return 1;

    long long int ans=1;
    while(n>0){
        if(n&1){
            ans = (one*ans)%d;
        }
        one=(one*one)%d;
        n=n>>1;
    }
    return ans;
}

int pow1(int x, int n, int d) {

    long long int ans = (x+d)%d;
    int left = 1;
    if(ans==0)
        return 0;

    if(n==0){
        return 1;
    }

    while(n>1){
        if(n%2==1){
            left=(left*ans)%d;
        }
        ans = (ans*ans)%d;
        n=n/2;
    }
    return (ans*left)%d;
}


int main(int argc, char const *argv[])
{
    while(true){
        int x = (rand())%1000000000;
        int n = (rand())%1000000000;
        int d = (rand())%15000000+2;
        // int d = mod;
        
        cout<<"x = "<<x<<endl;
        cout<<"n = "<<n<<endl;
        cout<<"d = "<<d<<"\n"<<endl;

        int o = pow(x,n,d);
        int t = pow1(x,n,d);
        cout<<"correct ans = "<<o<<endl;
        cout<<"your ans = "<<t<<"\n\n"<<endl;

        if(o!=t){
            cout<<"wrong code!!"<<endl;
            break;
        }
    }
    

    
    return 0;
}