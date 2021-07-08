#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int sqrt(int A) {
    int low =0;
    int high = A;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mid*mid==A){
            return mid;
        }
        else if(mid*mid<A){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    cout<<sqrt(n)<<endl;
    return 0;
}