Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

Complexity
Time complexity: O(n∗m)
n is length of text1 and m is length of text2

Space complexity: O(n)
For dp list with length of text1

 ```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dp(text1.length(), 0);
        int longest = 0;

        for (char c : text2) {
            int curLength = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (curLength < dp[i]) {
                    curLength = dp[i];
                } else if (c == text1[i]) {
                    dp[i] = curLength + 1;
                    longest = max(longest, curLength + 1);
                }
            }
        }

        return longest;        
    }
};
```
Let's break down and understand each part of this code in detail. The code is an implementation of a function to find the **Longest Common Subsequence (LCS)** between two strings. This algorithm uses dynamic programming to solve the problem.

### Code Breakdown

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Create a dynamic programming array with size equal to the length of text1
        vector<int> dp(text1.length(), 0);
        
        // Variable to keep track of the length of the longest common subsequence
        int longest = 0;

        // Loop over each character of text2
        for (char c : text2) {
            // Variable to store the maximum value found in the previous row
            int curLength = 0;

            // Loop over each character of text1
            for (int i = 0; i < dp.size(); i++) {
                // If the current length is smaller than the dp[i], update curLength
                if (curLength < dp[i]) {
                    curLength = dp[i];
                } 
                // If characters of text1 and text2 match, update dp[i]
                else if (c == text1[i]) {
                    dp[i] = curLength + 1;
                    // Update the longest value if necessary
                    longest = max(longest, dp[i]);
                }
            }
        }

        // Return the length of the longest common subsequence
        return longest;        
    }
};
```

### Example
Let’s take two strings:
- `text1 = "abcde"`
- `text2 = "ace"`

The Longest Common Subsequence (LCS) here is `"ace"`, with a length of 3.

### Step-by-Step Explanation

1. **Creating DP Array**:
   ```cpp
   vector<int> dp(text1.length(), 0);
   ```
   A dynamic programming (DP) array `dp` is initialized with size equal to the length of `text1` (i.e., 5 in this case), and all elements are set to `0`. This array will help store the length of the LCS up to the current character.

   For our example:
   ```cpp
   dp = [0, 0, 0, 0, 0] // corresponds to "abcde"
   ```

2. **Tracking Longest Common Subsequence**:
   ```cpp
   int longest = 0;
   ```
   A variable `longest` is initialized to `0`. It will store the maximum length of the LCS found so far.

3. **Iterating through `text2`**:
   ```cpp
   for (char c : text2)
   ```
   This loop goes over each character in `text2`. For our example, it will iterate through the characters: `'a'`, `'c'`, `'e'`.

4. **Iterating through `text1`**:
   ```cpp
   for (int i = 0; i < dp.size(); i++)
   ```
   This loop goes through each character in `text1`. For each character in `text2`, we compare it with all the characters in `text1`.

5. **Checking for LCS Conditions**:
   - **Finding maximum subsequence so far**:
     ```cpp
     if (curLength < dp[i]) {
         curLength = dp[i];
     }
     ```
     `curLength` keeps track of the maximum length of the LCS found so far in the current iteration of `text2`.

   - **Matching characters**:
     ```cpp
     else if (c == text1[i]) {
         dp[i] = curLength + 1;
         longest = max(longest, dp[i]);
     }
     ```
     If `c` (current character of `text2`) matches `text1[i]`, it means that we found another matching character for the subsequence. We update `dp[i]` to be `curLength + 1`. Also, we update `longest` to keep track of the maximum LCS length found so far.

### Dry Run Example

Let’s dry run the code with `text1 = "abcde"` and `text2 = "ace"`:

#### Initialization
```cpp
dp = [0, 0, 0, 0, 0] // corresponds to "abcde"
longest = 0
```

#### Iterating through `text2`:

- **First iteration (`c = 'a'`)**:
   - Comparing `'a'` with `text1 = "abcde"`:
     - `curLength = 0`
     - When `i = 0`, `'a' == text1[0]`, so we set `dp[0] = 1` (LCS of length 1).
     - `dp = [1, 0, 0, 0, 0]`
     - Update `longest = 1`

- **Second iteration (`c = 'c'`)**:
   - Comparing `'c'` with `text1 = "abcde"`:
     - `curLength = 0`
     - When `i = 1`, `curLength = 1` (since `dp[0] = 1`).
     - When `i = 2`, `'c' == text1[2]`, so we set `dp[2] = 2` (LCS of length 2).
     - `dp = [1, 0, 2, 0, 0]`
     - Update `longest = 2`

- **Third iteration (`c = 'e'`)**:
   - Comparing `'e'` with `text1 = "abcde"`:
     - `curLength = 0`
     - When `i = 3`, `curLength = 2` (since `dp[2] = 2`).
     - When `i = 4`, `'e' == text1[4]`, so we set `dp[4] = 3` (LCS of length 3).
     - `dp = [1, 0, 2, 0, 3]`
     - Update `longest = 3`

### Final Output
After going through all the characters of `text2`, the longest common subsequence length is stored in `longest`, which is `3`.

### Summary of Dry Run:

- `text1 = "abcde"`
- `text2 = "ace"`
- LCS: `"ace"`, Length = 3

### Time Complexity
- **Time Complexity**: `O(n * m)`, where `n` is the length of `text1` and `m` is the length of `text2`, because we are iterating through both strings using nested loops.

