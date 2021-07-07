#include<bits/stdc++.h>

using namespace std;

int repeatedNumber(const vector<int> &A) {

    int sq = floor(sqrt(A.size()-1));
    int n = (A.size()/sq) +1;
    int blocks[n] = {0};

    for (int i = 0; i < A.size(); i++){
    
        int k = (A[i]-1)/sq;
        blocks[k]++;
    }

    int flag = n-1;

    for (int i = 0; i < n-1; i++){
        if(blocks[i]>sq){
            flag=i;
            break;
        }
    }

    unordered_map<int,int> h;

    for (int i = 0; i < A.size(); i++){
    
        if(A[i]>flag*sq and A[i]<=(flag+1)*sq){
            if(h.find(A[i]) !=h.end())
                return A[i];
            h.insert({A[i],i});
        }
    }

    return -1;

}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    
    vector<int> a;
    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        a.push_back(ai);
    }

    cout<<repeatedNumber(a)<<endl;
    return 0;
}