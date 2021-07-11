#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> solve(int A, int B, int C, int D) {

    vector<int> ans;

    if(D==0)
        return ans;

    ans.push_back(1);

    int i=0;
    int x=0;
    int y=0;
    int z=0;


    while(i<D){
    
        int m = min(A*ans[x],min(B*ans[y],C*ans[z]));
        ans.push_back(m);

        if(m==A*ans[x])
            x+=1;
        if(m==B*ans[y])
            y+=1;
        if(m==C*ans[z])
            z+=1;

        i+=1;
    }   
    ans.erase(ans.begin());
    return ans;
}

int main(int argc, char const *argv[])
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    vector<int> v= solve(a,b,c,d);

    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<endl;
        
    }
    return 0;
}