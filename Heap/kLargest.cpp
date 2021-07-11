#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back




vector<int> solve(vector<int> &A, int B) {
    priority_queue<int, vector<int>> p;
    for(int i=0; i<A.size(); i++)
        p.push(A[i]);

    vector<int> v;
    for (int i = 0; i < B; i++){
    
        v.push_back(p.top());
        p.pop();
    }
    return v;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {725, 479, 359, 963, 465, 706, 146, 282, 828, 962};
    int b=2;
    vector<int> a = solve(v,b);

    for (int i = 0; i < a.size(); i++){
    
      cout<<a[i]<<", ";  
    }
    cout<<""<<endl;
    
    return 0;
}