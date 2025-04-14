// [Naive Approach] Using Recursion – Exponential Time and Linear Space
// The idea to do traverse the input array from left to right and find length of the Longest Increasing Subsequence (LIS) ending with every element arr[i]. Let the length found for arr[i] be L[i]. At the end we return maximum of all L[i] values. Now to compute L[i], we use recursion, we consider all smaller elements on left of arr[i], recursively compute LIS value for all the smaller elements on left, take the maximum of all and add 1 to it. If there is no smaller element on left of an element, we return 1.

// Cpp program to find lis using recursion
// in Exponential Time and Linear Space
#include <bits/stdc++.h>
using namespace std;

// Returns LIS of subarray ending with index i.
int lisEndingAtIdx(vector<int>& arr, int idx) {
  
    // Base case
    if (idx == 0)
        return 1;

    // Consider all elements on the left of i,
    // recursively compute LISs ending with 
    // them and consider the largest
    int mx = 1;
    for (int prev = 0; prev < idx; prev++)
        if (arr[prev] < arr[idx])
            mx = max(mx, lisEndingAtIdx(arr, prev) + 1);
    return mx;
}

int lis(vector<int>& arr) {
    int n = arr.size();
    int res = 1;
    for (int i = 1; i < n; i++)
        res = max(res, lisEndingAtIdx(arr, i));
    return res;
}

int main() {
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    cout << lis(arr);
    return 0;
}


// Better Approach – 1] Using Memoization – O(n^2) Time and O(n) Space
// If notice carefully, we can see that the above recursive function lisEndingAtIdx() also follows the overlapping subproblems property i.e., same substructure solved again and again in different recursion call paths. We can avoid this using the memoization approach. Since there is only one parameter that changes in recursive calls and the range of the parameter goes from 0 to n-1,  so we us a 1D array of size n and initialize it as -1 to indicate that the values are not computed yet.

#include <bits/stdc++.h>
using namespace std;

int lisEndingAtIdx(vector<int>& arr, int idx, vector<int>& memo) {
  
    // Base case
    if (idx == 0)
        return 1;

    // Check if the result is already computed
    if (memo[idx] != -1)
        return memo[idx];

    // Consider all elements on left of i,
    // recursively compute LISs ending with 
    // them and consider the largest
    int mx = 1;
    for (int prev = 0; prev < idx; prev++)
        if (arr[prev] < arr[idx])
            mx = max(mx, lisEndingAtIdx(arr, prev, memo) + 1);

    // Store the result in the memo array
    memo[idx] = mx;
    return memo[idx];
}

int lis(vector<int>& arr) {
    
    int n = arr.size();
  
    vector<int> memo(n, -1);
  
    int res = 1;
    for (int i = 1; i < n; i++)
        res = max(res, lisEndingAtIdx(arr, i, memo));
    return res;
}

int main() {
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
    cout << lis(arr);
    return 0;
}
