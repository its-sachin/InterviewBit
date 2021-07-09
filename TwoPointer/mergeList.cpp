#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

void merge(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int i=0;
    int j=0;

    while(i<A.size() and j<B.size()){
        if(A[i]<=B[j]){
            while(i<A.size() and A[i]<=B[j]){
                C.push_back(A[i]);
                i++;
            }
        }
        else{
            while(j<B.size() and B[j]<=A[i]){
                C.push_back(B[j]);
                j++;
            }
        }
    }

    while(i<A.size()){
        C.push_back(A[i]);
        i++;
    }
    while(j<B.size()){
        C.push_back(B[j]);
        j++;
    }

    i=0;
    while(i<A.size()){
        A[i]=C[i];
        i++;
    }
    while(i<C.size()){
        A.push_back(C[i]);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}