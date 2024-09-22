Longest Palindrome in a String
Difficulty: MediumAccuracy: 23.2%Submissions: 302K+Points: 4
Given a string str, find the longest palindromic substring in str. Substring of string str: str[ i . . . . j ] where 0 ≤ i ≤ j < len(str). Return the longest palindromic substring of str.

Palindrome string: A string that reads the same backward. More formally, str is a palindrome if reverse(str) = str. In case of conflict, return the substring which occurs first ( with the least starting index).

Examples :

Input: str = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic substring is "aabbaa".
Input: str = "abc"
Output: a
Explanation: "a", "b" and "c" are the longest palindromes with same length. The result is the one with the least starting index.
Expected Time Complexity: O(|str|2).
Expected Auxiliary Space: O(1).


  Approach 3: Dynamic Programming
Intuition :
image.png

To improve over the brute force solution, we first observe how we can avoid unnecessary re-computation while validating palindromes. Consider the case "ababa". If we already knew that "bab" is a palindrome, it is obvious that "ababa" must be a palindrome since the two left and right end letters are the same.

Algorithm :
We initialize a boolean table dp and mark all the values as false.
We will use a variable max_len to keep track of the maximum length of the palindrome.
We will iterate over the string and mark the diagonal elements as true as every single character is a palindrome.
Now, we will iterate over the string and for every character we will expand around its center.
For odd length palindrome, we will consider the current character as the center and expand around it.
For even length palindrome, we will consider the current character and the next character as the center and expand around it.
We will keep track of the maximum length and the maximum substring.
Print the maximum substring.
Complexity Analysis
Time complexity : O(n^2). This gives us a runtime complexity of O(n^2).

Space complexity : O(n^2). It uses O(n^2) space to store the table.

Code
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};

Let's break down the provided code and dry-run it to understand how it finds the longest palindromic substring.

### **Problem:**
The task is to find the longest palindromic substring in a given string `s`.

### **Approach:**
The approach uses **dynamic programming** to build a 2D table (`dp`) where `dp[i][j]` is `true` if the substring `s[i...j]` is a palindrome, and `false` otherwise.

### **Key Points:**
- **Base case:** Every single character is a palindrome by itself.
- **General case:** A substring `s[i...j]` is a palindrome if:
  - The characters at both ends are the same, i.e., `s[i] == s[j]`, and
  - The substring between them, i.e., `s[i+1...j-1]`, is also a palindrome, or the gap between `i` and `j` is less than or equal to 2 (for cases like "aa" or "aba").

### **Variables:**
- `max_len`: Stores the length of the longest palindrome found.
- `start` and `end`: Stores the starting and ending indices of the longest palindrome found.
- `dp[i][j]`: A 2D vector (boolean) to store whether the substring `s[i...j]` is a palindrome.

---

### **Dry Run:**

Let’s take the input string `s = "babad"` and dry run the code.

1. **Initialization:**
   - `max_len = 1`: Every single character is a palindrome of length 1.
   - `start = 0`, `end = 0`: Initially assume the first character is the longest palindrome.
   - `dp[i][i] = true` for all `i`: Every single character is a palindrome.

2. **Outer loop** (`i` loop):
   - Start iterating from the first character and expand to the right.

### Iterations:

- **Iteration 1 (`i = 0`):**
  - `dp[0][0] = true` (single character).
  - There's no `j` less than `i`, so no inner loop work for this iteration.

- **Iteration 2 (`i = 1`):**
  - `dp[1][1] = true` (single character).
  - **Inner loop (`j = 0`):**
    - `s[0] != s[1]`, so `dp[0][1] = false`.

- **Iteration 3 (`i = 2`):**
  - `dp[2][2] = true` (single character).
  - **Inner loop (`j = 1`):**
    - `s[1] == s[2]` and `(i - j <= 2)`:
      - So, `dp[1][2] = true`.
      - Update `max_len = 2`, `start = 1`, `end = 2`.
  - **Inner loop (`j = 0`):**
    - `s[0] != s[2]`, so `dp[0][2] = false`.

- **Iteration 4 (`i = 3`):**
  - `dp[3][3] = true` (single character).
  - **Inner loop (`j = 2`):**
    - `s[2] != s[3]`, so `dp[2][3] = false`.
  - **Inner loop (`j = 1`):**
    - `s[1] != s[3]`, so `dp[1][3] = false`.
  - **Inner loop (`j = 0`):**
    - `s[0] == s[3]` and `dp[1][2] = true`:
      - So, `dp[0][3] = true`.
      - Update `max_len = 4`, `start = 0`, `end = 3`.

- **Iteration 5 (`i = 4`):**
  - `dp[4][4] = true` (single character).
  - **Inner loop (`j = 3`):**
    - `s[3] != s[4]`, so `dp[3][4] = false`.
  - **Inner loop (`j = 2`):**
    - `s[2] == s[4]` and `(i - j <= 2)`:
      - So, `dp[2][4] = true`.
      - No update to `max_len` since it doesn't exceed the current `max_len = 4`.

---

### **Final Result:**
The longest palindrome found is `"bab"` (or `"aba"`, both are of the same length).

### **Time Complexity:**
- The code runs two nested loops, each running up to `n` (the length of the string), resulting in a time complexity of **O(n^2)**.

---

### **Example Walkthrough:**
For the input `s = "babad"`:
- The function will return `"bab"` or `"aba"`, as both are valid longest palindromic substrings.

I hope this helps you better understand the code! Let me know if you need further clarification.

Approach 4: Manacher's Algorithm
image.png

Intuition :
To avoid the unnecessary validation of palindromes, we can use Manacher's algorithm. The algorithm is explained brilliantly in this article. The idea is to use palindrome property to avoid unnecessary validations. We maintain a center and right boundary of a palindrome. We use previously calculated values to determine if we can expand around the center or not. If we can expand, we expand and update the center and right boundary. Otherwise, we move to the next character and repeat the process. We also maintain a variable max_len to keep track of the maximum length of the palindrome. We also maintain a variable max_str to keep track of the maximum substring.

Algorithm :
We initialize a boolean table dp and mark all the values as false.
We will use a variable max_len to keep track of the maximum length of the palindrome.
We will iterate over the string and mark the diagonal elements as true as every single character is a palindrome.
Now, we will iterate over the string and for every character we will expand around its center.
For odd length palindrome, we will consider the current character as the center and expand around it.
For even length palindrome, we will consider the current character and the next character as the center and expand around it.
We will keep track of the maximum length and the maximum substring.
Print the maximum substring.
Complexity Analysis
Time complexity : O(n). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n).

Space complexity : O(n). It uses O(n) space to store the table.

Code
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int maxLen = 1;
        std::string maxStr = s.substr(0, 1);
        s = "#" + std::regex_replace(s, std::regex(""), "#") + "#";
        std::vector<int> dp(s.length(), 0);
        int center = 0;
        int right = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (i < right) {
                dp[i] = std::min(right - i, dp[2 * center - i]);
            }
            
            while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length() && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
                dp[i]++;
            }
            
            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }
            
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxStr = s.substr(i - dp[i], 2 * dp[i] + 1);
                maxStr.erase(std::remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }
        
        return maxStr;
    }
};
