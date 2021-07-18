#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000003
#define pb push_back



void mergeSort(string array, int left, int right, int ind[], int small[]) {

    if(left<right) {

        int mid = (right+left)/2;
        mergeSort(array,left,mid,ind,small);
        mergeSort(array,mid+1,right,ind,small);

        int start=left;
        int l1=mid+1;
        vector<int> li;
        int k=0;

        while(left<=mid and l1<=right){
            if(array[ind[left]]<=array[ind[l1]]){
                li.push_back(ind[left]);
                small[ind[left]]+=k;
                left+=1;
            }
            else{
                li.push_back(ind[l1]);
                k+=1;
                l1+=1;
            }
        }

        while(left<=mid){
            li.push_back(ind[left]);
            small[ind[left]]+=k;
            left+=1;
        }

        while(l1<=right){
            li.push_back(ind[l1]);
            l1+=1;
        }

        for (int i = start; i <= right; i++){
        
            ind[i]=li[i-start];
        }


    }

}

int findRank(string A) {

    int fact[A.size()];
    fact[0]=1;
    for (int i = 1; i < A.size(); i++){
    
        fact[i]=(fact[i-1]*i%mod)%mod;
    }

    int ind[A.size()];
    for (int i = 0; i < A.size(); i++){

        ind[i]=i;
    }

    int small[A.size()] = {0};
    mergeSort(A,0,A.size()-1,ind,small);

    int ans=1;
    for (int i = 0; i < A.size(); i++){
        
        ans = (ans + ((small[i]%mod)*fact[A.size()-i-1])%mod)%mod;
        
    }

    return ans;

}


int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    cout<<findRank(s)<<endl;
    return 0;
}