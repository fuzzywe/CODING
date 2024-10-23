567. Permutation in String
Solved
Medium
Topics
Companies
Hint
Given two strings s1 and s2, return true if s2 contains a 
permutation
 of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

```cpp
class Solution {
public:
    static inline array<int, 26> count(string& s, int l, int r){
        array<int, 26> freq={0};
        for(int i=l; i<=r; i++)
            freq[s[i]-'a']++;
        return freq;
    }

    static bool checkInclusion(string& s1, string& s2) {
        const int n1=s1.size(), n2=s2.size();
        if (n2<n1) return 0;
        auto freq1=count(s1, 0, n1-1);
        auto freq2=count(s2, 0, n1-1);
        if (freq1==freq2) return 1;
        for(int l=1, r=n1; r<n2; r++, l++){
            freq2[s2[l-1]-'a']--;
            freq2[s2[r]-'a']++;
            if (freq2== freq1) return 1;
        }
        return 0;
    }
};
```

The code implements a sliding window approach to solve the "Permutation in String" problem. The goal is to check if one string (`s1`) is a permutation of a substring of another string (`s2`). The solution is efficient, using frequency arrays and a sliding window technique to minimize redundant computations.

### Code Breakdown

Let's go through the code line by line and explain the logic with an example.

#### Function `count`

```cpp
static inline array<int, 26> count(string& s, int l, int r){
    array<int, 26> freq={0};
    for(int i=l; i<=r; i++)
        freq[s[i]-'a']++;
    return freq;
}
```

- **Purpose**: This function returns an array representing the frequency of each character (a-z) in the substring `s[l...r]`.
- **Parameters**:
  - `s`: The string we are analyzing.
  - `l`: The starting index of the substring.
  - `r`: The ending index of the substring.
- **How it works**:
  1. We create a `freq` array of size 26 (since there are 26 lowercase letters), initialized to `0`.
  2. The loop goes through each character in the substring `s[l...r]` and increments the corresponding frequency in the `freq` array based on the character's ASCII value (`s[i] - 'a'` gives the index for that character).
  3. Finally, it returns the frequency array.

**Example**:
- If `s = "abcabc"` and we call `count(s, 0, 2)`, we are analyzing the substring `"abc"`. 
  - `freq['a' - 'a']++` increases the frequency of 'a' to 1.
  - `freq['b' - 'a']++` increases the frequency of 'b' to 1.
  - `freq['c' - 'a']++` increases the frequency of 'c' to 1.
  - The resulting frequency array for the substring `"abc"` will be:
    ```
    freq = [1, 1, 1, 0, 0, ..., 0] (1 for 'a', 1 for 'b', 1 for 'c')
    ```

---

#### Function `checkInclusion`

```cpp
static bool checkInclusion(string& s1, string& s2) {
    const int n1=s1.size(), n2=s2.size();
```

- **Purpose**: This is the main function that checks if any permutation of `s1` is a substring of `s2`.
- **Variables**:
  - `n1`: The length of string `s1`.
  - `n2`: The length of string `s2`.

---

```cpp
if (n2<n1) return 0;
```

- **Edge Case Check**: If `s2` is shorter than `s1`, it's impossible for any substring of `s2` to be a permutation of `s1`. So, return `0`.

---

```cpp
auto freq1=count(s1, 0, n1-1);
auto freq2=count(s2, 0, n1-1);
```

- **Initial Frequency Arrays**:
  - `freq1`: The frequency array for the string `s1`.
  - `freq2`: The frequency array for the first `n1` characters of `s2` (i.e., the first window of size `n1` in `s2`).

**Example**:
- Let `s1 = "abc"` and `s2 = "eidbacooo"`. 
  - `freq1` for `"abc"` would be `[1, 1, 1, 0, ..., 0]`.
  - `freq2` for the first window `"eid"` in `s2` would be `[0, 0, 1, ..., 0]` (because 'e', 'i', and 'd' are present in this window).

---

```cpp
if (freq1==freq2) return 1;
```

- **Initial Check**: If the frequency arrays for `s1` and the first window in `s2` are identical, that means the first window of `s2` is a permutation of `s1`. In that case, return `1` (true).

---

```cpp
for(int l=1, r=n1; r<n2; r++, l++){
    freq2[s2[l-1]-'a']--;
    freq2[s2[r]-'a']++;
    if (freq2== freq1) return 1;
}
```

- **Sliding Window Logic**:
  - We start sliding the window from the second position in `s2` (i.e., from `l=1` and `r=n1`, which corresponds to the second character of `s2`).
  - **Update the Frequency Array**:
    - Decrease the frequency of the character that is leaving the window (`s2[l-1]`).
    - Increase the frequency of the character that is entering the window (`s2[r]`).
  - After each update, compare `freq2` with `freq1`. If they match, it means the current window in `s2` is a permutation of `s1`, so return `1`.

**Example** (continued):
- For `s2 = "eidbacooo"`, after sliding to the next window `"idb"`:
  - `freq2` will be updated by removing 'e' and adding 'b', resulting in the frequency array:
    ```
    freq2 = [1, 1, 1, 0, ..., 0] (which matches freq1 for "abc")
    ```
  - Since `freq1 == freq2`, return `1` (indicating that a permutation of `s1` is found in `s2`).

---

```cpp
return 0;
```

- **Return 0 (False)**: If no matching frequency array is found after sliding through all windows of `s2`, return `0`, indicating that no permutation of `s1` exists in `s2`.

---

### Dry Run Example

#### Input:
- `s1 = "abc"`
- `s2 = "eidbacooo"`

#### Step-by-Step Dry Run:

1. **Initialization**:
   - `n1 = 3`, `n2 = 9`.
   - `freq1 = [1, 1, 1, 0, ..., 0]` for `"abc"`.
   - `freq2 = [1, 1, 0, 0, ..., 0]` for the first window `"eid"`.

2. **First Window Check**:
   - `freq1 != freq2` (The first window `"eid"` is not a permutation of `"abc"`).

3. **Sliding the Window**:
   - Slide the window to the next substring `"idb"`.
   - Update `freq2`: Remove 'e', add 'b'.
     - New `freq2 = [1, 1, 1, 0, ..., 0]` (which matches `freq1`).

4. **Matching Found**:
   - Since `freq1 == freq2`, return `1`.

Thus, the function finds that the substring `"idb"` in `s2` is a permutation of `s1` and returns `1`.

### Time Complexity

- The function computes the frequency of the first window in O(n1) and then slides the window across `s2` in O(n2), with each update operation being O(1). So, the overall time complexity is **O(n1 + n2)**.

### Conclusion

This sliding window approach efficiently checks if any permutation of `s1` exists in `s2` by maintaining frequency counts of characters in each window of `s2`. The solution avoids redundant recalculations by only adjusting the frequency array for the entering and leaving characters as the window slides.
