#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A, int B) {
    int i=0;
    int c=0;
    int last = -1;
    while(i<A.size() and i<=B-1){
        if(A[i]==1){
            last=i;
        }
        i++;
    }
    if(last==-1){
        return -1;
    }
    c+=1;
    while(i<A.size()){
        int diff = i-last;
        int prev=last;
        while(diff<=2*(B-1)+1){
            if(A[i]==1){
                last=i;
            }
            diff+=1;
            i++;
            if(i>=A.size()-1){
                if(diff>B-1){
                    if(last<A.size()-B){
                        return -1;
                    }
                    else
                        return c+1;
                }
                return c;
            }
        }
        if(last==prev){
            return -1;
        }
        c+=1;
    }
    return c;
}


int main(int argc, char const *argv[])
{
    vector<int> a;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int ai;
        cin>>ai;
        a.push_back(ai);
    }

    int k;
    cin>>k;
    
    cout<<solve(a,k)<<endl;
    return 0;
}
