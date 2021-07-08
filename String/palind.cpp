#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int isPalindrome(string A) {
    int i=0;
    int j=A.size()-1;
    while(i<j){
        while(i<A.size() and !isalnum(A[i]))
            i++;
        while(j>=0 and !isalnum(A[j]))
            j--;
        if(i<A.size() and j>=0 and tolower(A[i]) != tolower(A[j]))
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    cout<<isPalindrome(s)<<endl;
    return 0;
}