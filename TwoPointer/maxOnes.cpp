#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A, int B) {

    int l=0;
    int r=0;
    int k=0;
    while(r<A.size()){
        if(A[r]==0)
            k+=1;
        if(k==B)
            break;
        r+=1;
    }
    if(r==A.size())
        return A.size();
    
    int m = r-l+1;
    // cout<<"l= "<<l<<" r= "<<r<<" m= "<<m<<endl;
    while(r<A.size()-1){
        if(A[r+1]==0){
            if(k<B){
                k+=1;
                r+=1;
            }
            else{
                if(A[l]==0){
                    l+=1;
                    r+=1;
                }
                else{
                    while(l<r and A[l]==1){
                        l+=1;
                    }
                    if(A[l]==0){
                        l+=1;
                        r+=1;
                    }
                    else{
                        r+=1;
                        while(r<A.size() and A[r]==0)
                            r+=1;
                        if(r==A.size())
                            return m;
                        l=r;
                        k=0;
                    }
                }
            }
        }
        else{
            r+=1;
        }
        m = max(m,r-l+1);
        // cout<<"l= "<<l<<" r= "<<r<<" m= "<<m<<endl;
    }
    if(r==A.size())
            m=max(m,r-l+1);
    return m;
    
}


int main(int argc, char const *argv[])
{
    vector<int> v = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int b = 2;
    cout<<solve(v,b)<<endl;
    
    return 0;
}