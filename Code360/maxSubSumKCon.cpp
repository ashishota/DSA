#include <bits/stdc++.h> 

using namespace std;

long long maxSubSumKCon(vector<int> &arr, int n, int k)
{
	// Write your code here.
	int size = n*k;
	long long currSum = 0;
	long long maxSum = 0;
	vector<int> concat;
	for(int i=0;i<size;i++) {
		concat.push_back(arr[i%n]);
	}
	for(int i=0;i<size;i++) {
		currSum += arr[i];
		maxSum = max(currSum,maxSum);
		if(currSum < 0) {
			currSum=0;
		}
	}
	return maxSum;
}

int main() {
    vector<int> arr = {1,3};
    int res = maxSubSumKCon(arr,arr.size(),3);
    cout<<res<<endl;
}
