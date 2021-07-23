#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int solve(int A, int B) {
    return min(8-A,8-B)+min(A-1,8-B)+min(8-A,B-1)+min(A-1,B-1);
}


int main(int argc, char const *argv[])
{
    return 0;
}