// Given a number n, the task is to find all prime factors of n.

// Examples:

// Input: n = 24
// Output: 2 2 2 3
// Explanation: The prime factorization of 24 is 23×3.Given a number n, the task is to find all prime factors of n.

// Examples:

// Input: n = 24
// Output: 2 2 2 3
// Explanation: The prime factorization of 24 is 23×3.

// C++ program to print all prime factors 
#include <bits/stdc++.h>
using namespace std;

// A function to print all prime 
// factors of a given number n 
void primeFactors(int n) {
  
    // Print the number of 2s that divide n 
    while (n % 2 == 0) {
      
        cout << 2 << " "; 
        n = n/2; 
    } 

    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i*i <= n; i = i + 2) {
      
        // While i divides n, print i and divide n 
        while (n % i == 0) {
          
            cout << i << " "; 
            n = n/i; 
        } 
    } 

    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2) 
        cout << n << " "; 
} 


int main() {
  
    int n = 315; 
    primeFactors(n); 
    return 0; 
} 
