#include <bits/stdc++.h> 

using namespace std;

long long maxSubSumKConcat(vector<int> &arr, int n, int k)
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
    vector<int> arr = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    int res = maxSubSumKConcat(arr,arr.size());
    cout<<res<<endl;
}