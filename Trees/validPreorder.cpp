#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solveRec(vector<int> &A, int l, int r){

    if(l>=r or r-l==1){
        return 1;
    }

    int i=l+1;
    while(i<=r and A[i]<=A[l])
        i++;
    if(i>r)
        return solveRec(A,l+1,r);
    
    int mid=i;
    while(i<=r){
        if(A[i]<A[l])
            return 0;
        i++;
    }
    return solveRec(A,l,mid-1) and solveRec(A,mid,r);
}

int solve(vector<int> &A) {
    return solveRec(A,0,A.size()-1);
    
}


int main(int argc, char const *argv[])
{
    vector<int> v = {888, 343, 357, 578, 153, 710, 498, 124, 749, 337, 194, 473, 13, 70, 174, 433, 235, 853, 807, 158, 832, 396, 252, 911, 329, 71, 472, 245, 337, 162, 509, 567, 977, 239, 572, 523, 12, 674, 874, 855, 137, 466, 197, 406, 241, 957, 444, 431, 726, 834, 4, 427, 517, 218, 886, 95, 513, 101, 125, 651, 286, 258, 59, 968, 360, 846, 521, 136, 228, 725, 195, 219, 833, 336, 356, 47, 775, 118, 309, 531, 783, 820, 113, 349, 448, 768, 427, 400, 313, 380, 654, 776, 390 };
    cout<<solve(v)<<endl;
    return 0;
}