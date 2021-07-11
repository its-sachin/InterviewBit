#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

string solve(string A, int B) {
    if(B==0 or A=="")
        return A;

    vector<int> great;
    for (int i = 1; i < A.size(); i++){
    
        if((int(A[0])-48<int(A[i])-48))
            great.push_back(i);
        
    }
    if(great.size()==0)
        return A[0] + solve(A.substr(1,A.size()-1),B);
    else{
        int m = 0;
        for (int i = 0; i < great.size(); i++){
            string b = A;
            swap(b[0],b[great[i]]);
            m = max(m,stoi(b[0]+solve(b.substr(1,b.size()),B-1)));
        }
        return to_string(m);
    }

}


int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    
    cout<<solve(s,n)<<endl;
    return 0;
}