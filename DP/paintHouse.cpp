#include<bits/stdc++.h>

using namespace std;

//typedef long long int;
#define inf 1e18
#define mod 1000000007
#define pb push_back

int rec(vector<vector<int> > &A, int i, int color, int** dp){
    if(i==A.size()-1)
        return A[i][color];

    else{

        if(dp[i][color]!=-1)
            return dp[i][color];
        int k1,k2;
        if(color==0){
            k1 = dp[i+1][1];
            k2 = dp[i+1][2];

            if(k1==-1){
                k1=rec(A,i+1,1,dp);
                dp[i+1][1]=k1;
            }

            if(k2==-1){
                k2=rec(A,i+1,2,dp);
                dp[i+1][2]=k2;
            }
        }

        else if(color==1){
            k1 = dp[i+1][0];
            k2 = dp[i+1][2];

            if(k1==-1){
                k1=rec(A,i+1,0,dp);
                dp[i+1][0]=k1;
            }

            if(k2==-1){
                k2=rec(A,i+1,2,dp);
                dp[i+1][2]=k2;
            }
        }

        else{
            k1 = dp[i+1][0];
            k2 = dp[i+1][1];

            if(k1==-1){
                k1=rec(A,i+1,0,dp);
                dp[i+1][0]=k1;
            }

            if(k2==-1){
                k2=rec(A,i+1,1,dp);
                dp[i+1][1]=k2;
            }
        }

        return min(k1,k2)+A[i][color];

    }
}

int solve(vector<vector<int> > &A) {
    
    int** dp = new int*[A.size()+1];
    for (int i = 0; i <= A.size(); i++){
    
        dp[i]=new int[3];

        for(int j=0; j<3; j++)
            dp[i][j]=-1;
    }
    return min(rec(A,0,0,dp),min(rec(A,0,1,dp),rec(A,0,2,dp)));

}


int main(int argc, char const *argv[])
{
    vector<vector<int> > a = {
        {468, 335, 501},
  {170, 725, 479},
  {359, 963, 465},
  {706, 146, 282},
  {828, 962, 492},
  {996, 943, 828},
  {437, 392, 605},
  {903, 154, 293},
  {383, 422, 717},
  {719, 896, 448},
  {727, 772, 539},
  {870, 913, 668},
  {300, 36, 895},
  {704, 812, 323},
  {334, 674, 665},
  {142, 712, 254},
  {869, 548, 645},
  {663, 758, 38},
  {860, 724, 742},
  {530, 779, 317},
  {36, 191, 843},
  {289, 107, 41},
  {943, 265, 649},
  {447, 806, 891},
  {730, 371, 351},
  {7, 102, 394},
  {549, 630, 624},
  {85, 955, 757},
  {841, 967, 377},
  {932, 309, 945},
  {440, 627, 324},
  {538, 539, 119},
  {83, 930, 542},
  {834, 116, 640},
  {659, 705, 931},
  {978, 307, 674},
  {387, 22, 746},
  {925, 73, 271},
  {830, 778, 574},
  {98, 513, 987},
  {291, 162, 637},
  {356, 768, 656},
  {575, 32, 53},
  {351, 151, 942},
  {725, 967, 431},
  {108, 192, 8},
  {338, 458, 288},
  {754, 384, 946},
  {910, 210, 759},
  {222, 589, 423},
  {947, 507, 31}
    };

    cout<<solve(a)<<endl;
    return 0;
}