// Given a distance ‘dist’, count total number of ways to cover the distance with 1, 2 and 3 steps. 
// Input: n = 3
// Output: 4
// Explanation: Below are the four ways
// => 1 step + 1 step + 1 step
// => 1 step + 2 step
// => 2 step + 1 step
// => 3 step

// A naive recursive C++ program to count number of ways to
// cover a distance with 1, 2 and 3 steps
#include <iostream>
using namespace std;

// Returns count of ways to cover 'dist'
int printCountRec(int dist)
{
    // Base cases
    if (dist < 0)
        return 0;
    if (dist == 0)
        return 1;

    // Recur for all previous 3 and add the results
    return printCountRec(dist - 1) + printCountRec(dist - 2)
           + printCountRec(dist - 3);
}

// driver program
int main()
{
    int dist = 4;
    cout << printCountRec(dist);
    return 0;
}


// Count number of ways to cover a distance using Dynamic Programming
// The problem have overlapping subproblems, meaning that the same subproblems are encountered multiple times during the recursive computation. For example, when calculating the number of ways to cover distance ‘dist’, we need to calculate the number of ways to cover distances ‘dist-1’, ‘dist-2’, and ‘dist-3’. These subproblems are also encountered when calculating the number of ways to cover distances ‘dist-2’ and ‘dist-3’.



// Memoization solve this issue by storing the results of previously computed subproblems in a data structure, typically an array or a hash table.



// Before making a recursive call, we first check if the result for the current distance has already been computed and stored in the memo[] array. If it has, we directly return the stored result, avoiding the recursive call. This significantly reduces the number of recursive calls and improves the performance of the algorithm, especially for larger distances. Once the result for the current distance is computed, we store it in the memo[] array for future reference.

#include <iostream>
#include <vector>
using namespace std;

// Returns count of ways to cover 'dist' using memoization
int printCountRecMemo(int dist, vector<int>& memo)
{
    // Base cases
    if (dist < 0)
        return 0;
    if (dist == 0)
        return 1;

    // Check if the value for 'dist' is already computed
    if (memo[dist] != -1)
        return memo[dist];

    // Recur for all previous 3 and add the results
    int ways = printCountRecMemo(dist - 1, memo)
               + printCountRecMemo(dist - 2, memo)
               + printCountRecMemo(dist - 3, memo);

    // Memoize the result for 'dist' for future use
    memo[dist] = ways;

    return ways;
}

// Function to calculate the count of ways with memoization
int countWays(int dist)
{
    vector<int> memo(
        dist + 1,
        -1); // Initialize memoization array with -1
    return printCountRecMemo(dist, memo);
}

// Driver program
int main()
{
    int dist = 4;
    cout << countWays(dist);
    return 0;
}

// Count number of ways to cover a distance using Dynamic Programming (Tabluation):
// We start by initializing the base cases for covering distances 0, 1, and 2. For distance 0, there is only one way to cover it (do nothing). For distance 1, there is also only one way to cover it (take a step of size 1). For distance 2, there are two ways to cover it (take two steps of size 1 or take a step of size 2).



// We use a bottom-up approach to fill in the count[] array. For each entry count[i], we compute the number of ways to cover distance i by adding the number of ways to cover distances i-1, i-2, and i-3.



// Finally, we return the value of count[dist], which represents the number of ways to cover the given distance.

// A Dynamic Programming based C++ program to count number of ways
// to cover a distance with 1, 2 and 3 steps
#include<iostream>
using namespace std;

int printCountDP(int dist)
{
    int count[dist+1];

    // Initialize base values. There is one way to cover 0 and 1
    // distances and two ways to cover 2 distance
     count[0] = 1;
     if(dist >= 1)
            count[1] = 1;
     if(dist >= 2)
              count[2] = 2;

    // Fill the count array in bottom up manner
    for (int i=3; i<=dist; i++)
       count[i] = count[i-1] + count[i-2] + count[i-3];

    return count[dist];
}

// driver program
int main()
{
    int dist = 4;
    cout << printCountDP(dist);
    return 0;
}
