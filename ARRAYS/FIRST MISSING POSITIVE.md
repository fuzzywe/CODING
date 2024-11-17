41. First Missing Positive
Solved
Hard
Topics
Companies
Hint
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

https://leetcode.com/problems/first-missing-positive/description/

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Complexity
Time complexity: O(nlogn)
Space complexity: O(n)

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Filter the numbers greater than 0
        vector<int> filteredNums;
        for (int n : nums) {
            if (n > 0) {
                filteredNums.push_back(n);
            }
        }
        
        // Sort the filtered array
        sort(filteredNums.begin(), filteredNums.end());
        
        int target = 1;
        // Iterate through the sorted array to find the first missing positive
        for (int n : filteredNums) {
            if (n == target) {
                target++;
            } else if (n > target) {
                return target;
            }
        }
        
        // If all numbers are in sequence, return the next number
        return target;
    }
};

```
optimized


```cpp


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int target = 1;
        for (int n : nums) {
            if (n > 0 && n == target) {
                target++;
            } else if (n > target) {
                return target;
            }
        }

        return target;
    }
};

```

o(n) 0(1)
