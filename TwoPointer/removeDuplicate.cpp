#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


int removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int k=-1;
    int i=1;
    while(i<A.size()){
        
        if(k==-1){
            if(A[i-1]==A[i]){
                k=i;
                i+=1;
            }
            else   
                i+=1;
        }
        else{
            if(A[k-1]==A[i]){
                while(i<A.size() and A[i]==A[k-1]){
                    i+=1;
                }
            }
            else{
                A[k]=A[i];
                k+=1;
                i+=1;
            }
        }
    }
    if(k==-1)
        return A.size();
    return k;
}

int main(int argc, char const *argv[])
{
    return 0;
}