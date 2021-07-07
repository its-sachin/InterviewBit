#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(vector<int> &A, int N, int K) {

    int dig = log10(K)+1;

    if(A.size() ==0 or K==0 or N>dig )
        return 0;

    if(N<dig){
        int i=0;
        for (i = 0; i < A.size() and A[i]==0; i++);

        if(N==1)
            return A.size();
        int ans = A.size()-i;
        i=1;
        while(i<N){
            ans*=A.size();
            i++;
        }
        return ans;
    }

    else{
        bool isit[10]={false};
        int numSmall[10]={0};
    
        for (int i = 0; i < A.size(); i++){
        
            if(!isit[A[i]]){
                isit[A[i]]=true; 
            }   
        }

        int k=0;
        for (int i = 0; i < 10; i++){
            
            numSmall[i]=k;
            if(isit[i])
                k++;
        }

        int ans = 0;
        int i=0;

        bool isDig[dig];
        memset(isDig,true,dig);
        int p = pow(10,dig-1);
        int l = K;
        while(i<dig){
            if(!isit[l/p]){
                i++;
                while(i<dig){
                    isDig[i]=false;
                    i++;
                }
            }
            i++;
            l=l%p;
            p/=10;
        }

        i=0;
        while(K>0){
            if(isDig[dig-i-1]){
                int s = K%10;
                if(K/10!=0) s=numSmall[s];
                else{
                    if(isit[0]){ 
                        if(dig == 1)
                            return numSmall[s];
                        s=numSmall[s]-1;
                    }
                    else s=numSmall[s];
                }
                
                ans+=(s*pow(k,i));
            }
            K=K/10;
            i++;
        }

        return ans;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    vector<int> v;
    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        v.push_back(ai);
    }

    int N;
    cin>>N;
    int K;
    cin>>K;
    
    cout<<solve(v,N,K)<<endl;
    return 0;
}