930. Binary Subarrays With Sum
Medium
Topics
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 https://leetcode.com/problems/binary-subarrays-with-sum/description/

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15

 ---

 Initialization:

count = {0: 1}: This initializes a dictionary called count with one key-value pair: 0 as the key and 1 as the value. This represents that there is one subarray whose sum is 0.
curr_sum = 0: This initializes a variable curr_sum to keep track of the cumulative sum of elements encountered so far.
total_subarrays = 0: This initializes a variable total_subarrays to keep track of the total count of subarrays whose sum is equal to the goal.
Iterating through nums:

The code iterates through each element num in the list nums.
Calculating Cumulative Sum:

curr_sum += num: This adds the current element num to the curr_sum, updating the cumulative sum.
Checking for Subarrays with the Desired Sum:

if curr_sum - goal in count: This checks if the difference between the current cumulative sum curr_sum and the goal is present in the count dictionary.
If it is, it means there exists a subarray whose sum is equal to the goal.
Updating total_subarrays:

total_subarrays += count[curr_sum - goal]: If there is such a subarray, the code increments total_subarrays by the count of subarrays found in count[curr_sum - goal].
Updating Count Dictionary:

count[curr_sum] = count.get(curr_sum, 0) + 1: This updates the count dictionary by incrementing the count of the current cumulative sum curr_sum. If curr_sum is already present in count, it increments its count by 1. Otherwise, it initializes its count to 1.
Returning the Result:

return total_subarrays: Finally, the code returns the total count of subarrays whose sum equals the goal.

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};
```
