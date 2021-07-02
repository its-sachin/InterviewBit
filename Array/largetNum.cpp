#include <iostream>
#include <bits\stdc++.h>

using namespace std;

bool comp(string a, string b){
    string one = a.append(b);
    string two = b.append(a);

    return one>two;
}

string largestNumber(vector<int> &A){
    vector<string> a;
    for(int i:A){
        a.push_back(to_string(i));
    }
    sort(a.begin(),a.end(),comp);
    string ans = "";
    for(string i:a){
        ans.append(i);
    }
    int i=0;
    while(i+1<a.size() and ans[i]=='0'){
        i++;
    }
    return ans.substr(i);
}

int main(int argc, char const *argv[])
{
    vector<int> a;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        a.push_back(ai);
    }
    cout<<largestNumber(a)<<endl;
    return 0;
}