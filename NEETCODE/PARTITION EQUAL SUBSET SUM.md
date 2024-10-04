
https://leetcode.com/problems/partition-equal-subset-sum/solutions/462699/whiteboard-editorial-all-approaches-explained/?envType=problem-list-v2&envId=plakya4j&difficulty=MEDIUM&status=TO_DO


Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

❌ Solution - I (Brute-Force)

Let's try solving it using brute-force approach. We need to partition the array into two subsets. This means that for each element of the array, we can either place it in 1st subset, or place it in 2nd subset.

Since we are only concerned with the sums of subset being equal, we will maintain 1st subset's sum: sum1 & 2nd subset's sum: sum2. For each element, we try both possible options of either placing it in 1st subset and increasing sum1 or placing it in 2nd subset & increasing sum2. Finally, once we reach the end of array, we can check if the current placements gave equal sum. If none of the possible placements give equal sum, we will return false.

C++
```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums, int i = 0, int sum1 = 0, int sum2 = 0) {
        if(i >= size(nums)) return sum1 == sum2;                    // check if both subset have equal sum
        return canPartition(nums, i+1, sum1 + nums[i], sum2)        // try including into subset-1
		    || canPartition(nums, i+1, sum1, sum2 + nums[i]);       // try including into subset-2
    }
};```
 
