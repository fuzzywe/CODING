442. Find All Duplicates in an Array
Solved
Medium
Topics
Companies
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 https://leetcode.com/problems/find-all-duplicates-in-an-array/description/

 https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
     
    int n = nums.size();
    vector<int> result;
    vector<int> freq(n + 1, 0); // Create frequency array initialized to 0
    
    // Count frequencies of elements
    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }
    
    // Find elements with frequency greater than 1
    for (int i = 0; i <= n; i++) {
        if (freq[i] > 1) {
            result.push_back(i);
        }
    }
    
    return result;
}


    
};

```

OPITMAL 

```cpp

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Get the absolute value of the current element
            int index = abs(nums[i]) - 1; 
            
            // If the value at the corresponding index is negative, it's a duplicate
            if (nums[index] < 0) {
                result.push_back(abs(nums[i]));
            } else {
                // Mark the value at the index as visited by negating it
                nums[index] = -nums[index];
            }
        }
        
        return result;
    }
};

```
Let’s go through a dry run of the code with an example input step-by-step.

Suppose the input array is:
```cpp
nums = [4, 3, 2, 7, 8, 2, 3, 1]
```

### Initial Setup
1. We initialize an empty `result` vector to store the duplicates.
2. We will iterate through each element in `nums`, and for each element, we calculate an index based on its absolute value (adjusted by subtracting 1 since array indices are 0-based).

### Step-by-Step Dry Run
Let’s go through each iteration and understand what happens.

#### Iteration 1:
- **`i = 0`**: `nums[0] = 4`
  - `index = abs(nums[0]) - 1 = 4 - 1 = 3`
  - `nums[3] = 7` (value at index 3 is positive)
  - Mark `nums[3]` as visited by negating it: `nums[3] = -7`
  - **Updated `nums`**: `[4, 3, 2, -7, 8, 2, 3, 1]`

#### Iteration 2:
- **`i = 1`**: `nums[1] = 3`
  - `index = abs(nums[1]) - 1 = 3 - 1 = 2`
  - `nums[2] = 2` (value at index 2 is positive)
  - Mark `nums[2]` as visited by negating it: `nums[2] = -2`
  - **Updated `nums`**: `[4, 3, -2, -7, 8, 2, 3, 1]`

#### Iteration 3:
- **`i = 2`**: `nums[2] = -2` (already negative due to previous step)
  - `index = abs(nums[2]) - 1 = 2 - 1 = 1`
  - `nums[1] = 3` (value at index 1 is positive)
  - Mark `nums[1]` as visited by negating it: `nums[1] = -3`
  - **Updated `nums`**: `[4, -3, -2, -7, 8, 2, 3, 1]`

#### Iteration 4:
- **`i = 3`**: `nums[3] = -7` (already negative due to previous step)
  - `index = abs(nums[3]) - 1 = 7 - 1 = 6`
  - `nums[6] = 3` (value at index 6 is positive)
  - Mark `nums[6]` as visited by negating it: `nums[6] = -3`
  - **Updated `nums`**: `[4, -3, -2, -7, 8, 2, -3, 1]`

#### Iteration 5:
- **`i = 4`**: `nums[4] = 8`
  - `index = abs(nums[4]) - 1 = 8 - 1 = 7`
  - `nums[7] = 1` (value at index 7 is positive)
  - Mark `nums[7]` as visited by negating it: `nums[7] = -1`
  - **Updated `nums`**: `[4, -3, -2, -7, 8, 2, -3, -1]`

#### Iteration 6:
- **`i = 5`**: `nums[5] = 2`
  - `index = abs(nums[5]) - 1 = 2 - 1 = 1`
  - `nums[1] = -3` (value at index 1 is negative, indicating a duplicate)
  - Add `abs(nums[5]) = 2` to `result`
  - **Updated `result`**: `[2]`

#### Iteration 7:
- **`i = 6`**: `nums[6] = -3` (already negative)
  - `index = abs(nums[6]) - 1 = 3 - 1 = 2`
  - `nums[2] = -2` (value at index 2 is negative, indicating a duplicate)
  - Add `abs(nums[6]) = 3` to `result`
  - **Updated `result`**: `[2, 3]`

#### Iteration 8:
- **`i = 7`**: `nums[7] = -1` (already negative)
  - `index = abs(nums[7]) - 1 = 1 - 1 = 0`
  - `nums[0] = 4` (value at index 0 is positive)
  - Mark `nums[0]` as visited by negating it: `nums[0] = -4`
  - **Updated `nums`**: `[-4, -3, -2, -7, 8, 2, -3, -1]`

### Final Result
After all iterations, `result` contains the duplicates found in the array:
```cpp
result = [2, 3]
```

### Summary
This algorithm effectively identifies duplicates by using the input array itself to mark visited indices. By making elements at certain indices negative, it tracks if an index has been visited more than once, which signals a duplicate.

---

 There are two issues in the code:

1. **Out-of-Bounds Error in the Loop**:  
   The loop currently iterates with `i < nums.size() + 2`. This will cause an out-of-bounds access error because you’re trying to access elements beyond the end of the `nums` array. The loop should only iterate up to `nums.size()` to avoid going beyond the bounds of the array.

2. **Index Calculation**:  
   In this line:
   ```cpp
   int index = abs(nums[i]);
   ```
   `index` is intended to be a 0-based index. However, `nums[i]` can be any integer in the range `[1, n]`, so `index` should be calculated as `abs(nums[i]) - 1`. Without subtracting 1, you’re accessing an out-of-bounds index if `index == nums.size()`.

### Corrected Code:
Here’s the corrected code with these changes:

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Get the correct index by subtracting 1
            int index = abs(nums[i]) - 1; 
            
            // If the value at the corresponding index is negative, it's a duplicate
            if (nums[index] < 0) {
                result.push_back(abs(nums[i]));
            } else {
                // Mark the value at the index as visited by negating it
                nums[index] = -nums[index];
            }
        }
        
        return result;
    }
};
```

### Explanation of Changes
1. **Loop Bound**: Changed `nums.size() + 2` to `nums.size()` to prevent accessing elements outside of the array.
2. **Index Calculation**: Changed `int index = abs(nums[i]);` to `int index = abs(nums[i]) - 1;` to ensure we’re using a 0-based index correctly.
   

This corrected version should now work as expected without errors.

 ---
 
** GFGs**


 

You are given an integer n and an integer array arr of size n+2. All elements of the array are in the range from 1 to n. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
Note: Return the numbers in their order of appearing twice. So, if x and y are repeating numbers, and x's second appearance comes before the second appearance of y, then the order should be (x, y).

Examples:

Input: n = 4, arr[] = [1, 2, 1, 3, 4, 3]
Output: 1 3
Explanation: In the given array, 1 and 3 are repeated two times, and as 1's second appearance occurs before 2's second appearance, so the output should be 1 3.
Input: n = 2, arr[] = [1, 2, 2, 1]
Output: 2 1
Explanation: In the given array, 1 and 2 are repeated two times and second occurence of 2 comes before 1. So the output is 2 1.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1). 

```cpp

class Solution {
  public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int n, int arr[]) {
        // Your code here
        vector<int>ans;
        for(int i=0;i<n+2;i++)
        {
            int index = abs(arr[i]);
        if(arr[index]<0) ans.push_back(index);
        else arr[index] = -arr[index];
        if(ans.size()==2) break;
        }return ans;
    }
};


```

n = 4
arr = {1, 2, 1, 3, 4, 3}
We are looking for two repeating numbers in the array, which are in the range 1 to n.

Step-by-Step Dry Run
Initial Array State: {1, 2, 1, 3, 4, 3}

First Iteration (i = 0):

Current element: arr[0] = 1
index = abs(arr[0]) = 1
arr[1] is positive, so negate arr[1] to mark 1 as seen.
Array after change: {1, -2, 1, 3, 4, 3}
Second Iteration (i = 1):

Current element: arr[1] = -2
index = abs(arr[1]) = 2
arr[2] is positive, so negate arr[2] to mark 2 as seen.
Array after change: {1, -2, -1, 3, 4, 3}
Third Iteration (i = 2):

Current element: arr[2] = -1
index = abs(arr[2]) = 1
arr[1] is negative, indicating 1 is a duplicate.
Add 1 to ans.
Array remains: {1, -2, -1, 3, 4, 3}
ans = {1}
Fourth Iteration (i = 3):

Current element: arr[3] = 3
index = abs(arr[3]) = 3
arr[3] is positive, so negate arr[3] to mark 3 as seen.
Array after change: {1, -2, -1, -3, 4, 3}
Fifth Iteration (i = 4):

Current element: arr[4] = 4
index = abs(arr[4]) = 4
arr[4] is positive, so negate arr[4] to mark 4 as seen.
Array after change: {1, -2, -1, -3, -4, 3}
Sixth Iteration (i = 5):

Current element: arr[5] = 3
index = abs(arr[5]) = 3
arr[3] is negative, indicating 3 is a duplicate.
Add 3 to ans.
Array remains: {1, -2, -1, -3, -4, 3}
ans = {1, 3}
Exit the loop since ans now contains two elements.
Final Output
ans = {1, 3}
Explanation of the Result
The duplicates 1 and 3 were detected in the order they appear for the second time, resulting in the output 1 3.

---


Given a list of array elements with all unique elements, except one element which comes two times, find that duplicate number. It was similar to this Repeating element except the array elements were not from 1 to n. I gave him the hashing solution but he wanted it in O(1) space complexity and O(n) time complexity.

If the array elements are unique except for one duplicate, and the elements are not constrained to be from 1 to n, you can solve this problem in \( O(n) \) time and \( O(1) \) space by using the **XOR method**.

### Explanation of the XOR Method:
1. XOR has a unique property where:
   - \( a \oplus a = 0 \) (any number XORed with itself is 0)
   - \( a \oplus 0 = a \) (any number XORed with 0 is the number itself)
2. When you XOR all numbers in the array, the duplicate number will remain, as every other unique number cancels out itself due to the XOR property.

### Solution:
To implement this, simply XOR all elements in the array. The result will be the duplicate element.

Here's how it works in code:

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int xorResult = 0;

        // XOR all elements in the array
        for (int num : nums) {
            xorResult ^= num;
        }

        return xorResult;
    }
};
```

### Example:
Consider the input array:
```cpp
nums = [5, 2, 3, 4, 5]
```


- XOR all elements:
  - \( 5 \oplus 2 \oplus 3 \oplus 4 \oplus 5 \)
  - Result: `5` (since the unique elements cancel out, leaving only the duplicate)

### Explanation of Complexity:

![10 11 2024_13 32 43_REC](https://github.com/user-attachments/assets/ee858f07-7cf7-47f4-8649-72c31faa994c)


- **Time Complexity**: \( O(n) \), as we are iterating through the array once.
- **Space Complexity**: \( O(1) \), as we use only a single variable `xorResult` to store the XOR result.

This approach meets the requirements of \( O(n) \) time and \( O(1) \) space complexity.


---

The second question he asked was this – In an array, all elements are repeated twice except one element which comes thrice, find that element. I gave him the simple XOR solution, where we XOR all the elements and the final result is the answer.


The XOR solution won't work here because XOR is effective only when elements appear exactly twice (or an odd number of times). In this case, where all elements appear **twice** except for **one element that appears three times**, we need a different approach to find the element appearing three times in \(O(n)\) time and \(O(1)\) space.

### Solution: Bit Manipulation (Sum of Bits)

Here's an efficient approach using bit manipulation based on summing the bits of each position across all numbers:

1. **Count the occurrence of each bit across all numbers**: 
   For each bit position (from 0 to 31 for a 32-bit integer), count the number of `1`s across all numbers in the array.

2. **Modulo 3 for Each Bit**:
   If a bit appears three times in total across all numbers, it means this bit contributes fully to elements that appear twice. The bit of the unique element that appears only once will have a remainder of `1` in that bit position when counted modulo 3. 

3. **Reconstruct the Unique Number**:
   By taking the modulo of the bit count with 3 for each bit position, we can reconstruct the unique element.

### Code:

Here's the code to implement this solution:

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int findUniqueElement(vector<int>& nums) {
        int result = 0;

        // Iterate through each bit position
        for (int i = 0; i < 32; ++i) {
            int bitCount = 0;

            // Count how many numbers have a 1 at the i-th bit position
            for (int num : nums) {
                if (num & (1 << i)) {
                    bitCount++;
                }
            }

            // If bitCount % 3 is 1, this bit belongs to the unique element
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }

        return result;
    }
};
```

### Explanation:

- **Counting Bits**: For each bit position `i` (from 0 to 31), we count the number of numbers that have a `1` at that bit position.
- **Modulo Operation**: If `bitCount % 3 != 0`, it means this bit position contributes to the unique number (the one that appears three times).
- **Setting the Result**: Set the corresponding bit in the `result` using bitwise OR.

### Complexity Analysis:

- **Time Complexity**: \( O(n) \), since we loop through each element and then each bit position (a constant 32-bit loop).
- **Space Complexity**: \( O(1) \), as we only use a fixed amount of extra space for counting bits.

This approach effectively finds the element that appears three times without needing extra space beyond the counters and operates in linear time.
