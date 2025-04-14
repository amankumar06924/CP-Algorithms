// Given an array arr[] of size n, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
// If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.

// Example:

// Input: arr = [1, 6, 11, 5]
// Output: 1
// Explanation: S1 = [1, 5, 6], sum = 12,  S2 = [11], sum = 11,  Absolute Difference (12 – 11) = 1
// Using Recursion – O(2^n) Time and O(n) Space

// C++ Code to partition a set into two
// subsets such that the difference
// of subset sums is minimum
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum absolute difference
int findMinDifference(vector<int> &arr, int n,
                      int sumCalculated, int sumTotal)
{

    // Base case: if we've considered all elements
    if (n == 0)
    {
        return abs((sumTotal - sumCalculated) - sumCalculated);
    }

    // Include the current element in the subset
    int include = findMinDifference(arr, n - 1,
                                    sumCalculated + arr[n - 1], sumTotal);

    // Exclude the current element from the subset
    int exclude = findMinDifference(arr,
                                    n - 1, sumCalculated, sumTotal);

    // Return the minimum of both choices
    return min(include, exclude);
}

// Function to get the minimum difference
int minDifference(vector<int> &arr)
{
    int sumTotal = 0;

    // Calculate total sum of the array
    for (int num : arr)
    {
        sumTotal += num;
    }

    // Call recursive function to find
    // the minimum difference
    return findMinDifference(arr,
                             arr.size(), 0, sumTotal);
}

int main()
{

    vector<int> arr = {1, 6, 11, 5};

    cout << minDifference(arr) << endl;

    return 0;
}

// Using Top-Down DP (Memoization) – O(n*sumTotal) Time and O(n*sumTotal) Space


// C++ Code to partition a set into two 
// subsets such that the difference 
// of subset sums is minimum, using memoization
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum absolute 
// difference with memoization
int findMinDifference(vector<int>& arr, int n, 
                      int sumCalculated, int sumTotal, 
                      vector<vector<int>>& memo) {

    // Base case: if we've considered all elements
    if (n == 0) {
        return abs((sumTotal - sumCalculated) 
                                    - sumCalculated);
    }

    // Check if the result is already computed
    if (memo[n][sumCalculated] != -1) {
        return memo[n][sumCalculated];
    }

    // Include the current element in the subset
    int include = findMinDifference(arr, n - 1, 
                    sumCalculated + arr[n - 1], sumTotal, memo);

    // Exclude the current element from the subset
    int exclude = findMinDifference(arr, n - 1, 
                    sumCalculated, sumTotal, memo);

    // Store the result in memo and return
    return memo[n][sumCalculated] = min(include, exclude);
}

// Function to get the minimum difference
int minDifference(vector<int>& arr) {
    int sumTotal = 0;

    // Calculate total sum of the array
    for (int num : arr) {
        sumTotal += num;
    }

    // Create a 2D memoization table, initialized to -1
    vector<vector<int>> memo(arr.size() + 1, 
                             vector<int>(sumTotal + 1, -1));

    // Call the recursive function with memoization
    return findMinDifference(arr, arr.size(), 
                               0, sumTotal, memo);
}

int main() {

    vector<int> arr = {1, 6, 11, 5};

    cout << minDifference(arr) << endl;

    return 0;
}


// Using Space Optimized DP – O(n*sumTotal) Time and O(sumTotal) Space

// C++ code to partition a set into two subsets
// with min diff with space optimization
#include <bits/stdc++.h>
using namespace std;

// Function to get the minimum difference using 
// space optimization
int minDifference(vector<int>& arr) {
   int sumTotal = 0;

    // Calculate total sum of the array
    for (int num : arr) {
        sumTotal += num;
    }

    // Create a 1D DP array to track achievable subset sums
    vector<bool> dp(sumTotal + 1, false);
    dp[0] = true; 

    // Fill the DP array
    for (int num : arr) {
        for (int sum = sumTotal; sum >= num; sum--) {
            dp[sum] = dp[sum] || dp[sum - num];
        }
    }

    // Find the minimum difference
    int minDiff = sumTotal;
    for (int sum = 0; sum <= sumTotal / 2; sum++) {
        if (dp[sum]) {
            minDiff = min(minDiff, abs((sumTotal - sum) - sum));
        }
    }

    return minDiff;
}

int main() {
    vector<int> arr = {1, 6, 11, 5};

    cout << minDifference(arr) << endl;

    return 0;
}

