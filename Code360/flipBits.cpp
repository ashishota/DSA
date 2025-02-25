#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int flipBits(int*, int);

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array (0s and 1s only): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = flipBits(arr.data(), n);
    cout << "Maximum number of 1s after flipping a subarray: " << result << endl;
    
    return 0;
}

int flipBits(int* arr, int n) 
{
    // flip 1 to -1 and 0 to 1
    for(int i = 0; i < n; i++) {
        arr[i] = (arr[i] == 1) ? -1 : 1;
    }

    int sum = 0, sum_max = INT_MIN;
    int ans = 0;
    int l = 0, r = 0, ans_l = 0, ans_r = 0;

    // kadane's algorithm
    for(r = 0; r < n; r++) {
        sum += arr[r];
        
        if(sum > sum_max) {
            sum_max = sum;
            ans_l = l;
            ans_r = r;
        }
        if(sum < 0) {
            sum = 0;
            l = r + 1;
        }
    }

    // undo the initial flip
    for(int i = 0; i < n; i++) {
        arr[i] = (arr[i] == -1) ? 1 : 0;
    }

    // flip 0 to 1
    if(sum_max > 0) {
        for(int i = ans_l; i <= ans_r; i++) {
            arr[i] = 1 - arr[i];
        }
    }

    // count ones
    ans = count(arr, arr + n, 1);
    return ans;
}
