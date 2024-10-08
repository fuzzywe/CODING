Brute Force Approach:
Intuition
The idea is to divide the problem into smaller subproblems, and using them to calculate the answer for original problem.

Implementation
Let func(i,j) be the count of palindromic subsequences in string Str[i..j] (substring of string Str from index i to j, both inclusive),
then this function can be defined as:

if i == j :
  return 1 // palindrome of length 1

// If first and last characters are same, then we 
// consider it as palindrome subsequence and check
// for the rest subsequence (i+1, j), (i, j-1)
Else if (str[i] == str[j]) :
  return   func(i+1, j) + func(i, j-1) + 1

Else :
  // check for rest sub-sequence and  remove common
  // palindromic subsequences as they are counted
  // twice when we do func(i+1, j) + func(i,j-1)
  return func(i+1, j) + func(i, j-1) - func(i+1, j-1).

Complexity
Time Complexity: O(3^(n*n)), it is exponential increasing which can see using recursion tree, it is not a tight bound.
Auxiliary Space: O(n), as max number of stack frames in recursion tree of it will have n frames.


```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        int ans = 0;

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                if (s[i] == s[i + len - 1] && (len <= 2 || palindrome[i + 1][i + len - 2])) {
                    palindrome[i][i + len - 1] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};
```
https://leetcode.com/problems/palindromic-substrings/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO
