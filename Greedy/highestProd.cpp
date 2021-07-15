
#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int maxp3(vector<int> &A) {

    if(A.size()==1){
        return A[0];
    }

    if(A.size()==2){
        return A[0]*A[1];
    }

    if(A.size()==3){
        return A[0]*A[1]*A[2];
    }
    int m1 = INT32_MIN;
    int m2 = INT32_MIN;
    int m3 = INT32_MIN;

    int m4 = INT32_MAX;
    int m5 = INT32_MAX;

    for (int i = 0; i < A.size(); i++){
    
        if(m1<A[i]){
            m3=m2;
            m2=m1;
            m1=A[i];
        }

        else if(m2<A[i]){
            m3=m2;
            m2=A[i];
        }

        else if(m3<A[i]){
            m3=A[i];
        }

        if(m4>A[i]){
            m5=m4;
            m4=A[i];
        }

        else if(m5>A[i]){
            m5=A[i];
        }
    }
    cout<<m4<<" "<<m5<<endl;
    return max(m1*m2*m3,m1*(m4*m5));
}

int main(int argc, char const *argv[])
{
    vector<int> v = {-65, 41, 15, -11, 69, 23, -63, -4, 49, -99, -61, 17, -61 };
    cout<<maxp3(v)<<endl;
    return 0;
}