#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

long long int modulo(long long int a, long long int b, int n){
    long long x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n;
        }
        y = (y*y) % n;
        b /= 2;
    }
    return x % n;
}

bool f(int t, pair<int,int> &p, int k){
    if(t==p.first){
        if(t==p.second){
            return k>2;
        }
        return k>1;
    }
    if(t==p.second)
        return k>1;
    return k>0;
}


int solve(int A, vector<int> &B) {

    sort(B.begin(),B.end());

    unordered_map<int,int> part;
    part.insert({B[0]-1,1});

    long long int sum=B[0]-1;
    for (int i = 1; i < B.size(); i++){

        int k = B[i]-B[i-1]-1;
        sum+=k;

        if(part.find(k)!=part.end())
            part.at(k)++;
        else    
            part.insert({k,1});
    }

    int k = A-B[B.size()-1];
    sum+=k;

    if(part.find(k)!=part.end())
            part.at(k)++;
    else    
        part.insert({k,1});

    pair<int,int> no = {B[0]-1,k};

    int powAns =1;
    int factAns=1;

    long long int i=1;
    long long int prod=1;
    long long int pow =1;
    while(i<sum){
        if(part.find(i)!=part.end()){
            int k = part.at(i);
            while(k>0){
                factAns = (factAns*prod)%mod;
                if(f(i,no,k)){
                    powAns=(powAns*pow)%mod;
                }

                k--;
            }
            
        }
        i+=1;
        prod=(prod*(i%mod))%mod;
        pow=(pow*2)%mod;
    }

    if(part.find(i)!=part.end()){
        int k = part.at(i);
        while(k>0){
            factAns = (factAns*prod)%mod;
            if(f(i,no,k)){
                powAns=(powAns*pow)%mod;
            }

            k--;
        }
        
    }

    cout<<factAns<<" "<<prod<<" "<<powAns<<endl;

    factAns = modulo(factAns,mod-2,mod);
    return ((prod*factAns)%mod*(powAns))%mod;

}

int main(int argc, char const *argv[])
{
    int a = 48;
    vector<int> vis = {5, 12, 48, 34, 21, 29, 25, 11, 37, 26, 14, 15, 35, 41, 24, 39, 10, 17, 23, 16, 8, 44, 13, 31};

    // int a = 3;
    // vector<int> vis = {1};

    cout<<solve(a,vis)<<endl;
    return 0;
}