#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(int num1, int num2, int op){
    switch (op)
    {
    case 43:
        num2+=num1;
        break;

    case 45:
        num2-=num1;
        break;

    case 42:
        num2*=num1;
        break;

    case 47:
        num2/=num1;
        break;
    
    }
    return num2;
}

int evalRPN(vector<string> &A) {
    stack<int> s;
    unordered_map<string,int> u = {{"+",43},{"-",45},{"/",47},{"*",42}};
    for (int i = 0; i<A.size(); i++){
        if(u.find(A[i])!=u.end()){
            int op=u.at(A[i]);

            int n1 = s.top();
            s.pop();
            int n2 = s.top();
            s.pop();
            s.push(solve(n1,n2,op));            
        }
        else{
            s.push(stoi(A[i]));
        }
        
    }

    return s.top();
}


int main(int argc, char const *argv[])
{
    vector<string> v = {"5","1","2","+","4","*","+","3","-"};
    cout<<evalRPN(v)<<endl;
    return 0;
}