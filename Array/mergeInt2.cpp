#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(Interval i1, Interval i2){
    return i1.start<=i2.start;
}

vector<Interval> merge(vector<Interval> &A) {
    vector<Interval> ans;

    if(A.size()==0)
        return ans;

    sort(A.begin(),A.end(),comp);

    ans.push_back(A[0]);
    for (int i = 1; i < A.size(); i++){
    
        if(ans.back().end>=A[i].start){
            ans.back().end = max(ans.back().end,A[i].end);            
        }
        else{
            ans.push_back(A[i]);
        }
    }
    return ans;
}

int main(int argc, char const argv[])
{
    return 0;
}