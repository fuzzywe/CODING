Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

Let's dry run the given code step by step to understand its working in detail. This code finds the **next greater element** for each element in a circular array `a`.

### Code Breakdown:

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size(); // Step 1
        vector<int> v(n, -1); // Step 2

        stack<int> st; // Step 3
        for (int i = 2 * n - 1; i >= 0; i--) { // Step 4
            while (!st.empty() && (a[i % n] >= st.top())) { // Step 5
                st.pop(); // Step 6
            }
            if (!st.empty() && (i < n)) { // Step 7
                v[i] = st.top(); // Step 8
            }
            st.push(a[i % n]); // Step 9
        }
        return v; // Step 10
    }
};
```

### Dry Run Example:

#### Input:
- `a = [1, 2, 1]`

#### Step-by-step Dry Run:

1. **Step 1**: `int n = a.size();`
   - `n = 3`
   - This stores the size of the array `a`.

2. **Step 2**: `vector<int> v(n, -1);`
   - Initializes a result vector `v` of size `n` filled with `-1`.
   - Initial state of `v = [-1, -1, -1]`.

3. **Step 3**: `stack<int> st;`
   - Initializes an empty stack `st` to help find the next greater element.

4. **Step 4**: The loop runs from `i = 2 * n - 1` down to `0`. So, `i` starts at `5` and runs until `0` (for a total of `6` iterations).

#### Iteration 1: `i = 5`
- **Step 5**: `a[i % n] = a[5 % 3] = a[2] = 1`
- **Step 5**: The stack is empty, so the `while` loop is skipped.
- **Step 7**: `i >= n` (5 ≥ 3), so the `if` condition is skipped.
- **Step 9**: Push `a[2] = 1` onto the stack.
  - Stack after this: `st = [1]`.

#### Iteration 2: `i = 4`
- **Step 5**: `a[i % n] = a[4 % 3] = a[1] = 2`
- **Step 5**: `a[1] = 2` is greater than the top of the stack (`st.top() = 1`), so we pop `1` from the stack.
  - Stack after popping: `st = []`.
- **Step 5**: The stack is empty now, so the `while` loop ends.
- **Step 7**: `i >= n` (4 ≥ 3), so the `if` condition is skipped.
- **Step 9**: Push `a[1] = 2` onto the stack.
  - Stack after this: `st = [2]`.

#### Iteration 3: `i = 3`
- **Step 5**: `a[i % n] = a[3 % 3] = a[0] = 1`
- **Step 5**: `a[0] = 1` is smaller than `st.top() = 2`, so we skip the `while` loop.
- **Step 7**: `i >= n` (3 ≥ 3), so the `if` condition is skipped.
- **Step 9**: Push `a[0] = 1` onto the stack.
  - Stack after this: `st = [2, 1]`.

#### Iteration 4: `i = 2`
- **Step 5**: `a[i % n] = a[2 % 3] = a[2] = 1`
- **Step 5**: `a[2] = 1` is equal to `st.top() = 1`, so we pop `1` from the stack.
  - Stack after popping: `st = [2]`.
- **Step 5**: Now, `a[2] = 1` is smaller than `st.top() = 2`, so the `while` loop ends.
- **Step 7**: Since `i < n` (2 < 3), we set `v[2] = st.top() = 2`.
  - After this, `v = [-1, -1, 2]`.
- **Step 9**: Push `a[2] = 1` onto the stack.
  - Stack after this: `st = [2, 1]`.

#### Iteration 5: `i = 1`
- **Step 5**: `a[i % n] = a[1 % 3] = a[1] = 2`
- **Step 5**: `a[1] = 2` is equal to `st.top() = 1`, so we pop `1` from the stack.
  - Stack after popping: `st = [2]`.
- **Step 5**: `a[1] = 2` is equal to `st.top() = 2`, so we pop `2` from the stack.
  - Stack after popping: `st = []`.
- **Step 5**: The stack is now empty, so the `while` loop ends.
- **Step 7**: Since `i < n` (1 < 3), `v[1]` remains `-1` (no greater element).
  - After this, `v = [-1, -1, 2]`.
- **Step 9**: Push `a[1] = 2` onto the stack.
  - Stack after this: `st = [2]`.

#### Iteration 6: `i = 0`
- **Step 5**: `a[i % n] = a[0 % 3] = a[0] = 1`
- **Step 5**: `a[0] = 1` is smaller than `st.top() = 2`, so the `while` loop ends.
- **Step 7**: Since `i < n` (0 < 3), we set `v[0] = st.top() = 2`.
  - After this, `v = [2, -1, 2]`.
- **Step 9**: Push `a[0] = 1` onto the stack.
  - Stack after this: `st = [2, 1]`.

5. **Step 10**: Return the result vector `v`.

### Final Output:
```cpp
[2, -1, 2]
```

### Explanation of Output:
- For `a[0] = 1`, the next greater element in a circular manner is `2`.
- For `a[1] = 2`, there is no next greater element.
- For `a[2] = 1`, the next greater element in a circular manner is `2`.
- Complexity
Time complexity: O(N)
Space complexity: O(N)
