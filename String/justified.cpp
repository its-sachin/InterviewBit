#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

vector<string> fullJustify(vector<string> &A, int B) {

    vector<string> ans;
    vector<string> currline; 
    int c = 0;
    int line=0;
    for (int i = 0; i < A.size(); i++){
        if(c+A[i].size()>B){

            int spaces = B-c+1;
            string s = "";
            s.append(currline[0]);
            int words = currline.size()-1;

            if(words==0){
                for (int j = 0; j < spaces; j++){
                
                    s.push_back(' ');
                }
            }

            else{

                int every = spaces/words;
                int left = spaces%words;

                for (int i = 1; i < currline.size(); i++){
                    
                    s.push_back(' ');
                    if(left>0){
                        s.push_back(' ');
                        left-=1;
                    }
                    for (int j = 0; j < every; j++){
                    
                        s.push_back(' ');
                    }
                    s.append(currline[i]);
                }
            }

            ans.push_back(s);

            currline.clear();
            i-=1;
            c=0;
            line+=1;
        }
        else{
            currline.push_back(A[i]);
            c+=A[i].size()+1;
        }
    } 

    if(!currline.empty()){
        string s = "";

        int c=0;
        for (int i = 0; i < currline.size(); i++){
            c+=currline[i].size()+1;
            s.append(currline[i]);
            
            s.push_back(' ');
        }

        if(c>B)
            s.pop_back();

        for (int i = 0; i < B-c; i++){
        
            s.push_back(' ');
        }

        ans.push_back(s);
    }

    return ans;  
}

int main(int argc, char const *argv[])
{
    vector<string> v = {"am", "fasgoprn", "lvqsrjylg", "rzuslwan", "xlaui", "tnzegzuzn", "kuiwdc", "fofjkkkm", "ssqjig", "tcmejefj", "uixgzm", "lyuxeaxsg", "iqiyip", "msv", "uurcazjc", "earsrvrq", "qlq", "lxrtzkjpg", "jkxymjus", "mvornwza", "zty", "q", "nsecqphjy" };
    vector<string> s = fullJustify(v,14);

    for (int i = 0; i < s.size(); i++){
        cout<<s[i].size()<<" "<<s[i]<<endl;
    }
    return 0;
}