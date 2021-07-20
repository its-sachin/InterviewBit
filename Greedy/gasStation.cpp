#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    vector<int> c;
    for (int i = 0; i < A.size(); i++){
    
        c.push_back(A[i]-B[i]);
        
    }

    for (int i = 0; i < A.size(); i++){
    
        if(c[i]>=0){
            bool nDone = false;
            int sum=c[i];
            for (int j = i+1; j < A.size(); j++){
            
                sum+=c[j];
                if(sum<0){
                    nDone = true;
                    break;
                }
            }
            if(!nDone){
                for (int j = 0; j < i; j++){
                
                    sum+=c[j];
                    if(sum<0){
                        nDone = true;
                        break;
                    }
                }
            }

            if(!nDone){
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,2};
    vector<int> b= {2,1};
    cout<<canCompleteCircuit(v,b)<<endl;
    
    return 0;
}