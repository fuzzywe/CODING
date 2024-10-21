78. Subsets
Solved
Medium
Topics
Companies
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

```cpp

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        int n = nums.size();
        int subsetsCount = 1 << n; // 2^n subsets

        for (int i = 0; i < subsetsCount; ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            sets.push_back(subset);
        }
        return sets;
    }
};
```

This code generates all the possible subsets of a given set `nums` using a mathematical concept called **bit manipulation**. Let's break it down in a mathematical way, especially focusing on how binary numbers help generate the subsets.

### Key Points:
1. **Number of Subsets**:  
   For a set of size \( n \), there are \( 2^n \) possible subsets. This is because each element of the set can either be included or excluded from a subset, and there are \( n \) elements, leading to \( 2^n \) combinations.

2. **Binary Representation and Subsets**:  
   Each subset can be represented as a binary number of length \( n \). Each bit in this binary number corresponds to an element in the set. If the bit is 1, the element is included in the subset; if the bit is 0, the element is excluded.

#### Example:
For the set `nums = [a, b, c]`, we have \( n = 3 \). The binary numbers from 0 to \( 2^n - 1 \) (which is \( 2^3 - 1 = 7 \)) are:
- 000: {}
- 001: {c}
- 010: {b}
- 011: {b, c}
- 100: {a}
- 101: {a, c}
- 110: {a, b}
- 111: {a, b, c}

Thus, each binary number represents a unique subset.

---

### Line-by-Line Mathematical Explanation:

```cpp
int subsetsCount = 1 << n;  // This means 2^n subsets
```
- \( 1 \ll n \) is the bitwise left shift operation, equivalent to \( 2^n \), meaning there are \( 2^n \) possible subsets.

```cpp
for (int i = 0; i < subsetsCount; ++i) { 
    vector<int> subset;
```
- Here, `i` ranges from 0 to \( 2^n - 1 \). Each value of `i` represents a binary number of length \( n \), corresponding to a specific subset.

```cpp
for (int j = 0; j < n; ++j) {
    if (i & (1 << j)) {
        subset.push_back(nums[j]);
    }
}
```
- This inner loop iterates over each element of the set `nums` (with size \( n \)). For each element at position `j`:
    - **Mathematical Interpretation**:  
      - `1 << j` is equivalent to \( 2^j \), which has the binary form where only the \( j \)-th bit is set to 1. For example:
        - \( 1 << 0 = 0001 \) (binary), or \( 2^0 = 1 \)
        - \( 1 << 1 = 0010 \) (binary), or \( 2^1 = 2 \)
        - \( 1 << 2 = 0100 \) (binary), or \( 2^2 = 4 \)
    - `i & (1 << j)` checks if the \( j \)-th bit of `i` is set to 1. If it is, the element `nums[j]` is included in the subset.
      - **Mathematical Check**:  
        - If `i & (1 << j)` is true, the \( j \)-th element is part of the subset because the corresponding bit is 1.

---

### Example Dry Run (for `nums = [a, b, c]`):
1. **n = 3**  
   Number of subsets = \( 2^3 = 8 \)
   
2. **Iteration i = 0 (000 in binary)**:  
   - No bits are set, so the subset is `{}`.

3. **Iteration i = 1 (001 in binary)**:  
   - The 0-th bit is set (corresponds to `nums[0] = a`), so the subset is `{a}`.

4. **Iteration i = 2 (010 in binary)**:  
   - The 1st bit is set (corresponds to `nums[1] = b`), so the subset is `{b}`.

5. **Iteration i = 3 (011 in binary)**:  
   - The 0-th and 1st bits are set (corresponds to `nums[0] = a` and `nums[1] = b`), so the subset is `{a, b}`.

6. **Iteration i = 7 (111 in binary)**:  
   - All bits are set (corresponds to `nums[0] = a`, `nums[1] = b`, `nums[2] = c`), so the subset is `{a, b, c}`.

---

### Summary:
- The code generates all possible subsets of `nums` by iterating over the binary numbers from 0 to \( 2^n - 1 \).
- Each binary number represents a specific subset by indicating which elements of `nums` should be included.
- This approach leverages the fact that for any set of size \( n \), the total number of subsets is \( 2^n \), and the binary representation of numbers from 0 to \( 2^n - 1 \) can be used to determine inclusion/exclusion of elements in the subset.
