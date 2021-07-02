#include <iostream>
#include <vector>

using namespace std;


int crossing(vector<int> array, int left, int mid, int right){

    int l,r;

    int leftSum =INT32_MIN;
    int sum=0;

    for (int i=mid; i>=left; i--){
        sum+=array[i];
        if (sum>leftSum){
            leftSum = sum;
            l = i;
        }
    }
    int rightSum = INT32_MIN;
    sum = 0;

    for (int i=mid+1; i<= right;i++){
        sum+=array[i];
        if (sum>rightSum){
            rightSum = sum;
            r = i;
        }
    }
    return leftSum+rightSum;

}


int recusrive(vector<int> array, int left, int right){

    // O(nlogn)

    if(left==right){
        return array[left];
    }

    else{
        int mid = (left+right)/2;

        int l = recusrive(array,left,mid);
        int r = recusrive(array,mid+1,right);
        int m = crossing(array,left,mid,right);

        if (l>=r && l>=m){
            return l;
        }
        if (r>=m){
            return r;
        }
        return m;

    }


}

int maxSubArray1(const vector<int> &array) {
    return recusrive(array,0,array.size()-1);
}

int maxSubArray(const vector<int> &array) {

    //O(n)
    int n = array.size();
    long int max = INT64_MIN;
    long int sum = INT64_MIN;

    int left=0;
    int right=0;
    int firstPos=0;

    for (int i=0;i<n;i++){

        sum += array[i];
        

        if (sum>max){
            max = sum;
            left = firstPos;
            right = i;
        }

        if (sum<0){
            sum=0;
            firstPos = i+1;
        }
    }

    return max;

}


int main(int argc, char const *argv[])
{
    return 0;
}