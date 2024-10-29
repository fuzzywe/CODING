https://www.naukri.com/code360/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=DISCUSS


Test case 4

Input
1

2

15
-7 -8 -16 -4 -8 -5 -7 -11 -10 -12 -4 -6 -4 -16 -10 
Output
1

2

-4

The output you're seeing, `-4`, for the given test case suggests that the code isn't properly handling cases where all numbers are negative, and it defaults to returning a maximum sum of a subarray that may not be optimal. Kadane’s Algorithm should return the largest (least negative) number in the array in such cases, as this would represent the maximum possible sum of any subarray, even if it’s just a single negative number.

Let's ensure that our implementation handles this case correctly. Instead of initializing `current_sum` and `max_sum` both to `arr[0]`, let's handle cases where each element is negative by adjusting our initial `current_sum` to zero. We can then update `max_sum` based on whether `current_sum` becomes positive at any point.

Here’s the revised code:

```cpp
#include <vector>
#include <algorithm>
using namespace std;

long long maxSubarraySum(vector<int> arr, int n) {
    // Initialize max_sum as a small number to handle cases with all negatives
    long long max_sum = arr[0];
    long long current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        // Update current_sum
        current_sum += arr[i];
        max_sum = max(max_sum, current_sum);

        // Reset current_sum if it becomes negative
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    return max_sum;
}
```

### Explanation of Changes
1. **Initialize `max_sum` with `arr[0]`**: This handles cases with all negative numbers by ensuring `max_sum` will at least capture the maximum negative value.
2. **Reset `current_sum` to 0 when it goes negative**: This allows the algorithm to restart from a new subarray, avoiding accumulation of large negative sums.
  
Now, when all elements are negative, `max_sum` will store the maximum single element from `arr`, which is the desired outcome. This should now correctly output `-4` as the maximum sum for this test case, matching the largest element in the array.

https://leetcode.com/problems/maximum-subarray/description/

LARGEST SUM CONSECUTIVE SUBARRAY 
Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 979K+Points: 4
Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

Examples:

Input: arr[] = [1, 2, 3, -2, 5]
Output: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
Input: arr[] = [-1, -2, -3, -4]
Output: -1
Explanation: Max subarray sum is -1 of element (-1)
Input: arr[] = [5, 4, 7]
Output: 16
Explanation: Max subarray sum is 16 of element (5, 4, 7)
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

  Example 1:
Input:
 arr = [-2,1,-3,4,-1,2,1,-5,4] 

Output:
 6 

Explanation:
 [4,-1,2,1] has the largest sum = 6. 

Examples 2:
Input:
 arr = [1] 

Output:
 1 

Explanation:
 Array has only one element and which is giving positive sum of 1.


  

```cpp
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
```

Complexity Analysis
Time Complexity: O(N2), where N = size of the array.
Reason: We are using two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space.


optimized code in code platform:

```cpp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int max_sum = nums[0]; // Initialize max_sum as the first element
        
        for (int i = 0; i < nums.size(); i++) {
            // At each step, either include the current element in the subarray
            // or start a new subarray with just the current element
            current_sum = max(nums[i], current_sum + nums[i]);
            
            // Update the maximum sum encountered so far
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};
```


The issue with the current code is that it uses a brute-force approach with a time complexity of **O(n²)** due to the nested loops, which checks every possible subarray. This is inefficient and leads to a **Time Limit Exceeded (TLE)** error on large test cases, such as the one provided.

### Optimal Solution: Kadane's Algorithm

A more efficient approach to solve this problem is **Kadane’s Algorithm**, which runs in **O(n)** time. The basic idea of Kadane's algorithm is to iterate through the array and, at each step, decide whether to:
1. Continue the current subarray (by adding the current element).
2. Start a new subarray (by considering only the current element).

This ensures that you keep track of the maximum subarray sum at each point, resulting in an optimal solution.

Let’s implement **Kadane's Algorithm**:

### Code: Kadane's Algorithm

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = 0;
        int max_sum = nums[0]; // Initialize max_sum as the first element
        
        for (int i = 0; i < nums.size(); i++) {
            // At each step, either include the current element in the subarray
            // or start a new subarray with just the current element
            current_sum = max(nums[i], current_sum + nums[i]);
            
            // Update the maximum sum encountered so far
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};
```

### Explanation:

1. **Initialization**:
   - `current_sum`: Tracks the sum of the current subarray.
   - `max_sum`: Tracks the maximum sum encountered so far (starts as the first element).

2. **Iterating through the array**:
   - At each step, for the current element `nums[i]`, we decide whether to:
     - Continue the subarray by adding `nums[i]` to `current_sum` (i.e., `current_sum + nums[i]`).
     - Start a new subarray with just the current element `nums[i]` (i.e., `nums[i]`).
   - This decision is made using `current_sum = max(nums[i], current_sum + nums[i])`.

3. **Updating max_sum**:
   - After updating `current_sum`, we update `max_sum` to store the maximum sum encountered so far.

4. **Return the result**: At the end of the loop, `max_sum` holds the maximum subarray sum.

### Dry Run Example

For the array: `nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`

- Initial `max_sum = -2`, `current_sum = 0`.
  
Step-by-step:

| i  | nums[i] | current_sum                  | max_sum |
|----|---------|------------------------------|---------|
| 0  | -2      | max(-2, 0 + (-2)) = -2       | -2      |
| 1  | 1       | max(1, -2 + 1) = 1           | 1       |
| 2  | -3      | max(-3, 1 + (-3)) = -2       | 1       |
| 3  | 4       | max(4, -2 + 4) = 4           | 4       |
| 4  | -1      | max(-1, 4 + (-1)) = 3        | 4       |
| 5  | 2       | max(2, 3 + 2) = 5            | 5       |
| 6  | 1       | max(1, 5 + 1) = 6            | 6       |
| 7  | -5      | max(-5, 6 + (-5)) = 1        | 6       |
| 8  | 4       | max(4, 1 + 4) = 5            | 6       |

- **Result**: The maximum subarray sum is `6`, achieved by the subarray `[4, -1, 2, 1]`.

### Time Complexity:
- **Time Complexity**: O(n), where `n` is the number of elements in the input array. We only traverse the array once.
- **Space Complexity**: O(1), since we only use a constant amount of extra space.

This solution will handle large inputs efficiently without causing TLE.


Kadane's Algorithm is a well-known method for finding the maximum sum of a contiguous subarray in a given array of integers. Let’s break down the mathematics and logic behind Kadane’s Algorithm to understand why it works and how it achieves optimal results in linear time.

### Problem Statement
Given an array of integers (which may include both positive and negative numbers), find the contiguous subarray with the maximum sum.

### Kadane’s Algorithm: Key Idea
The core idea behind Kadane’s Algorithm is to use **dynamic programming** to build up a solution by making local decisions at each element in the array. It does this by maintaining a running maximum subarray sum that ends at each position and updates the global maximum sum as it goes through the array.

### Mathematical Breakdown

1. **Define Variables**:
   - `current_sum`: This keeps track of the maximum sum of the subarray ending at the current position.
   - `max_sum`: This keeps track of the maximum sum encountered so far across the array.

2. **Dynamic Programming Transition**:
   - For each element at index `i`, update `current_sum` as:
     \[
     \text{current\_sum} = \max(\text{array}[i], \text{current\_sum} + \text{array}[i])
     \]
   - This transition uses the intuition that at each step, you decide whether to:
     - Include the current element in the existing subarray (adding `array[i]` to `current_sum`), or
     - Start a new subarray beginning at `array[i]` (setting `current_sum` to `array[i]` itself).
   - By taking the maximum of these two values, you ensure `current_sum` always holds the highest possible sum for any subarray ending at index `i`.

3. **Update Global Maximum**:
   - After updating `current_sum` for each element, compare it to `max_sum`:
     \[
     \text{max\_sum} = \max(\text{max\_sum}, \text{current\_sum})
     \]
   - This step ensures that `max_sum` will always store the highest subarray sum encountered so far.

### Why Kadane's Algorithm Works

The algorithm leverages the **optimal substructure** property, which means the solution to the problem can be built using solutions to its subproblems. In Kadane's algorithm, the maximum sum ending at index `i` depends only on the maximum sum ending at index `i - 1` and the element `array[i]`. Thus, it iterates through the array only once (O(n) time complexity), making it highly efficient.

### Example Walkthrough

Consider the array:
\[
\text{array} = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
\]

Using Kadane's Algorithm, let’s calculate `current_sum` and `max_sum` at each step:

1. **Initialize**:
   - `current_sum = array[0] = -2`
   - `max_sum = -2`

2. **Iterate through the array**:

   - **Index 1**: `array[1] = 1`
     - `current_sum = max(1, -2 + 1) = 1`
     - `max_sum = max(-2, 1) = 1`
   - **Index 2**: `array[2] = -3`
     - `current_sum = max(-3, 1 + (-3)) = -2`
     - `max_sum = max(1, -2) = 1`
   - **Index 3**: `array[3] = 4`
     - `current_sum = max(4, -2 + 4) = 4`
     - `max_sum = max(1, 4) = 4`
   - **Index 4**: `array[4] = -1`
     - `current_sum = max(-1, 4 + (-1)) = 3`
     - `max_sum = max(4, 3) = 4`
   - **Index 5**: `array[5] = 2`
     - `current_sum = max(2, 3 + 2) = 5`
     - `max_sum = max(4, 5) = 5`
   - **Index 6**: `array[6] = 1`
     - `current_sum = max(1, 5 + 1) = 6`
     - `max_sum = max(5, 6) = 6`
   - **Index 7**: `array[7] = -5`
     - `current_sum = max(-5, 6 + (-5)) = 1`
     - `max_sum = max(6, 1) = 6`
   - **Index 8**: `array[8] = 4`
     - `current_sum = max(4, 1 + 4) = 5`
     - `max_sum = max(6, 5) = 6`

3. **Final Result**:
   - After going through all elements, `max_sum` is `6`.
   - The maximum sum of any contiguous subarray in `array` is `6`.

### Why Kadane’s Algorithm is Optimal

Kadane’s Algorithm is optimal because it uses only one pass through the array, updating `current_sum` and `max_sum` as it goes. Each element is evaluated just once, resulting in \( O(n) \) time complexity, which is the best possible for this problem. Additionally, it uses only \( O(1) \) extra space for the variables, making it space-efficient.

### Conclusion

Kadane’s Algorithm leverages simple mathematical operations (comparisons and additions) to determine whether to continue a subarray or start fresh at each step, ensuring it always has the maximum subarray sum up to the current index. This approach ensures an efficient and optimal solution to the maximum subarray sum problem.
