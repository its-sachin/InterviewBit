#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

string solve(string A) {
    unordered_map<char,bool> once;
    queue<char> order;
    string ans="";

    ans.push_back(A[0]);
    char last = A[0];
    once.insert({A[0],true});

    for (int i = 1; i < A.size(); i++){
    
        if(once.find(A[i])==once.end()){
            //first occurence
            once.insert({A[i],true});
            order.push(A[i]);

            if(last=='#')
                last = A[i];
        }
        else{
            once.at(A[i]) = false;
            if(A[i]==last){
                // cout<<"lol"<<endl;
                while(!(order.empty()) and once.at(order.front()) == false)
                    order.pop();
                if(order.empty())
                    last = '#';
                else{
                    last = order.front();
                    order.pop();
                }
            }
        }
        ans.push_back(last);
    }
    return ans;
    
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    
    cout<<solve(s)<<endl;
    return 0;
}