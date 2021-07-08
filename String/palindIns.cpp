#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve1(string A) {

    int i=0;
    int j=A.size()-1;
    while(j>0 and A[j]!=A[i])
        j--;
    if(j==0)
        return A.size()-1;
    int prev=-1;
    int start=j;
    while(i<j){
        if(A[j]==A[0] and prev==-1)
            prev=j;
        if(A[i]!=A[j]){
            if(prev!=-1){
                j=prev;
                start=prev;
            }
            else{
                while(j>0 and A[j]!=A[0])
                    j--;

                if(j==0)
                    return A.size()-1;
                start=j;
            }
            prev=-1;
            i=0;
        }

        i++;
        j--;
    }
    // cout<<i<<" "<<j<<endl;
    if(j>i)
        return A.size()-1;
    return A.size()-start-1;
}

int solve(string A) {

    string rev = A;
    reverse(rev.begin(), rev.end());
    string concat = A + '$'+ rev;

    vector<int> lps(concat.size());
 
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < concat.size()){
        if (concat[i] == concat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }

    return (A.size() - lps.back());
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    cout<<solve(s)<<endl;
    return 0;
}