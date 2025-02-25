#include<iostream>
#include<vector>

using namespace std;

long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long currSum = 0;
    long long maxSum = 0;

    for(int i=0;i<arr.size();i++) {
        currSum += arr[i];
        maxSum = max(currSum,maxSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> arr = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    int res = maxSubarraySum(arr,arr.size());
    cout<<res<<endl;
}