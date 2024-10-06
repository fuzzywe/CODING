17. Letter Combinations of a Phone Number
Medium
Topics
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        if (digits.empty()) {
            return res;
        }
        
        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        
        backtrack(digits, 0, "", res, digitToLetters);
        
        return res;        
    }

    void backtrack(const string& digits, int idx, string comb, vector<string>& res, const unordered_map<char, string>& digitToLetters) {
        if (idx == digits.length()) {
            res.push_back(comb);
            return;
        }
        
        string letters = digitToLetters.at(digits[idx]);
        for (char letter : letters) {
            backtrack(digits, idx + 1, comb + letter, res, digitToLetters);
        }
    }    
};
```
Let's break down each line of the code, explaining it in detail with an example and then performing a dry run of the entire code.

### Problem Context
This problem is about generating all possible letter combinations that a phone number could represent. Each digit on the phone's keypad maps to a set of letters (like '2' maps to "abc", '3' to "def", etc.). The task is to return all possible letter combinations given a string of digits.

### Code Breakdown

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
```
- **Explanation**: This defines a class `Solution` with a method `letterCombinations` that takes a string `digits` as input and returns a vector of strings containing all possible letter combinations.
- **Example**: Let's consider the input `digits = "23"`. This means we need to find all combinations of letters that map to these digits (2 maps to "abc" and 3 maps to "def").

---

```cpp
vector<string> res;
```
- **Explanation**: This is the result vector `res` that will store all valid letter combinations.
- **Example**: Initially, `res = []`.

---

```cpp
if (digits.empty()) {
    return res;
}
```
- **Explanation**: This condition checks if the input `digits` string is empty. If it is, it returns an empty result vector since no combinations can be formed.
- **Example**: If `digits = ""`, we return `[]`.

---

```cpp
unordered_map<char, string> digitToLetters = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
```
- **Explanation**: This map `digitToLetters` stores the mapping of digits to their respective letters (like a phone keypad). Each digit from 2 to 9 maps to a string of letters.
- **Example**: For digit '2', `digitToLetters['2'] = "abc"`; for '3', `digitToLetters['3'] = "def"`.

---

```cpp
backtrack(digits, 0, "", res, digitToLetters);
```
- **Explanation**: This is the initial call to the `backtrack` function, which performs a recursive depth-first search (DFS) to generate all combinations.
  - `digits` is the input string.
  - `0` is the current index in the digits string.
  - `""` is the current combination being built.
  - `res` is the result vector that will store all valid combinations.
  - `digitToLetters` is the map of digits to letters.
- **Example**: The call is `backtrack("23", 0, "", res, digitToLetters)`.

---

```cpp
return res;
```
- **Explanation**: Once all combinations have been generated, this returns the result vector containing all the letter combinations.
- **Example**: The result might be `["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]` for input `"23"`.

---

### Backtrack Function Breakdown

```cpp
void backtrack(const string& digits, int idx, string comb, vector<string>& res, const unordered_map<char, string>& digitToLetters) {
```
- **Explanation**: This is the helper function `backtrack` that performs the recursive backtracking.
  - `digits`: The input string of digits.
  - `idx`: The current index in the digits string.
  - `comb`: The current combination of letters being formed.
  - `res`: The result vector to store all combinations.
  - `digitToLetters`: The map of digits to their corresponding letters.

---

```cpp
if (idx == digits.length()) {
    res.push_back(comb);
    return;
}
```
- **Explanation**: This is the base case for the recursion. If `idx` is equal to the length of the `digits` string, it means a complete combination has been formed, so we add it to the result vector `res` and return.
- **Example**: When we reach `idx = 2` for `digits = "23"`, it means we've formed a valid combination like `"ad"`, and we add it to `res`.

---

```cpp
string letters = digitToLetters.at(digits[idx]);
```
- **Explanation**: This retrieves the string of letters corresponding to the current digit at index `idx`. For example, if the current digit is '2', `letters = "abc"`.
- **Example**: For `digits = "23"` and `idx = 0`, `letters = "abc"`.

---

```cpp
for (char letter : letters) {
    backtrack(digits, idx + 1, comb + letter, res, digitToLetters);
}
```
- **Explanation**: This loop iterates over each letter in the `letters` string and calls `backtrack` recursively for the next digit (i.e., incrementing `idx + 1`). It appends the current letter to the `comb` string to form the next combination.
- **Example**: For `letters = "abc"`, the loop will first append `'a'` to `comb` and call `backtrack` for the next digit, then `'b'`, and so on.

---

### Dry Run with Input `digits = "23"`

- **Initial Input**: `digits = "23"`
  - `digitToLetters['2'] = "abc"`
  - `digitToLetters['3'] = "def"`

#### Step-by-Step Execution:

1. Start with `backtrack("23", 0, "", res, digitToLetters)`
   - `idx = 0`, `comb = ""`, `letters = "abc"`
   - Loop over `"abc"`:
     - For `'a'`: `comb = "a"`, call `backtrack("23", 1, "a", res, digitToLetters)`
     - For `'b'`: `comb = "b"`, call `backtrack("23", 1, "b", res, digitToLetters)`
     - For `'c'`: `comb = "c"`, call `backtrack("23", 1, "c", res, digitToLetters)`

2. Processing the first branch:
   - For `'a'`: `backtrack("23", 1, "a", res, digitToLetters)`
     - `idx = 1`, `comb = "a"`, `letters = "def"`
     - Loop over `"def"`:
       - For `'d'`: `comb = "ad"`, call `backtrack("23", 2, "ad", res, digitToLetters)` (base case: `res.push_back("ad")`)
       - For `'e'`: `comb = "ae"`, call `backtrack("23", 2, "ae", res, digitToLetters)` (base case: `res.push_back("ae")`)
       - For `'f'`: `comb = "af"`, call `backtrack("23", 2, "af", res, digitToLetters)` (base case: `res.push_back("af")`)

3. Processing the second branch:
   - For `'b'`: `backtrack("23", 1, "b", res, digitToLetters)`
     - `idx = 1`, `comb = "b"`, `letters = "def"`
     - Loop over `"def"`:
       - For `'d'`: `comb = "bd"`, call `backtrack("23", 2, "bd", res, digitToLetters)` (base case: `res.push_back("bd")`)
       - For `'e'`: `comb = "be"`, call `backtrack("23", 2, "be", res, digitToLetters)` (base case: `res.push_back("be")`)
       - For `'f'`: `comb = "bf"`, call `backtrack("23", 2, "bf", res, digitToLetters)` (base case: `res.push_back("bf")`)

4. Processing the third branch:
   - For `'c'`: `backtrack("23", 1, "c", res, digitToLetters)`
     - `idx = 1`, `comb = "c"`, `letters = "def"`
     - Loop over `"def"`:
       - For `'d'`: `comb = "cd"`, call `backtrack("23", 2, "cd", res, digitToLetters)` (base case: `res.push_back("cd")`)
       - For `'e'`: `comb = "ce"`, call `backtrack("23", 2, "ce", res, digitToLetters)` (base case: `res.push_back("ce")`)
       - For `'f'`: `comb = "cf"`, call `backtrack("23", 2, "cf", res, digitToLetters)` (base case: `res.push_back("cf")`)

---

### Final Output:
- `res = ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`

Thus, for the input `"23"`, the function will output all the possible letter combinations mapped from the digits.
