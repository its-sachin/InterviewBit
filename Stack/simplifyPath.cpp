#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

string simplifyPath(string A) {
    stack<string> s;

    string d;
    int i=0;
    while(i<A.size()){

        d.clear();

        if(A[i]=='/'){
            while(i<A.size() and A[i]=='/')i++;
        }

        while(i<A.size() and A[i]!='/'){
            d.push_back(A[i]);
            i+=1;
        }  

        if(d.compare("..")==0){
            
            if(!s.empty())
                s.pop();
            i+=1;
        }

        else if(d.compare(".")==0)
            continue;

        else if(d.size()!=0){
            s.push(d);
        }
    }

    stack<string> rev;
    while(!s.empty()){
        rev.push(s.top());
        s.pop();
    }
    
    string ans="/";
    while(!rev.empty()){
        ans.append(rev.top());
        ans.push_back('/');
        rev.pop();
    }
    if(ans.size()!=1)
        ans.pop_back();
    return ans;
}


string simplifyPath2(string A) {
    stack<string> s;
    int i=0;
    while(i<A.size()){
        if(A[i]=='/'){
            while(i<A.size() and A[i]=='/')i++;
        }
        else if(A[i]=='.'){
            
            if(i<A.size() and A[i+1]=='.'){
                if(!s.empty())
                    s.pop();
                i+=1;
            }
            i+=1;
        }
        else{
            string a="";
            while(i<A.size() and A[i]!='/'){
                a.push_back(A[i]);
                i+=1;
            }
            s.push(a);
        }
    }

    stack<string> rev;
    while(!s.empty()){
        rev.push(s.top());
        s.pop();
    }
    string ans="/";
    while(!rev.empty()){
        ans.append(rev.top());
        ans.push_back('/');
        rev.pop();
    }
    if(ans.size()!=1)
        ans.pop_back();
    return ans;
}


int main(int argc, char const *argv[])
{
    string s;
    cin>>s;

    cout<<simplifyPath2(s)<<endl;    
    return 0;
}