#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int Mod(int A, int B, int C) {
    if(B==0){
        if(A==0)
            return 0;
        return 1;
    } 
    A=(A+C)%C;
    long long int g=A;
    if(B&1){
        return ((Mod((g*g)%C,B/2,C)%C)*g)%C;
    }
    return Mod((g*g)%C,B/2,C);
}

int main(int argc, char const *argv[]){

    int a,b,c;
    cin>>a>>b>>c;

    cout<<Mod(a,b,c)<<endl;
    
    return 0;
}