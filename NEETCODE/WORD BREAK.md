139. Word Break
Medium
Topics
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= s.size(); i++) {
            for (const string& w : wordDict) {
                int start = i - w.length();
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];        
    }
};
```
Complexity
Time complexity: O(n∗m∗k)
n is length of input string.
m is number of words in wordDict
k is average size of substrings.

Space complexity: O(n)

Let's break down each line of the code and explain it in detail with an example.

### Code:
```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
```
- **Explanation**: This defines the function `wordBreak` inside the `Solution` class. It takes two arguments:
  - `s`: A string that we are trying to break into words.
  - `wordDict`: A vector of strings that acts as a dictionary of words we can use to segment the string `s`.
  
- **Example**:  
  - Input: `s = "applepenapple"`
  - `wordDict = ["apple", "pen"]`
  
  The goal is to check if we can split the string `s` into words from `wordDict`.

---

```cpp
vector<bool> dp(s.size() + 1, false);
```
- **Explanation**: This creates a dynamic programming (DP) array `dp` of size `s.size() + 1`. The `dp[i]` element will store whether the substring `s[0:i]` can be segmented into valid words from `wordDict`. The array is initialized to `false`.
  
- **Example**:
  - For the string `"applepenapple"`, `s.size() = 13`, so the `dp` array will have 14 elements: `[false, false, false, ..., false]`.

---

```cpp
dp[0] = true;
```
- **Explanation**: This sets `dp[0] = true`, meaning an empty string can always be segmented into words (trivially, with no words). It acts as the base case for the dynamic programming solution.
  
- **Example**:
  - After this, the DP array looks like: `[true, false, false, ..., false]`.

---

```cpp
unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
```
- **Explanation**: The `wordDict` is converted into an unordered set `wordSet` for efficient lookup. This allows us to check whether a word exists in the dictionary in constant time on average.
  
- **Example**:
  - For `wordDict = ["apple", "pen"]`, `wordSet` will be `{"apple", "pen"}`.

---

```cpp
for (int i = 1; i <= s.size(); i++) {
```
- **Explanation**: A loop starts from index `1` and iterates through the string `s` up to `s.size()`. We will check if the substring `s[0:i]` can be broken into valid words.
  
- **Example**: 
  - In the first iteration, `i = 1` refers to the first character `"a"` in `"applepenapple"`.
  - In the second iteration, `i = 2` refers to the substring `"ap"`, and so on.

---

```cpp
for (const string& w : wordDict) {
```
- **Explanation**: This is an inner loop that goes through every word `w` in the `wordDict`. The idea is to check if the word `w` can fit at the end of the substring `s[0:i]`.

- **Example**:
  - For `i = 5`, the substring `s[0:5] = "apple"`, so we will check the words in the dictionary `["apple", "pen"]`.

---

```cpp
int start = i - w.length();
```
- **Explanation**: This calculates the starting index `start` of the substring of length `w.length()` that we want to match with `w`. The goal is to see if the last part of the current substring `s[0:i]` matches the word `w`.

- **Example**:
  - For `i = 5` and `w = "apple"`, `start = 5 - 5 = 0`. So, we're checking if the substring `s[0:5] = "apple"` matches the word `"apple"`.

---

```cpp
if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
```
- **Explanation**: This condition checks three things:
  1. `start >= 0`: Ensures the start index is valid (non-negative).
  2. `dp[start]`: Checks if the substring `s[0:start]` can be segmented into valid words (i.e., if the string up to `start` has been successfully split before).
  3. `s.substr(start, w.length()) == w`: Verifies if the substring starting at `start` matches the word `w`.

- **Example**:
  - For `i = 5` and `w = "apple"`, `start = 0` and `dp[0] == true` (since `dp[0]` is always `true`). Also, `s.substr(0, 5) == "apple"`, so the condition is satisfied.

---

```cpp
dp[i] = true;
```
- **Explanation**: If the condition is satisfied, it means that the substring `s[0:i]` can be segmented using words from `wordDict`. Thus, we set `dp[i] = true`.

- **Example**:
  - For `i = 5`, since `"apple"` is a valid word and `dp[0] == true`, we set `dp[5] = true`.
  - After this, the DP array looks like: `[true, false, false, false, false, true, false, ..., false]`.

---

```cpp
break;
```
- **Explanation**: Once a valid word `w` is found for the substring `s[0:i]`, we break out of the inner loop, as we don’t need to check other words for this index.

---

```cpp
return dp[s.size()];
```
- **Explanation**: After processing all indices, the value `dp[s.size()]` will tell us whether the entire string `s` can be segmented using words from `wordDict`. The function returns this value.
  
- **Example**:
  - For `s = "applepenapple"`, after processing, `dp[13] == true`, indicating that the string can be segmented into valid words.
  
---

### Dry Run Example

Let’s dry run the code with an example:

```cpp
s = "applepenapple"
wordDict = ["apple", "pen"]
```

1. **Initialization**:
   - `dp = [true, false, false, false, false, false, false, false, false, false, false, false, false, false]`
   - `wordSet = {"apple", "pen"}`

2. **First iteration (`i = 1`)**:
   - Check each word in `wordDict`:
     - For `"apple"`: `start = 1 - 5 = -4` (invalid, so skip).
     - For `"pen"`: `start = 1 - 3 = -2` (invalid, so skip).
   - No match found, `dp[1]` remains `false`.

3. **Second iteration (`i = 2`)**:
   - Similar to the first iteration, no valid words are found that match the substring `s[0:2]`.

4. **Fifth iteration (`i = 5`)**:
   - Check `"apple"`: 
     - `start = 5 - 5 = 0` and `dp[0] == true`, and `s.substr(0, 5) == "apple"`, so set `dp[5] = true`.
   - Break the loop. The DP array is now: `[true, false, false, false, false, true, false, ..., false]`.

5. **Sixth iteration (`i = 6`) to Ninth iteration (`i = 9`)**:
   - No match found in these iterations.

6. **Tenth iteration (`i = 10`)**:
   - Check `"pen"`: 
     - `start = 10 - 3 = 7` and `dp[7] == true`, and `s.substr(7, 3) == "pen"`, so set `dp[10] = true`.

7. **Thirteenth iteration (`i = 13`)**:
   - Check `"apple"`:
     - `start = 13 - 5 = 8` and `dp[8] == true`, and `s.substr(8, 5) == "apple"`, so set `dp[13] = true`.

Finally, the DP array looks like: `[true, false, false, false, false, true, false, false, false, true, false, false, false, true]`.

Since `dp[13] == true`, the function returns `true`, meaning that the string `"applepenapple"` can be segmented into `"apple"`, `"pen"`, and `"apple"`.

Let’s go through the code step by step, explaining each part of the logic, followed by an example to illustrate how it works.

### Code:

```cpp
class Solution {
```
- **Explanation**: Declares the `Solution` class, where the function `wordBreak()` is defined.

---

```cpp
public:
```
- **Explanation**: Declares that the functions and members inside the `public` section of the class are accessible from outside.

---

```cpp
bool wordBreak(string s, vector<string>& wordDict) {
```
- **Explanation**: This function takes two arguments:
  - `s`: A string that we are trying to break into words.
  - `wordDict`: A vector of strings (the dictionary) containing valid words that can be used to form the string `s`.
- **Example**:
  - `s = "leetcode"`
  - `wordDict = ["leet", "code"]`
  - We are tasked with determining if we can segment the string `s` into one or more words from `wordDict`.

---

```cpp
vector<bool> dp(s.size() + 1, false);
```
- **Explanation**: Initializes a dynamic programming (DP) array `dp` of size `s.size() + 1` (one extra element for convenience). Each element in `dp[i]` will be `true` if the substring `s[0:i]` can be segmented into words from `wordDict`. Initially, all values in `dp` are set to `false`.
- **Example**:
  - For `s = "leetcode"`, the `dp` array will be of size 9 (since `s.size() = 8`).

---

```cpp
dp[0] = true;
```
- **Explanation**: This sets `dp[0] = true`, indicating that an empty string (a string of length 0) can always be segmented.
- **Example**:
  - After this, the `dp` array looks like: `[true, false, false, false, false, false, false, false, false]`.

---

```cpp
unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
```
- **Explanation**: Converts the `wordDict` into an unordered set called `wordSet` for faster lookup. This set contains all the words from the dictionary.
- **Example**:
  - For `wordDict = ["leet", "code"]`, `wordSet` will be `{"leet", "code"}`.

---

```cpp
for (int i = 1; i <= s.size(); i++) {
```
- **Explanation**: This `for` loop iterates over each index `i` from 1 to `s.size()`. For each `i`, the goal is to check if the substring `s[0:i]` can be segmented into valid words.

---

```cpp
for (const string& w : wordDict) {
```
- **Explanation**: For each index `i`, another loop checks all the words `w` in `wordDict`. The idea is to see if the word `w` can be the last word in the substring `s[0:i]`.

---

```cpp
int start = i - w.length();
```
- **Explanation**: This calculates the starting index of the substring that matches the word `w`. If the length of `w` is `w.length()`, then the starting index for checking that word would be `i - w.length()`.

---

```cpp
if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
```
- **Explanation**: This condition checks three things:
  1. `start >= 0`: Ensure that the starting index for the word `w` is valid (not out of bounds).
  2. `dp[start]`: Check if the substring `s[0:start]` can be segmented. If `dp[start] == true`, it means the substring up to `start` can be split into valid words.
  3. `s.substr(start, w.length()) == w`: Check if the substring from `start` to `i` is exactly equal to the word `w`.

---

```cpp
dp[i] = true;
```
- **Explanation**: If the conditions in the `if` statement are met, it means that the substring `s[0:i]` can be segmented. So, we set `dp[i] = true`.

---

```cpp
break;
```
- **Explanation**: If a valid word `w` is found that makes the substring `s[0:i]` segmentable, there is no need to check further words for this index. The loop breaks and moves on to the next `i`.

---

```cpp
}
```
- **Explanation**: Ends the inner `for` loop that iterates through `wordDict`.

---

```cpp
return dp[s.size()];
```
- **Explanation**: After processing all the indices, the value of `dp[s.size()]` will tell us whether the entire string `s` can be segmented into valid words. The function returns this boolean value.
- **Example**:
  - For `s = "leetcode"`, the function would return `true`, because the string can be split into `"leet"` and `"code"`.

---

### Dry Run Example:

Let’s dry-run the code with the example:

```cpp
s = "leetcode"
wordDict = ["leet", "code"]
```

1. **Initialization**:
   - `dp = [true, false, false, false, false, false, false, false, false]`
   - `wordSet = {"leet", "code"}`

2. **First iteration (`i = 1`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 1 - 4 = -3` (invalid, so skip).
     - For `"code"`: `start = 1 - 4 = -3` (invalid, so skip).
   - No match found, `dp[1]` remains `false`.

3. **Second iteration (`i = 2`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 2 - 4 = -2` (invalid, so skip).
     - For `"code"`: `start = 2 - 4 = -2` (invalid, so skip).
   - No match found, `dp[2]` remains `false`.

4. **Third iteration (`i = 3`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 3 - 4 = -1` (invalid, so skip).
     - For `"code"`: `start = 3 - 4 = -1` (invalid, so skip).
   - No match found, `dp[3]` remains `false`.

5. **Fourth iteration (`i = 4`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 4 - 4 = 0`, and `dp[0] == true`, and `s.substr(0, 4) == "leet"`. So, `dp[4] = true` (we can segment `"leet"`).
   - No need to check `"code"`, break the inner loop.

   Now, `dp = [true, false, false, false, true, false, false, false, false]`.

6. **Fifth iteration (`i = 5`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 5 - 4 = 1`, but `dp[1] == false`, so skip.
     - For `"code"`: `start = 5 - 4 = 1`, but `dp[1] == false`, so skip.
   - No match found, `dp[5]` remains `false`.

7. **Sixth iteration (`i = 6`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 6 - 4 = 2`, but `dp[2] == false`, so skip.
     - For `"code"`: `start = 6 - 4 = 2`, but `dp[2] == false`, so skip.
   - No match found, `dp[6]` remains `false`.

8. **Seventh iteration (`i = 7`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 7 - 4 = 3`, but `dp[3] == false`, so skip.
     - For `"code"`: `start = 7 - 4 = 3`, but `dp[3] == false`, so skip.
   - No match found, `dp[7]` remains `false`.

9. **Eighth iteration (`i = 8`)**:
   - Check each word in `wordDict`:
     - For `"leet"`: `start = 8 - 4 = 4`, but `dp[4] == true`, and `s.substr(4, 4) == "code"`. So, `dp[8] = true` (we can segment `"leet"` and `"code"`).
   - Break the inner loop.

   Now, `dp = [true, false, false, false, true, false, false, false, true]`.

10. **Return**:
    - `dp[8] == true

`, so return `true`.

### Conclusion:
- The function returns `true`, indicating that the string `"leetcode"` can be segmented into `"leet"` and `"code"`.
