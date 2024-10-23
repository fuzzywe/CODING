643. Maximum Average Subarray I

https://leetcode.com/problems/maximum-average-subarray-i/description/

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Our given input
Given input nums and k value

![image](https://github.com/user-attachments/assets/145bc847-91d3-44da-9514-3646eceea7c8)

Initialization
This image expplains sliding window concept and our initial values


![image](https://github.com/user-attachments/assets/04a77b65-7c27-454e-82ad-8cd6ea6d4d52)

Operations


![image](https://github.com/user-attachments/assets/7b70e8c4-a3ed-4254-b2a0-475d6f7c35eb)

 ---
 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;
        
        // Initialize currSum and maxSum to the sum of the initial k elements
        for (int i = 0; i < k; i++)
            currSum += nums[i];
        maxSum = currSum;
        
        // Start the loop from the kth element 
        // Iterate until you reach the end
        for (int i = k; i < nums.size(); i++) {
            // Subtract the left element of the window
            // Add the right element of the window
            currSum += nums[i] - nums[i - k];
            
            // Update the max
            maxSum = max(maxSum, currSum);
        }
        
        // Since the problem requires average, we return the average
        return maxSum / k;
    }
};

```
Complexity
Time: O(n)
Space: O(1)
