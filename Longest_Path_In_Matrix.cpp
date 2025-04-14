// Find the longest path in a matrix with given constraints
// Last Updated : 16 Dec, 2024
// Given an n*m matrix where all numbers are distinct, the task is to find the maximum length path (starting from any cell) such that all cells along the path are in increasing order with a difference of 1. 
// We can move in 4 directions from a given cell (i, j), i.e., we can move to (i+1, j) or (i, j+1) or (i-1, j) or (i, j-1) with the condition that the adjacent cells have a difference of 1.

// Example: 

// Input:
// n = 3, m = 3
// matrix[][] = [[1 2 9],
//                      [5 3 8],
//                     [4 6 7]]


// Output: 4
// Explanation:  The longest increasing path is  [6, 7, 8, 9]. 

// C++ program to find the longest path
// in a matrix with given constraints
#include <bits/stdc++.h>
using namespace std;

int longestPath(int i, int j, vector<vector<int>> &matrix) {
    int ans = 1;

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Check for all 4 directions
    for (auto d : dir) {
        int x = i + d[0];
        int y = j + d[1];

        // If new cells are valid and
        // increasing by 1.
        if (x >= 0 && x < matrix.size() && y >= 0 && 
            y < matrix[0].size() && matrix[x][y] == matrix[i][j] + 1) {
            ans = max(ans, 1 + longestPath(x, y, matrix));
        }
    }

    return ans;
}

int longestIncreasingPath(vector<vector<int>> &matrix) {
    int ans = 0;

    // Find length of longest path
    // from each cell i, j
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            int val = longestPath(i, j, matrix);
            ans = max(ans, val);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 9}, {5, 3, 8}, {4, 6, 7}};
    cout << longestIncreasingPath(matrix);

    return 0;
}


// Using DFS and Memoization – O(n*m) Time and O(n*m) Space
// The idea is to use memoization to avoid recomputing same subproblems. In the recursive solution, multiple recursive calls can explore the same cell multiple times from different paths, leading to exponential time complexity. 


// For example, if a cell can be reached through multiple different paths, the recursive DFS will recompute the maximum path length for that cell each time it is encountered, resulting in repeated and unnecessary calculations. 


// Memoization solves this by storing the maximum path length for each cell after its first computation, allowing immediate retrieval of previously calculated results and preventing redundant recursive calls.


// Step by step approach:

// Create a memoization matrix[][] memo of size n*m, initialized with -1 to indicate no computations have been made yet.
// Each memo[i][j] will store the maximum path length starting from cell (i, j).
// If a cell’s maximum path length is not yet computed (memo[i][j] == -1), perform the DFS exploration.
// During DFS, explore all four adjacent cells that satisfy the strictly increasing condition of difference 1.
// When a valid path is found from a cell, store its maximum path length in memo[i][j].
// If a cell’s maximum path length is already computed, directly return the memoized value.

// C++ program to find the longest path 
// in a matrix with given constraints
#include <bits/stdc++.h>
using namespace std;

int longestPath(int i, int j, vector<vector<int>> &matrix, 
vector<vector<int>> &memo) {
    
    // If value is memoized
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    
    int ans = 1;
    
    vector<vector<int>> dir = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
    
    // Check for all 4 directions
    for (auto d: dir) {
        int x = i+d[0];
        int y = j+d[1];
        
        // If new cells are valid and 
        // increasing by 1.
        if (x>=0 && x<matrix.size() && y>=0 && 
        y<matrix[0].size() && matrix[x][y]==matrix[i][j]+1) {
            ans = max(ans, 1+longestPath(x, y, matrix, memo));
        }
    }
    
    return memo[i][j] = ans;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int ans = 0;
    
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    
    // Find length of longest path 
    // from each cell i, j
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            int val = longestPath(i, j, matrix, memo);
            ans = max(ans, val);
        }
    }
    
    return ans;
}

int main() {
    vector<vector<int>> matrix = 
    {{1, 2, 9},
    {5, 3, 8},
    {4, 6, 7}};
    cout << longestIncreasingPath(matrix);

    return 0;
}
