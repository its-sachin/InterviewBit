#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A, int B) {

    int low =0;
    int high = A.size()-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid]==B){
            return mid;
        }
        
        else if(mid==0){
            if(A.size()==1){
                return -1;
            }
            low=mid+1;
        }
        else{
            if(A[mid-1]>A[mid]){
                if(A[mid]>B){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else{
                if(A[mid]<B){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
    }
    return -1;
}


int main(int argc, char const *argv[])
{
    return 0;
}