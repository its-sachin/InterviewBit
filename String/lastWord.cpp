#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int lengthOfLastWord(const string A) {

    int i=A.size()-1;
    while(i>=0 and A[i]==' ')
        i--;
    if(i<0)
        return 0;

    int size=0;
    while(i>=0 and A[i]!=' '){
        size++;
        i--;
    }
    return size;
}


int main(int argc, char const *argv[])
{

    string s;
    cin>>s;
    
    cout<<lengthOfLastWord(s)<<endl;
    return 0;
}