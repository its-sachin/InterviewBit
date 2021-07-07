#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<int> primesum(int A) {

    bool spf[A+1];
    for (int i=0; i<=A; i++){
        spf[i]=true;
    }
    int i=2;
    while(i*i<=A){
        if(spf[i]){
            int j=i*i;
            while(j<=A){
                spf[j]=false;
                j+=i;
            }
        }
        i+=1;
    }

    if(spf[A-2])
        return {2,A-2};

    for (int i = 3; i <A; i+=2){
    
        if(spf[i] and spf[A-i])
            return {i,A-i};
    }


}


bool isPrime(int A) {
    if(A==2 or A==3)
        return true;
    if(A%2==0 || A%3==0)
        return false;

    int i=5;
    while(i*i<=A){
        if(A%i==0){
            return false;
        }
        i+=2;
    }    
    return true;
}


vector<int> primesum2(int A) {

    int i=2;
    vector<int> ans;
    while(i<A){
        if(isPrime(i) and isPrime(A-i))
        {
            ans.push_back(i);
            ans.push_back(A-i);
            return ans;
        }
        i++;
    }

}

int main(int argc, char const *argv[])
{

    int n;
    cin>>n;

    vector<int> a = primesum(n);
    cout<<a[0]<<" "<< a[1]<<endl;
    return 0;
}