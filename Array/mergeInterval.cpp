#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back


/**
 * Definition for an interval.
 * */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(Interval a, Interval b){
    return a.start<b.start;
}


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end(),comp);

    vector<Interval> ans;
    ans.push_back(intervals[0]);
    int i=1;
    while(i<intervals.size()){
        if(intervals[i-1].end<intervals[i].start)
            ans.push_back(intervals[i]);
        else{
            while(i<intervals.size() and intervals[i-1].end>=intervals[i].start)
                i++;
            ans.back().end = intervals[i-1].end;
        }
    }
    return ans;

}

void adjust(int start, vector<Interval> &intervals, Interval newInterval){

    int j=start+1;
    while(j<intervals.size() and intervals[j].end <= newInterval.end){
        j++;
    }

    if(j==intervals.size() || newInterval.end<intervals[j].start){
        intervals[start].end = newInterval.end;
    }
    else{
        intervals[start].end = intervals[j].end;
        j++;
    }
    start++;
    while(j<intervals.size()){
        swap(intervals[start],intervals[j]);
        start++;
        j++;
    }
    int k = intervals.size()-start;
    while(k>0){
        intervals.pop_back();
        k--;
    }

}
vector<Interval> iinsert(vector<Interval> &intervals, Interval newInterval) {

    if(newInterval.start>newInterval.end)
        swap(newInterval.start, newInterval.end);
    
    if(intervals[0].start >= newInterval.start){
        if(intervals[0].start>newInterval.end){
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end(),comp);
            return intervals;
        }
        intervals[0].start = newInterval.start;
        adjust(0,intervals,newInterval);
        return intervals;
    }

    bool done = false;
    for (int i = 0; i < intervals.size()-1; i++){
    
        if(intervals[i+1].start>=newInterval.start){
            done = true;

            if(newInterval.start<=intervals[i].end){
                if(newInterval.end<=intervals[i].end){
                    break;
                }
                if(newInterval.end<intervals[i+1].start){
                    intervals[i].end = newInterval.end;
                    break;
                }

                adjust(i,intervals,newInterval);
            
            }

            else{
                
                if(newInterval.end<intervals[i+1].start){
                    intervals.push_back(newInterval);
                    sort(intervals.begin(),intervals.end(),comp);
                    break;
                }
                if(newInterval.start<intervals[i+1].start){

                    intervals[i+1].start = newInterval.start;
                }

                    if(intervals[i+1].end>=newInterval.end)
                        break;
                    adjust(i+1,intervals,newInterval);
                    
            }
            break;
        }
        
    }

    if(!done){
        intervals.push_back(newInterval);
    }
    return intervals;

}
int main(int argc, char const *argv[])
{
    vector<pair<int,int>> a ={ { 7790713, 9332533}, {10755183, 11155540}, {11880594, 16372598}, {20253304, 21480099}, {21594791, 32554370}, {37491833, 42144750}, {47246399, 48594350}, {55564470, 65968466}, {68003756, 74442674}, {76298468, 78101486}, {81417190, 83823945}, {84742054, 88369776} };
    vector<Interval> b;
    for(int i=0; i<a.size();i++){
        Interval k;
        k.start = a[i].first;
        k.end = a[i].second;
        b.push_back(k);
    }

    Interval newi ;
    newi.start =2558064;
    newi.end = 96618465;

    vector<Interval> ans = iinsert(b,newi);
    
    for(int i=0; i<ans.size();i++){
        cout<<"("<<ans[i].start<<", "<<ans[i].end<<"), ";
    }

    return 0;
}