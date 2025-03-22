#include <bits/stdc++.h>
using namespace std;

int kadanes(vector<int>& arr) {
    int currSum = 0;
    int maxSum = INT_MIN; // Handle all negative numbers case
    for (int i = 0; i < arr.size(); i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int kadanesOfTwo(vector<int>& arr) {
    int n = arr.size();
    vector<int> narr(2 * n);
    
    // Copying array twice
    for (int i = 0; i < n; i++) {
        narr[i] = arr[i];
        narr[i + n] = arr[i];
    }
    return kadanes(narr);
}

long long maxSubSumKConcat(vector<int>& arr, int n, int k) {
    if (k == 1) {
        return kadanes(arr);
    }

    long long kadaneTwo = kadanesOfTwo(arr);
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);

    if (sum > 0) {
        return kadaneTwo + (k - 2) * sum;
    } else {
        return kadaneTwo; // If sum is negative, repeating won’t improve the sum
    }
}

int main() {
    vector<int> arr = {1, -2, 1, 3};
    int k = 3;
    cout << maxSubSumKConcat(arr, arr.size(), k) << endl;
    return 0;
}
