#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> single(string &A,int b, int l){

    vector<int>  ans;
    for (int i = 0; i < l; i++){
    
        ans.push_back(0);
    }
    int c=0;
    for (int i = A.size()-1; i >= 0; i--){
    
        int temp = (int(A[i])-48)*b+c;
        ans.push_back(temp%10);
        c=temp/10;
    }
    if(c!=0)
        ans.push_back(c);
    return ans;
}

string multiply(string A, string B) {

    bool ispos=true;
    if(A[0]=='-'){
        A=A.substr(1);
        if(B[0]=='-')
            B=B.substr(1);
        else
            ispos=false;
    }
    else if(B[0]=='-'){
        ispos=false;
        B=B.substr(1);
    }
    
    vector<vector<int>> levels;
    for (int i = B.size()-1; i >=0; i--){
    
        levels.push_back(single(A,int(B[i])-48,B.size()-i-1));
    }

    int size = levels[B.size()-1].size();
    string ans="";
    int c=0;

    for (int i = 0; i < size; i++){
        
        int temp=c;
        for (int j = 0; j < levels.size(); j++){
            
            if(levels[j].size()>i)
                temp+=levels[j][i];
        }
        ans.push_back((temp%10)+48);
        c=temp/10;
    }
    if(c!=0){
        while(c>0){
            ans.push_back((c%10)+48);
            c/=10;
        }
    }
    while(ans.size()>1 and ans.back()=='0')
        ans.pop_back();

    if(!ispos and ans!="0")
        ans.push_back('-');
    reverse(ans.begin(),ans.end());
    return ans;

}

int main(int argc, char const *argv[])
{
    string a;
    cin>>a;
    
    string b;
    cin>>b;
    
    cout<<multiply(a,b)<<endl;
    return 0;
}