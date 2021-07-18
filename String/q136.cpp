#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (int i = 0; i < nums.size(); i++){
            
            ans^=nums[i];
            
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}