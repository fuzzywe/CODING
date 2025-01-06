https://leetcode.com/problems/ugly-number-ii/description/



264. Ugly Number II
Medium
Topics
Companies
Hint
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.


```cpp

Heap Method
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> uglyHeap;
        unordered_set<long> visited;
        
        uglyHeap.push(1);
        visited.insert(1);
        
        long curr;
        for (int i = 0; i < n; ++i) {
            curr = uglyHeap.top();
            uglyHeap.pop();
            for (int prime : primes) {
                long new_ugly = curr * prime;
                if (visited.find(new_ugly) == visited.end()) {
                    uglyHeap.push(new_ugly);
                    visited.insert(new_ugly);
                }
            }
        }
        return (int)curr;
    }
};

```
---

DP

```cpp


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes = {2, 3, 5};  // Initialize the primes array
        vector<int> indices = {0, 0, 0}; // Initialize indices for multiples of 2, 3, 5
        vector<int> uglyArr(1, 1);       // Initialize the ugly number array with 1

        for (int i = 1; i < n; ++i) {
            // Calculate the next possible ugly numbers
            vector<int> next_uglies = {
                uglyArr[indices[0]] * primes[0],
                uglyArr[indices[1]] * primes[1],
                uglyArr[indices[2]] * primes[2]
            };
            int min_value = *min_element(next_uglies.begin(), next_uglies.end()); // Find the smallest value
            uglyArr.push_back(min_value); // Append the smallest value to uglyArr

            // Update indices for primes that generated the current min_value
            for (int j = 0; j < 3; ++j) {
                if (next_uglies[j] == min_value) {
                    ++indices[j];
                }
            }
        }

        return uglyArr[n - 1];
    }
};

```
