97. Interleaving String
Medium
Topics
Companies
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true

Complexity:
The primary advantage of this 1D DP approach is its space efficiency. While it maintains the same time complexity as the 2D DP approach O(m×n), the space complexity is optimized to O(min(m,n)).

Time Complexity:

The solution iterates over each character of s1 and s2 once, leading to a complexity of O(m×n).
Space Complexity:

The space complexity is optimized to O(min(m,n)) as we're only using a single 1D array instead of a 2D matrix.
```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), l = s3.length();
        if (m + n != l) return false;
        
        if (m < n) return isInterleave(s2, s1, s3);

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int j = 1; j <= n; ++j) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= m; ++i) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= n; ++j) {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        
        return dp[n];
    }
};
```
 This C++ code defines a function `isInterleave` that checks if a string `s3` is an interleaving of two other strings `s1` and `s2`. An interleaving of `s1` and `s2` means that `s3` is formed by merging `s1` and `s2`, preserving the order of characters in both strings.

### Code Explanation with Example and Dry Run

#### Example
Let's take:
- `s1 = "abc"`
- `s2 = "def"`
- `s3 = "adbcef"`

We will dry-run the code on this example.

### Line-by-Line Explanation

```cpp
int m = s1.length(), n = s2.length(), l = s3.length();
```
- **Explanation**: This line calculates the lengths of the three strings:
  - `m` is the length of `s1` (`m = 3` for `"abc"`),
  - `n` is the length of `s2` (`n = 3` for `"def"`),
  - `l` is the length of `s3` (`l = 6` for `"adbcef"`).

```cpp
if (m + n != l) return false;
```
- **Explanation**: If the total length of `s1` and `s2` is not equal to the length of `s3`, return `false` because it's impossible for `s3` to be an interleaving. In our case, `m + n = 6` and `l = 6`, so the function continues.

```cpp
if (m < n) return isInterleave(s2, s1, s3);
```
- **Explanation**: This swaps `s1` and `s2` if `s1` is shorter than `s2`, to ensure `s1` is always the longer string. This simplifies the dynamic programming (DP) approach. In our example, `m = n`, so no swapping occurs.

```cpp
vector<bool> dp(n + 1, false);
dp[0] = true;
```
- **Explanation**: A 1D DP array `dp` of size `n + 1` is created and initialized to `false`. The `dp` array helps track whether a prefix of `s2` (up to index `j`) and a prefix of `s1` (up to index `i`) can form a prefix of `s3` (up to index `i + j`). `dp[0]` is set to `true`, meaning an empty `s1` and `s2` can form an empty `s3`.

```cpp
for (int j = 1; j <= n; ++j) {
    dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
}
```
- **Explanation**: This loop fills out the `dp` array for the case where `s1` is empty, and only `s2` needs to match with `s3`. Specifically, if the previous `dp[j-1]` is `true` and the `j-th` character of `s2` matches the `j-th` character of `s3`, set `dp[j]` to `true`. Otherwise, it's `false`.

- **Dry Run** for this step with `s2 = "def"` and `s3 = "adbcef"`:
  - `j = 1`: `dp[1] = dp[0] && s2[0] == s3[0] → false` (because `"d" != "a"`)
  - `j = 2`: `dp[2] = dp[1] && s2[1] == s3[1] → false` (because `dp[1] = false`)
  - `j = 3`: `dp[3] = dp[2] && s2[2] == s3[2] → false`

So, the `dp` array after this loop is `[true, false, false, false]`.

```cpp
for (int i = 1; i <= m; ++i) {
    dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
```
- **Explanation**: This handles the case where `s2` is empty, and we only need `s1` to match `s3`. If `dp[0]` remains `true` and the characters of `s1` match `s3`, it updates `dp[0]`.

- **Dry Run**:
  - For `i = 1`: `dp[0] = dp[0] && s1[0] == s3[0] → true` (because `"a" == "a"`)
  - For `i = 2`: `dp[0] = dp[0] && s1[1] == s3[1] → true` (because `"b" == "b"`)
  - For `i = 3`: `dp[0] = dp[0] && s1[2] == s3[2] → false` (because `"c" != "d"`)

```cpp
for (int j = 1; j <= n; ++j) {
    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
```
- **Explanation**: This is the core DP update where we consider both strings `s1` and `s2`. The idea is that `dp[j]` will be `true` if:
  - Either the previous `dp[j]` is `true` and `s1[i-1]` matches `s3[i+j-1]`,
  - Or `dp[j-1]` is `true` and `s2[j-1]` matches `s3[i+j-1]`.

- **Dry Run** for `i = 1`:
  - For `j = 1`: `dp[1] = (dp[1] && s1[0] == s3[1]) || (dp[0] && s2[0] == s3[1]) → true` (because `"d" == "d"`)
  - For `j = 2`: `dp[2] = (dp[2] && s1[0] == s3[2]) || (dp[1] && s2[1] == s3[2]) → true` (because `"e" == "e"`)
  - For `j = 3`: `dp[3] = (dp[3] && s1[0] == s3[3]) || (dp[2] && s2[2] == s3[3]) → true` (because `"f" == "f"`)

So, after the first iteration, the `dp` array becomes `[true, true, true, true]`.

The loop continues for the rest of the iterations (`i = 2`, `i = 3`), updating the DP table in a similar manner.

```cpp
return dp[n];
```
- **Explanation**: After completing the DP table, the last value `dp[n]` holds the result. If it's `true`, `s3` is a valid interleaving of `s1` and `s2`. In our case, the final value of `dp[3]` will be `true`, so the function returns `true`.

### Final Dry Run

For `s1 = "abc"`, `s2 = "def"`, and `s3 = "adbcef"`, the DP table correctly updates, and the function returns `true` as `s3` is a valid interleaving of `s1` and `s2`.
