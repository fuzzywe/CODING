
https://leetcode.com/problems/maximum-subarray/
53. Maximum Subarray

Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.


❌ Solution - I (Brute-Force) [TLE]

We can start with brute-force by trying out every possible sub-array in nums and choosing the one with maximum sum.

```cpp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {int cursum =0;
            for(int j=i;j<nums.size();j++)
            {
                cursum +=nums[j];
                maxi = max(maxi,cursum);

            }
        }return maxi;
    }
};
```
✔️ Solution - V (Kadane's Algorithm)

We can observe that in the previous approach, dp[i] only depended on dp[i-1]. So do we really need to maintain the whole dp array of N elements? One might see the last line of previous solution and say that we needed all elements of dp at the end to find the maximum sum subarray. But we can simply optimize that by storing the max at each iteration instead of separately calculating it at the end.

Thus, we only need to maintain curMax which is the maximum subarray sum ending at i and maxTillNow which is the maximum sum we have seen till now. And this way of solving this problem is what we popularly know as Kadane's Algorithm

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxTillNow = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};
```
