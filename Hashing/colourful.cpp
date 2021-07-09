#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int colorful(int A) {
    
    vector<int> v;
    unordered_map<int,int> m;
    while(A>0){
        int k = A%10;
        if(m.find(k)!=m.end())
            return 0;
        m.insert({k,0});
        v.push_back(k);
        A/=10;
    }

    for (int i = 0; i < v.size(); i++){
    
        long long k = v[i];
        for (int j = i+1; j < v.size(); j++){
        
            k*=v[j];
            if(m.find(k)!=m.end())
                return 0;
            m.insert({k,0});
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    cout<<colorful(n)<<endl;
    return 0;
}