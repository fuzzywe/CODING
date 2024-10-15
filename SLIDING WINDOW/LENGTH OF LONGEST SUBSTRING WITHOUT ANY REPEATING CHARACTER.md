3. Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


The **time complexity (TC)** and **space complexity (SC)** of the algorithm are as follows:

- **Time Complexity (TC)**:  
  **O(n)**  
  - The `right` pointer traverses the entire string `s`, and each character is processed at most twice (once when added to the set and once when removed). Therefore, the time complexity is linear in the size of the input string, where `n` is the length of the string.

- **Space Complexity (SC)**:  
  **O(min(n, m))**  
  - The space complexity depends on the number of unique characters in the string. In the worst case, the set could contain all unique characters from the string. If `m` is the size of the character set (for example, 128 for ASCII or 256 for extended ASCII), the space complexity is the smaller of `n` (length of the string) or `m` (size of the character set).
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        unordered_set<char> set;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left++]);
            }
            set.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

```
Let's go through the C++ code line by line and visualize what happens in each step using the sliding window technique for the string `"abcabcbb"`:

### C++ Code:

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        unordered_set<char> set;
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left++]);
            }
            set.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
```

### Input: `"abcabcbb"`

---

#### Line 1: `unordered_set<char> set;`

- **Action**: We create an empty set to store the unique characters in the current window.
- **State**:
  - `set = {}` (empty)
  
---

#### Line 2: `int maxLen = 0;`

- **Action**: Initialize `maxLen` to store the length of the longest substring found so far.
- **State**:
  - `maxLen = 0`

---

#### Line 3: `int left = 0;`

- **Action**: Initialize `left` pointer, which will track the start of the sliding window.
- **State**:
  - `left = 0`

---

#### Line 4: `for (int right = 0; right < s.size(); right++) {`

- **Action**: Start iterating over the string `s` using the `right` pointer, which will expand the window.
  
---

### Iteration 1: `right = 0`, character = `'a'`

- **Check**: The `while` loop checks if `'a'` is in the set, but it’s not.
- **Action**: Insert `'a'` into the set.
  - `set = {'a'}`

- **Update**: Calculate `maxLen = max(0, 0 - 0 + 1) = 1`.
  - `maxLen = 1`

---

### Iteration 2: `right = 1`, character = `'b'`

- **Check**: `'b'` is not in the set.
- **Action**: Insert `'b'` into the set.
  - `set = {'a', 'b'}`

- **Update**: Calculate `maxLen = max(1, 1 - 0 + 1) = 2`.
  - `maxLen = 2`

---

### Iteration 3: `right = 2`, character = `'c'`

- **Check**: `'c'` is not in the set.
- **Action**: Insert `'c'` into the set.
  - `set = {'a', 'b', 'c'}`

- **Update**: Calculate `maxLen = max(2, 2 - 0 + 1) = 3`.
  - `maxLen = 3`

---

### Iteration 4: `right = 3`, character = `'a'`

- **Check**: `'a'` is already in the set. Enter the `while` loop.
- **Action**: Remove `'a'` (character at `left`) from the set and increment `left`:
  - `set = {'b', 'c'}`, `left = 1`

- **Exit `while` loop**: Add `'a'` back to the set.
  - `set = {'b', 'c', 'a'}`

- **Update**: Calculate `maxLen = max(3, 3 - 1 + 1) = 3`.
  - `maxLen = 3`

---

### Iteration 5: `right = 4`, character = `'b'`

- **Check**: `'b'` is already in the set. Enter the `while` loop.
- **Action**: Remove `'b'` (character at `left`) from the set and increment `left`:
  - `set = {'c', 'a'}`, `left = 2`

- **Exit `while` loop**: Add `'b'` back to the set.
  - `set = {'c', 'a', 'b'}`

- **Update**: Calculate `maxLen = max(3, 4 - 2 + 1) = 3`.
  - `maxLen = 3`

---

### Iteration 6: `right = 5`, character = `'c'`

- **Check**: `'c'` is already in the set. Enter the `while` loop.
- **Action**: Remove `'c'` (character at `left`) from the set and increment `left`:
  - `set = {'a', 'b'}`, `left = 3`

- **Exit `while` loop**: Add `'c'` back to the set.
  - `set = {'a', 'b', 'c'}`

- **Update**: Calculate `maxLen = max(3, 5 - 3 + 1) = 3`.
  - `maxLen = 3`

---

### Iteration 7: `right = 6`, character = `'b'`

- **Check**: `'b'` is already in the set. Enter the `while` loop.
- **Action**: Remove characters from the set and increment `left` until `'b'` is removed:
  - Remove `'a'`: `set = {'b', 'c'}`, `left = 4`
  - Remove `'b'`: `set = {'c'}`, `left = 5`

- **Exit `while` loop**: Add `'b'` back to the set.
  - `set = {'c', 'b'}`

- **Update**: Calculate `maxLen = max(3, 6 - 5 + 1) = 3`.
  - `maxLen = 3`

---

### Iteration 8: `right = 7`, character = `'b'`

- **Check**: `'b'` is already in the set. Enter the `while` loop.
- **Action**: Remove characters from the set and increment `left` until `'b'` is removed:
  - Remove `'c'`: `set = {'b'}`, `left = 6`
  - Remove `'b'`: `set = {}`, `left = 7`

- **Exit `while` loop**: Add `'b'` back to the set.
  - `set = {'b'}`

- **Update**: Calculate `maxLen = max(3, 7 - 7 + 1) = 3`.
  - `maxLen = 3`

---

### Final State:
- **The longest substring without repeating characters is `"abc"`, with length `3`.**
- **Result**: `return 3`.

---

This detailed dry run illustrates how each line of the code affects the set of characters, the sliding window, and the maximum length found. Each iteration either expands the window or shrinks it if a duplicate character is found, ensuring that the longest substring without repeating characters is identified.

Here’s a textual visualization of how the sliding window technique works step by step for the string `"abcabcbb"`:

### String: `"abcabcbb"`
We use two pointers, `left` and `right`, to track the current window, and a set to keep track of unique characters. `maxLen` stores the length of the longest substring without repeating characters.

### Initial State:
- `left = 0`
- `right = 0`
- `maxLen = 0`
- `set = {}` (empty set)

---

### Step 1: `right = 0`, character = `'a'`
- **Check**: `'a'` is not in the set.
- **Action**: Add `'a'` to the set → `set = {'a'}`.
- **Update**: `maxLen = max(0, 0 - 0 + 1) = 1`.

```
Window: [a] (from index 0 to 0)
Set: {'a'}
maxLen: 1
```

---

### Step 2: `right = 1`, character = `'b'`
- **Check**: `'b'` is not in the set.
- **Action**: Add `'b'` to the set → `set = {'a', 'b'}`.
- **Update**: `maxLen = max(1, 1 - 0 + 1) = 2`.

```
Window: [a, b] (from index 0 to 1)
Set: {'a', 'b'}
maxLen: 2
```

---

### Step 3: `right = 2`, character = `'c'`
- **Check**: `'c'` is not in the set.
- **Action**: Add `'c'` to the set → `set = {'a', 'b', 'c'}`.
- **Update**: `maxLen = max(2, 2 - 0 + 1) = 3`.

```
Window: [a, b, c] (from index 0 to 2)
Set: {'a', 'b', 'c'}
maxLen: 3
```

---

### Step 4: `right = 3`, character = `'a'`
- **Check**: `'a'` is already in the set.
- **Action**: Remove `'a'` (leftmost) from the set, move `left` to `1` → `set = {'b', 'c'}`.
- **Add**: Insert `'a'` → `set = {'b', 'c', 'a'}`.
- **Update**: `maxLen = max(3, 3 - 1 + 1) = 3`.

```
Window: [b, c, a] (from index 1 to 3)
Set: {'b', 'c', 'a'}
maxLen: 3
```

---

### Step 5: `right = 4`, character = `'b'`
- **Check**: `'b'` is already in the set.
- **Action**: Remove `'b'` (leftmost) from the set, move `left` to `2` → `set = {'c', 'a'}`.
- **Add**: Insert `'b'` → `set = {'c', 'a', 'b'}`.
- **Update**: `maxLen = max(3, 4 - 2 + 1) = 3`.

```
Window: [c, a, b] (from index 2 to 4)
Set: {'c', 'a', 'b'}
maxLen: 3
```

---

### Step 6: `right = 5`, character = `'c'`
- **Check**: `'c'` is already in the set.
- **Action**: Remove `'c'` (leftmost) from the set, move `left` to `3` → `set = {'a', 'b'}`.
- **Add**: Insert `'c'` → `set = {'a', 'b', 'c'}`.
- **Update**: `maxLen = max(3, 5 - 3 + 1) = 3`.

```
Window: [a, b, c] (from index 3 to 5)
Set: {'a', 'b', 'c'}
maxLen: 3
```

---

### Step 7: `right = 6`, character = `'b'`
- **Check**: `'b'` is already in the set.
- **Action**: Remove `'a'`, move `left` to `4`, then remove `'b'`, move `left` to `5` → `set = {'c'}`.
- **Add**: Insert `'b'` → `set = {'c', 'b'}`.
- **Update**: `maxLen = max(3, 6 - 5 + 1) = 3`.

```
Window: [c, b] (from index 5 to 6)
Set: {'c', 'b'}
maxLen: 3
```

---

### Step 8: `right = 7`, character = `'b'`
- **Check**: `'b'` is already in the set.
- **Action**: Remove `'c'`, move `left` to `6`, then remove `'b'`, move `left` to `7` → `set = {}`.
- **Add**: Insert `'b'` → `set = {'b'}`.
- **Update**: `maxLen = max(3, 7 - 7 + 1) = 3`.

```
Window: [b] (from index 7 to 7)
Set: {'b'}
maxLen: 3
```

---

### Final Result:
- The longest substring without repeating characters is `"abc"`, with length `3`.

---

This visualization represents how the sliding window expands and contracts based on duplicates, and how the maximum length (`maxLen`) is updated. The key part is removing characters from the left when duplicates are found.
Let me explain in simpler terms, step-by-step, using a real-life analogy.

### What is a **Set**?
- A **set** in programming is like a **collection of unique items**.
- Imagine you have a **box** where you keep some letters, like `'a'`, `'b'`, and `'c'`. This box is your **set**.

### What is **`set.find('x')`**?
- When you ask the set, "**Is the letter `'x'` in the box?**", this is what `set.find('x')` does.
- It **searches** the box to see if `'x'` is there.

### What is **`set.end()`**?
- **`set.end()`** is like a **special marker** that represents the **end** of the box.
- When you look for a letter, if you reach this special marker, it means you **didn’t find** the letter in the box.

### Example:

Let’s say your set (box) contains these letters: `'a'`, `'b'`, `'c'`.

1. **Searching for `'b'` in the set:**

   - You ask the set: "**Is `'b'` in the box?**"
   - The set looks and finds the letter `'b'`. So, it **does not** return the special marker `set.end()`.
   - This means **`'b'` is found** in the set.
   
   ```cpp
   set.find('b') != set.end();  // True, because 'b' is in the set
   ```

2. **Searching for `'d'` in the set:**

   - You ask the set: "**Is `'d'` in the box?**"
   - The set looks through `'a'`, `'b'`, `'c'`, but `'d'` is **not** in the box.
   - Since it didn’t find `'d'`, the set gives you the special marker `set.end()`, meaning it reached the end and didn’t find `'d'`.
   - This means **`'d'` is not found** in the set.
   
   ```cpp
   set.find('d') != set.end();  // False, because 'd' is NOT in the set
   ```

### `while (set.find(s[right]) != set.end())`
In your code:

- The loop `while (set.find(s[right]) != set.end())` means:
  - **While the character `s[right]` already exists in the set**, keep removing characters from the left of the window.
  
  This loop will continue until the duplicate character is no longer found in the set. The idea is to ensure that your sliding window has **only unique characters** at any point.

### In Simple Terms:
- **`set.find()`**: Checks if an item exists in the set (like looking inside a box for a letter).
- **`set.end()`**: A special marker that tells you when you’ve **reached the end** of the set (meaning the item isn’t in the set).

Does this help you understand the concept better?
