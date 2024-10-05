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
