https://leetcode.com/problems/counting-bits/description/

----

338. Counting Bits
Easy
Topics
Companies
Hint
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

---

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        // Create a vector of size n + 1
        vector<int> result(n + 1, 0);

        // Base case: if n is 0, return the vector
        if (n == 0) {
            return result;
        }

        // Base cases:
        // Set the first two elements of the vector
        result[0] = 0;
        if (n >= 1) {
            result[1] = 1;
        }

        // Iterate from 2 to n
        for (int x = 2; x <= n; ++x) {
            // If 'x' is even, set the x-th element of the vector to
            // the (x / 2)-th element
            if (x % 2 == 0) {
                result[x] = result[x / 2];
            }
            // If x is odd, set the x-th element of the vector to
            // the (x / 2)-th element + 1
            else {
                result[x] = result[x / 2] + 1;
            }
        }

        // Return the final vector
        return result;
    }
};
```
---
```cpp
 Intuition
The intuition behind this problem is to recognize that the number of 1's in the binary representation of a number can be calculated using the information from previously computed numbers. Specifically, we can use the fact that shifting a number right by 1 (i>>1) gives us a number with the same bit count except for possibly the least significant bit.

Approach
The approach used here is dynamic programming. We start with an array initialized with 0 for the first element (since 0 has no 1's in its binary representation). Then, for each number i from 1 to n:

We use the result for i >> 1 (which is i / 2 for positive integers).
We add 1 if i is odd (i.e., if the least significant bit is 1).
This works because i >> 1 is essentially i with its least significant bit removed. So, we're using the count of 1's in i >> 1 and adding 1 if i itself is odd.

Complexity
Time complexity: O(n)
We iterate through the numbers from 1 to n once, performing constant time operations for each number.

Space complexity:O(n)
We use an additional array of size n+1 to store the results.

Code
class Solution {
public:
    vector<int> countBits(int n){
        vector<int>result(n+1,0);
        for(int i=1;i<=n;i++){
            result[i] = result[i>>1]+(i&1);
        }
        return result;
    }
};
```
