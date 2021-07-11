#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<vector<int> > permute(vector<int> &A) {

    vector<vector<int>> ans;
    if(A.size()==0) return ans;
    if(A.size()==1){
        ans.push_back(A);
        return ans;
    }

    int f = A.back();
    A.pop_back();
    vector<vector<int>> a = permute(A);
    for (int i = 0; i < a.size(); i++){

        for (int j = 0; j <= a[i].size(); j++){
            vector<int> curr(a[i].size()+1);
            curr[j]=f;
            int ind=0;

            for (int k = 0; k <= a[i].size(); k++){
                if(k!=j){
                    curr[k]=a[i][ind];
                    ind+=1;
                }
            }
            ans.push_back(curr);
        }
    }
    return ans;


}


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4};
    vector<vector<int>> ans = permute(v);

    for (int i = 0; i < ans.size(); i++){
        
        cout<<"[";
        for (int j = 0; j < ans[i].size(); j++){
        
            cout<<ans[i][j]<< " ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}