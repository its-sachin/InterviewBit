#include<bits/stdc++.h>
#include <stack>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

string reverseString(string A) {
    stack<char> s;

    for (int i = 0; i < A.size(); i++){
    
        s.push(A[i]);
    }

    string ans = "";
    for (int i = 0; i < A.size(); i++){
        

        ans.push_back(s.top());
        s.pop();
    }
    return ans;


}


int main(int argc, char const *argv[])
{
    return 0;
}