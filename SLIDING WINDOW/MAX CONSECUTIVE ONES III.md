Basically the same problem as 340. Longest Substring with At Most K Distinct Characters (premium).

1004. Max Consecutive Ones III
1005. 
https://leetcode.com/problems/max-consecutive-ones-iii/description/

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                k--;
            }
            if(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            j++;
        }
        return j-i;
    }
};

```

Let's break down the provided C++ code step by step and perform a dry run to explain the algorithm visually. The code implements a solution to the problem of finding the length of the longest contiguous subarray containing at most `k` zeros in a binary array (an array consisting of 0s and 1s).

### Code Breakdown

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0; // Initialize two pointers, i (start of the window) and j (end of the window)
        while(j<nums.size()){ // Iterate while j is less than the size of the array
            if(nums[j]==0){ // If the current element is 0
                k--; // Decrease k (since we have encountered a zero)
            }
            if(k<0){ // If k becomes negative, it means we have more than k zeros
                if(nums[i]==0){ // If the element at the start of the window is 0
                    k++; // Increase k (as we are going to move the start of the window forward)
                }
                i++; // Move the start of the window forward
            }
            j++; // Move the end of the window forward
        }
        return j-i; // Return the length of the longest subarray
    }
};
```

### Detailed Explanation

1. **Initialization:**
   - `int i = 0, j = 0;`: 
     - Two pointers `i` and `j` are initialized to represent the starting and ending indices of the current window (subarray) being considered.

2. **Main Loop:**
   - `while(j < nums.size()) {`: 
     - This loop runs until the end of the array is reached.

3. **Check Current Element:**
   - `if(nums[j] == 0) { k--; }`: 
     - If the current element (`nums[j]`) is zero, we decrement `k` because we are using one of our allowed zeros.

4. **Check Zero Count:**
   - `if(k < 0) {`: 
     - If `k` is less than 0, it means we have encountered more than `k` zeros in the current window.

5. **Adjust Window:**
   - `if(nums[i] == 0) { k++; }`: 
     - If the element at the start of the window (`nums[i]`) is zero, we increment `k` because we are going to exclude this zero from the window.

   - `i++;`: 
     - Move the start of the window forward by incrementing `i`.

6. **Advance End Pointer:**
   - `j++;`: 
     - Move the end pointer forward by incrementing `j`.

7. **Return Result:**
   - `return j - i;`: 
     - The length of the longest subarray is calculated as the difference between `j` and `i`.

### Dry Run Example

Let’s perform a dry run with an example input:
- **Input:** `nums = [1, 1, 0, 0, 1, 1]`, `k = 1`

**Step-by-step Execution:**

| Step | i | j | nums[j] | k | Explanation |
|------|---|---|---------|---|-------------|
| 1    | 0 | 0 | 1       | 1 | Initialize i and j. j points to 1. k remains 1. |
| 2    | 0 | 1 | 1       | 1 | Move j to next element (1). k remains 1. |
| 3    | 0 | 2 | 0       | 1 | Move j to next element (0). Decrease k to 0. |
| 4    | 0 | 3 | 0       | 0 | Move j to next element (0). Decrease k to -1 (too many zeros). |
| 5    | 0 | 4 | 1       | 0 | Check k, it's negative. Increment i because nums[i] is 1. |
| 6    | 1 | 4 | 1       | 0 | Increment i (now points to second 1). |
| 7    | 1 | 5 | 1       | 0 | Move j to next element (1). k remains 0. |
| 8    | 1 | 6 |         | 0 | End of array reached. Return j-i = 6 - 1 = 5. |

### Visual Representation

Let's visualize the window as it slides over the array:

```
Initial array:   [1, 1, 0, 0, 1, 1]
                   ↑
                   i (start of the window)

1. First Move:
    [1, 1, 0, 0, 1, 1]
                      ↑
                      j (end of the window)

2. Second Move:
    [1, 1, 0, 0, 1, 1]
                       ↑
                       j

3. Third Move:
    [1, 1, 0, 0, 1, 1]
                         ↑
                         j

4. Fourth Move (exceeded k):
    [1, 1, 0, 0, 1, 1]
                   ↑   ↑
                   i   j

Continue adjusting i and j until the end of the array:
Final window: [1, 1, 0, 0, 1, 1]
Length of longest valid window = 5.
```

### Conclusion

The algorithm efficiently finds the longest contiguous subarray with at most `k` zeros using the two-pointer technique. This method maintains a time complexity of **O(n)**, where `n` is the length of the array, ensuring that it processes each element in the array only once.
