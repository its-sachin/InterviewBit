#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<vector<int>> rec(vector<int> &A, int power[]){

    vector<vector<int>> ans;
    if(A.size()==0) return ans;
    if(A.size()==1){
        ans.push_back(A);
        return ans;
    }

    int f = A.back();
    int k=A.size();
    A.pop_back();
    vector<vector<int>> a = rec(A,power);

    unordered_map<int,bool> m;

    for (int i = 0; i < a.size(); i++){
        
        int j=0;
        while(j <= a[i].size()){
            // cout<<k<<" "<<i<<" "<<j<<endl;
            vector<int> curr(a[i].size()+1);
            curr[j]=f;
            int ind=0;
            int h=0;

            for (int k = 0; k <= a[i].size(); k++){
                if(k!=j){
                    curr[k]=a[i][ind];
                    h= (h + power[k+1]*(a[i][ind])%mod)%mod;
                    ind+=1;
                }
                else{
                    h= (h + power[k+1]*(f)%mod)%mod;
                }
            }

            if(m.find(h)==m.end()){
                ans.push_back(curr);
                m[h]=true;
            }
            j+=1;
        }
    }
    return ans;
}

vector<vector<int> > permute(vector<int> &A) {

    int base=1000003;
    int power[A.size()+1];
    int mt=1;
    int i=0;
    while(i<=A.size()){
        power[i]=mt;
        mt=base*(mt)%mod;
        i+=1;
    }

    return rec(A,power);
    
}


int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8 };

    vector<vector<int> > ans = permute(v);
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++){
    
        for (int j = 0; j < ans[i].size(); j++){
        
            cout<<ans[i][j]<<" ";
        }
        cout<<""<<endl;
    }

    return 0;
}