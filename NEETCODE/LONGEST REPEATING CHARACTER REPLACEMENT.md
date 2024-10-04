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


