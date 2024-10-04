424. Longest Repeating Character Replacement
Medium
Topics
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

```
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.size();
        for(char c = 'A'; c <= 'Z'; c++)
        {
            int i = 0, j = 0, replaced = 0;
            while(j < n)
            {
                if(s[j] == c)
                    j++;
                else if(replaced < k)
                    j++, replaced++;
                else if(s[i] == c)
                    i++;
                else
                    i++, replaced--;
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};
```
 Got it! I'll explain this visually and break it down with as much detail as possible, using diagrams and simple steps. Let's go step by step to understand how the sliding window works and how the code runs.

### Problem Summary:
We are given a string `s` and a number `k`. Our goal is to find the longest substring where we can replace at most `k` characters to make the substring consist of all identical characters.

The code is trying to achieve this by checking each character (`'A'` to `'Z'`) and seeing how long of a substring can be formed where all characters become the same, allowing up to `k` changes.

### Example:  
Let’s use `s = "AABABBA"` and `k = 1` as the example.

### Step-by-Step Breakdown:

1. **Outer loop: for each character from 'A' to 'Z'**  
   We will go character by character to check what is the longest possible substring where we can replace up to `k` characters to make the substring filled with that character.

   So first, let’s start with `'A'`.

---

### Visual Representation for Character `'A'`:
We will use two pointers `i` and `j` to define a window that represents the current substring. We also count how many characters we’ve replaced using the variable `replaced`.

#### Initialization:  
- Set `i = 0`, `j = 0`, and `replaced = 0`.
- **Goal**: Find the longest substring where we can turn all characters into `'A'` by replacing at most `1` character.

#### String:  
```
  s = A A B A B B A
      0 1 2 3 4 5 6  (index positions)
```

### 1. **Start expanding the window**:
- We will move the `j` pointer (right pointer) to expand the window and see if we can turn the substring into a string of `'A'` characters.

#### Step-by-Step Movement of `j` (right pointer):
- **At `j = 0`:**
  - `s[0] = 'A'`, so no need to replace. Just expand the window by moving `j` to `1`.
  
  Current window: `[A]` (1 character)  
  Replaced = 0 (no replacements)

---

- **At `j = 1`:**
  - `s[1] = 'A'`, again no need to replace. Expand the window by moving `j` to `2`.

  Current window: `[A A]` (2 characters)  
  Replaced = 0

---

- **At `j = 2`:**
  - `s[2] = 'B'`. This does not match `'A'`.  
  We can replace this character since `replaced = 0` and we are allowed 1 replacement. So, replace `'B'` with `'A'` and move `j` to `3`.
  
  Current window: `[A A B]` → After replacement: `[A A A]`  
  Replaced = 1 (we used 1 replacement)

---

- **At `j = 3`:**
  - `s[3] = 'A'`, no need to replace, so move `j` to `4`.

  Current window: `[A A A A]`  
  Replaced = 1 (still only 1 replacement used)

---

- **At `j = 4`:**
  - `s[4] = 'B'`, this does not match `'A'`.  
  But we already used `1` replacement, which is the limit (`k = 1`).  
  Now, we can't expand the window unless we reduce the number of replacements. So, we move `i` (left pointer) to shrink the window.
  
  Now, we look at `s[i]` (which is `'A'`). Since `s[i] = 'A'`, we move `i` to `1` and keep `replaced` the same.

  New window: `[A A A B]`  
  Replaced = 1 (still 1 replacement used)

---

- **At `j = 5`:**
  - `s[5] = 'B'`, this is another `'B'` and we can't replace it.  
  Now, move `i` again to reduce the window.

  When `i = 2`, the window becomes `[A A B]` and `replaced = 1`.

---

### Window Adjustment:
We continue moving `i` and adjusting the window until we maximize the longest substring where at most 1 replacement can turn it into all `'A'`.

- The final longest substring we get for `'A'` is `"A A A A"` with a length of **4**.

---
Sure! Let's break down the code **line-by-line** and run a dry run at each step, followed by an example to see how everything works.

### Code:

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.size();  // Step 1
        for(char c = 'A'; c <= 'Z'; c++) {  // Step 2
            int i = 0, j = 0, replaced = 0;  // Step 3
            while(j < n) {  // Step 4
                if(s[j] == c) j++;  // Step 5
                else if(replaced < k) j++, replaced++;  // Step 6
                else if(s[i] == c) i++;  // Step 7
                else i++, replaced--;  // Step 8
                ans = max(ans, j - i);  // Step 9
            }
        }
        return ans;  // Step 10
    }
};
```

Now, let's explain the code **line-by-line**.

---

### Line-by-Line Breakdown

---

### **Step 1**:
```cpp
int ans = 0, n = s.size();
```
- **Explanation**:  
  - `ans`: This variable will hold the maximum length of the longest valid substring found so far.
  - `n`: This stores the length of the input string `s`.
  
  **Initial values**: `ans = 0`, `n = length of the string s`.
  
  Example:  
  For the string `s = "AABABBA"`, we have `n = 7`.

---

### **Step 2**:
```cpp
for(char c = 'A'; c <= 'Z'; c++) {
```
- **Explanation**:  
  This `for` loop will go through each character from `'A'` to `'Z'` to check how long the string can be if we try to make a substring filled with a specific character (`c`).

  **Iteration starts**:  
  - First, `c = 'A'`, meaning we want to check how long the string can be if we replace some characters to make a substring full of `'A'`.

---

### **Step 3**:
```cpp
int i = 0, j = 0, replaced = 0;
```
- **Explanation**:  
  We initialize three variables:
  - `i`: Marks the start of the current window (left boundary).
  - `j`: Marks the end of the current window (right boundary).
  - `replaced`: Keeps track of how many characters we've replaced so far to try and make the substring full of the character `c`.

  **Initial values**:  
  - `i = 0`, `j = 0`, `replaced = 0`.

---

### **Step 4**:
```cpp
while(j < n) {
```
- **Explanation**:  
  This `while` loop expands the window by moving `j` to the right and processes each character in the string `s`. It runs until `j` reaches the end of the string (`j < n`).

---

### **Step 5**:
```cpp
if(s[j] == c) j++;
```
- **Explanation**:  
  - If the character at position `j` in the string `s` matches the character `c` that we're currently focusing on, we simply move `j` one step to the right (expand the window).
  
  Example:  
  - If `c = 'A'` and `s[j] = 'A'`, move `j` right because no replacement is needed.

---

### **Step 6**:
```cpp
else if(replaced < k) j++, replaced++;
```
- **Explanation**:  
  - If `s[j]` does **not** match `c` (i.e., the current character of interest), and we still have replacements available (i.e., `replaced < k`), we "replace" the character at position `j` with `c` (virtually). We then:
    - Move `j` one step to the right (expand the window).
    - Increment `replaced` to count the replacement.
  
  Example:  
  - If `s[j] = 'B'` and we're focusing on `c = 'A'`, we replace `'B'` with `'A'` (virtually) and increase `replaced`.

---

### **Step 7**:
```cpp
else if(s[i] == c) i++;
```
- **Explanation**:  
  - If we can no longer replace characters (`replaced == k`), we need to **shrink** the window from the left side to try and make room for more replacements.
  - If the character at `i` matches `c`, just move `i` one step to the right because no replacement was involved in that position.
  
  Example:  
  - If `s[i] = 'A'` and `c = 'A'`, move `i` right to shrink the window.

---

### **Step 8**:
```cpp
else i++, replaced--;
```
- **Explanation**:  
  - If `s[i]` doesn't match `c`, that means this character was replaced before, so when we move `i`, we also need to decrease the `replaced` count by 1 (because we're removing a replacement from the window).

---

### **Step 9**:
```cpp
ans = max(ans, j - i);
```
- **Explanation**:  
  - Calculate the length of the current window (`j - i`) and update `ans` to the maximum of its current value and the length of this window.
  - This ensures that `ans` always holds the length of the longest valid substring found so far.

---

### **Step 10**:
```cpp
return ans;
```
- **Explanation**:  
  - After checking for all characters from `'A'` to `'Z'`, return `ans`, which holds the length of the longest valid substring that can be made with at most `k` replacements.

---

---

### Dry Run Example

#### Input:
```cpp
s = "AABABBA", k = 1
```

#### Iteration 1 (`c = 'A'`):
- We're looking for the longest substring that can be turned into all `'A'`s with at most `1` replacement.

---

1. **Window [0, 0]**:
   - `s[0] = 'A'`, matches `c = 'A'`.
   - Move `j = 1`.  
   Window: `"A"` (`replaced = 0`), length `1`, `ans = 1`.

---

2. **Window [0, 1]**:
   - `s[1] = 'A'`, matches `c = 'A'`.
   - Move `j = 2`.  
   Window: `"AA"` (`replaced = 0`), length `2`, `ans = 2`.

---

3. **Window [0, 2]**:
   - `s[2] = 'B'`, doesn’t match `c = 'A'`, replace it (`replaced = 1`).
   - Move `j = 3`.  
   Window: `"AAB"` → `"AAA"` (`replaced = 1`), length `3`, `ans = 3`.

---

4. **Window [0, 3]**:
   - `s[3] = 'A'`, matches `c = 'A'`.
   - Move `j = 4`.  
   Window: `"AABA"` → `"AAAA"` (`replaced = 1`), length `4`, `ans = 4`.

---

5. **Window [0, 4]**:
   - `s[4] = 'B'`, but we can't replace anymore (`replaced = 1`), so shrink the window by moving `i = 1`.
   
   Window shrinks to `"ABA"`, `replaced = 1`, `i = 1`.

---

6. **Window [1, 4]**:
   - Continue shrinking window.  
   After moving `i`, we get `i = 3`, `replaced = 0`, and `j = 4`.

---

Continue similarly until the end of the string.

---

Finally, for `'A'`, the longest valid substring is `"AABA"`, which is length `4`.

---

Similarly, you'll check for other characters like `'B'`, but `'A'` gives the longest valid result in this case. Therefore, the final output is `4`.

---

Does this explanation help clarify the process?


