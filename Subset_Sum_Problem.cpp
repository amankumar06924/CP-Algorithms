// Subset Sum Problem
// Last Updated : 15 Mar, 2025
// Given an array arr[] of non-negative integers and a value sum, the task is to check if there is a subset of the given array whose sum is equal to the given sum. 

// Examples: 

// Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
// Output: True
// Explanation: There is a subset (4, 5) with sum 9.
// Follow the below steps to implement the recursion:

// Build a recursive function and pass the index to be considered (here gradually moving from the last end) and the remaining sum amount.
// For each index check the base cases.
// If the answer is true for any recursion call, then there exists such a subset. Otherwise, no such subset exists.

//C++ implementation for subset sum
// problem using recursion
#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset
// with the given sum using recursion
bool isSubsetSumRec(vector<int>& arr, int n, int sum) {
  
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (arr[n - 1] > sum)
        return isSubsetSumRec(arr, n - 1, sum);

    // Check if sum can be obtained by including 
  	// or excluding the last element
    return isSubsetSumRec(arr, n - 1, sum) 
      		|| isSubsetSumRec(arr, n - 1, sum - arr[n - 1]);
}

bool isSubsetSum(vector<int>& arr, int sum) {
    return isSubsetSumRec(arr, arr.size(), sum);
}

int main() {
  
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (isSubsetSum(arr, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}


// [Better Approach 1] Using Top-Down DP (Memoization) – O(sum*n) Time and O(sum*n) Space
// The recursive solution involves changing two parameters: the current index in the array (n) and the current target sum (sum). We need to track both parameters, so we create a 2D array of size (n+1) x (sum+1) because the value of n will be in the range [0, n] and sum will be in the range [0, sum].
// We initialize the 2D array with -1 to indicate that no subproblems have been computed yet.
// We check if the value at memo[n][sum] is -1. If it is, we proceed to compute the result. otherwise, we return the stored result.

//C++ implementation for subset sum
// problem using memoization
#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if a subset 
// with the given sum exists
bool isSubsetSumRec(vector<int>& arr, int n, int sum,
                   vector<vector<int>> &memo) {
  
    // If the sum is zero, we found a subset
    if (sum == 0)
        return 1;

    // If no elements are left
    if (n <= 0)
        return 0;

    // If the value is already
  	// computed, return it
    if (memo[n][sum] != -1)
        return memo[n][sum];

    // If the last element is greater than
  	// the sum, ignore it
    if (arr[n - 1] > sum)
        return memo[n][sum] = isSubsetSumRec(arr, n - 1, sum, memo);
    else {
      
        // Include or exclude the last element
        return memo[n][sum] = isSubsetSumRec(arr, n - 1, sum, memo) ||
                              isSubsetSumRec(arr, n - 1, sum - arr[n - 1], memo);
    }
}

// Function to initiate the subset sum check
bool isSubsetSum(vector<int>&arr, int sum) {
   int n = arr.size();

    vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
    return isSubsetSumRec(arr, n, sum, memo);
}

int main() {
  
    vector<int>arr = {1, 5, 3, 7, 4};
    int sum = 12;

    if (isSubsetSum(arr, sum)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
