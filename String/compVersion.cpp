#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int compareVersion(string A, string B) {

    int i=0,j=0;
    string n1="",n2="";

    int n=A.size();
    int m=B.size();

    while(i<n or j<m){

        while(i<n and A[i]=='0'){
            i++;
        }

        while(i<n and A[i]!='.'){
            n1.push_back(A[i]);
            i++;
        }

        while(j<m and B[j]=='0'){
            j++;
        }

        while(j<m and B[j]!='.'){
            n2.push_back(B[j]);
            j++;
        }
        
        if(n1!=n2){
            if(n1.size()==n2.size())
                return n1.compare(n2) > 0 ? 1: -1;
            return n1.length()>n2.length() ? 1:-1;
        }

        n1="";
        n2="";
        i++;
        j++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string a,b;
    cin>>a>>b;
    cout<<compareVersion(a,b)<<endl;
    return 0;
}