#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> stepnum(int A, int B) {

    vector<int> c;

    if(0<=B and 0>=A)
        c.push_back(0);
    

    for (int i = 1; i < 10; i++){
        
        queue<int> q;
        q.push(i);

        while(!q.empty()){

            int k = q.front();
            if(k<=B and k>=A)
                c.push_back(k);

            q.pop();

            int k1=INT32_MAX;
            int k2=INT32_MAX;

            if(k%10!=0){
                k1=10*k+((k%10)-1);
            }
            if(k%10!=9){
                k2=10*k+((k%10)+1);
            }

            if(k1<=B){
                q.push(k1);
            }

            if(k2<=B){
                q.push(k2);
            }

        }

    }

    sort(c.begin(),c.end());
    return c;

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a;
    cin>>a;
    
    vector<int> v = stepnum(n,a);

    for (int i = 0; i < v.size(); i++){
    
        cout<<v[i]<<endl;
    } 
    
    return 0;
}