209. Minimum Size Subarray Sum

https://leetcode.com/problems/minimum-size-subarray-sum/description/

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


---
Approach 2: Using two pointers

The sum of elements in the window and the left pointer are initialized.
A loop iterates through the array, expanding the window by adding elements to the sum.
If the sum>=target, it means a valid subarray with the given sum is found. To find the minimum length, the left pointer is incremented until sum >= target.
The minimum length found is updated in the ans variable.


Complexity
Time complexity:O(n), where n is the length of the input array. Both the start and end pointers move from left to right, and each element is processed at most twice (once when expanding the window, and once when shrinking it).
Space complexity:O(1) because we only use a few variables (start, end, currentSum, and minLength), and no additional data structures are needed aside from the input array.


```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(), sum=0, left = 0, ans=INT_MAX;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
                ans=min(ans, right-left+1);
                sum-=nums[left++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```


Approach 1: Using Binary Search

First, the sum of all the elements in nums is calculated using the accumulate function.
If the sum of nums is greater than the target, it means a subarray with the given sum is not possible, so the function returns 0.
If the sum is equal to the target, it means the entire nums array is the subarray with the given sum, so the function returns the size of nums.
A lambda function is created to check if a subarray with a given length can have a sum greater than or equal to the target.
The minimum length of the subarray is found using the checker lambda function and binary search.

```cpp

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {        
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if(target > sum) return 0;
        if(target == sum) return n;
        
        auto checker = [nums, n, target](int len){
            int sum = 0;
        
            for(int i=0;i<len;i++){
                sum += nums[i];
            }

            for(int i=len;i<n;i++){
                if(sum>=target){
                    return true;
                }
                sum+=nums[i];
                sum-=nums[i-len];
            }

            return sum>=target;
        };
        
        int low = 1, high = n-1, mid;
        while(low<=high){
            mid = low + (high - low) / 2;
            if(checker(mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
};

```
